//include header files
#include "const.h"
#include "loadmap.h"
#include "setPosition.h"
#include "checkGameOver.h"
#include "movement.h"
#include "closeGame.h"
#include "animation.h"
#include "menu.h"
#include "music.h"
#define ifor(i, m) for (int i = 0; i < (m); i++)

using namespace std;
using namespace sf;
//map_width* width, map_height*height
RenderWindow window(VideoMode(1080, 720), "Fire Rescue", Style::Default);
Event event;
View view;
Clock gameTime;

bool gameOver = false;
bool carring = false;
bool startgame = false;
bool tutorial = false;

int main() {
	////clock start
	//Clock clock;
	//Clock gameTime;
	//count frame passed
	int countFramePassed = 0;
	//setup
	//load map container and setup menu's sprite and music
	vector < vector <char> > map(map_height, vector <char>(map_width));
	loadmap(map);
	loadtexture();
	loadmenu();
	loadMusic();

	view.zoom(0.75f);
	//character&host
	position dummy;
	position host_position;

	//set the object position
	setPosition(map, dummy, host_position);
	setCharacterPos(window, dummy);

	window.setFramerateLimit(60);
	while (window.isOpen()) {
		//menu_music(startgame);
		if (!tutorial)
			menu(window, event, startgame, tutorial);
		else tutorial_menu(window, event, startgame);
		while (startgame == true and gameOver == false) {
			background_music(gameOver);
			window.clear(Color::Black);
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) window.close();
				if (event.type == Event::Resized) {
					FloatRect visiableArea(0, 0, event.size.width, event.size.height);
					window.setView(View(visiableArea));
				}
				if (event.type == Event::EventType::KeyPressed) {
					if (!dummy.moving)
						keyInput(map, event, dummy);
				}
			}
			//lock view on player
			setView(window, view, dummy);

			//render (floor -> wall -> character -> box)
			renderFloor(window, map);
			renderWall(window, map, countFramePassed);

			//render object
			renderBox(window, map);


			
			//render player animation
			characterMoving(window, dummy);
			renderAnimation(window, dummy, countFramePassed);

			//render bloodbar
			renderBloodbar(window);

			//check if the document's been saved?
			renderHost(window, host_position, countFramePassed, carring);
			check_carring(map, dummy, host_position, carring);

			//display
			window.display();
			countFramePassed++;
			//check game_is_over?
			gameOver = check_game(map, dummy, carring, gameTime);
		}
		resetView(window, view);
		startgame = false;
	}
	close(window);
	return 0;
}