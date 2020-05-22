#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#define ifor(i, m) for (int i = 0; i < (m); i++)
//include header files

using namespace std;
using namespace sf;
//const
const int width = 48;
const int height = 46;
const int map_width = 25;
const int map_height = 16;
const int extra_size = 16;
static RenderWindow window(VideoMode(width * 15, height * 10), "Fire Rescue", Style::Default);
Event event;
Texture wall, floor_texture, box_texture, dummy, host;

bool gameOver = false;
bool rescue = false;
bool carring = false;

class position {
public:
	int x, y;
};

void loadmap(vector < vector <char> >& map) {
	ifstream game_map("map/map.txt");
	if (game_map.is_open()) {
		ifor(i, map_height) {
			ifor(j, map_width) {
				game_map >> map[i][j];
			}
		}
	}
	game_map.close();
}

void movement(vector < vector <char> >& map, position& dummy_position) {
	int x = dummy_position.x;
	int y = dummy_position.y;
	switch (event.key.code)
	{
	case Keyboard::Up:
		cout << "up-key pressed" << endl;
		if ((map[y - 1][x] == '0' or map[y - 1][x] == '5') and y - 1 >= 0) {
			dummy_position.y--;
		}
		if (map[y - 1][x] == '2' and map[y - 2][x] == '0' and y - 2 >= 0) { //out of the map
			map[y - 1][x] = '0';
			map[y - 2][x] = '2';
			dummy_position.y--;
		}
		break;
	case Keyboard::Down:
		cout << "down-key pressed" << endl;
		if ((map[y + 1][x] == '0' or map[y + 1][x] == '5') and y + 1 <= map_height) {
			dummy_position.y++;
		}
		if (map[y + 1][x] == '2' and map[y + 2][x] == '0' and y + 2 <= map_height) {
			map[y + 1][x] = '0';
			map[y + 2][x] = '2';
			dummy_position.y++;
		}
		break;
	case Keyboard::Left:
		cout << "left-key pressed" << endl;
		if ((map[y][x - 1] == '0' or map[y][x - 1] == '5') and x - 1 >= 0) {
			dummy_position.x--;
		}
		if (map[y][x - 1] == '2' and map[y][x - 2] == '0' and x - 2 >= 0) {
			map[y][x - 1] = '0';
			map[y][x - 2] = '2';
			dummy_position.x--;
		}
		break;
	case Keyboard::Right:
		cout << "right-key pressed" << endl;
		if ((map[y][x + 1] == '0' or map[y][x + 1] == '5') and x + 1 <= map_width) {
			dummy_position.x++;
		}
		if (map[y][x + 1] == '2' and map[y][x + 2] == '0' and x + 2 <= map_width) {
			map[y][x + 1] = '0';
			map[y][x + 2] = '2';
			dummy_position.x++;
		}
		break;
	default:
		break;
	}
}

void setPosition(vector < vector <char> >& map, position& dummy_position, position& host_position) { //vector <position>& host_position
	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '7') {
				//generate dummy's position
				dummy_position.x = j;
				dummy_position.y = i;
				map[i][j] = '0';
			}
			else if (map[i][j] == '8') {
				//generate hostages's position
				//position pos;
				//pos.x = j;
				//pos.y = i;
				//host_position.push_back(pos);
				host_position.x = j;
				host_position.y = i;
				map[i][j] = '0';
			}
		}
	}
}

void renderBox(vector < vector <char> >& map, vector < vector <Sprite> >& background_sprite) {
	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '2') {
				//render box
				background_sprite[i][j].setTexture(box_texture);
				background_sprite[i][j].setPosition(j * width, i * height);
				window.draw(background_sprite[i][j]);
			}
		}
	}
}

void renderFloor(vector < vector <char> >& map, vector < vector <Sprite> >& background_sprite) {
	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '0' or map[i][j] == '5') {
				background_sprite[i][j].setTexture(floor_texture);
				background_sprite[i][j].setPosition(j * width, i * height);
				window.draw(background_sprite[i][j]);
			}
		}
	}
}

void renderCharacter(vector < vector <char> >& map, Sprite dummy_sprite, position dummy_position) {
	dummy_sprite.setPosition((float)dummy_position.x * width, (float)dummy_position.y * height);
	window.draw(dummy_sprite);
}

void renderHost(vector < vector <char> >& map, Sprite& host_sprite, position& host_position) {
	//ifor(i, host_position.size()) {
		host_sprite.setTexture(host);
		host_sprite.setPosition((float)host_position.x * width, (float)host_position.y * height);
		window.draw(host_sprite);
	//}
}

void renderWall(vector < vector <char> >& map, vector < vector <Sprite> >& background_sprite) {
	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '1') {
				background_sprite[i][j].setTexture(wall);
				background_sprite[i][j].setPosition(j * width, i * height - extra_size);
				window.draw(background_sprite[i][j]);
			}
		}
	}
}

position checkNearestHost(vector <position>& host_position, position dummy_position) {
	ifor(i, host_position.size()) {
		if (host_position[i].x == dummy_position.x and host_position[i].y == dummy_position.y)
		{
			return host_position[i];
		}
	}
}

bool check_game(vector < vector <char> >& map, position dummy_position, position host_position, int& count) {
	//position position_host = checkNearestHost(host_position, dummy_position);
	if (dummy_position.x == host_position.x and dummy_position.y == host_position.y and rescue == false) {
		count--;
		rescue = true;
		cout << "rescue success" << endl;
		return false;
		/*cout << "rescued!" << endl;
		if (count == 0) {
			rescue = true;
		}*/
	}
	else if (map[dummy_position.y][dummy_position.x] == '5' and rescue == true) {
		gameOver = true;
		return true;
	}
	return false;
}

void cout_gameOver() {
	Font font;
	if (!font.loadFromFile("arcade.ttf")) {
		return;
	}
	Text you_won("we won mr stark", font, 82);
	//you_won.setColor(Color::Blue);
	window.draw(you_won);
}
void close() {
	window.clear();
	window.close();
}

int main() {
	int count = 0;
	//map container 
	vector < vector <char> > map(map_height, vector <char>(map_width));
	loadmap(map);

	//character&host
	dummy.loadFromFile("images/character2.png");
	host.loadFromFile("images/host2.png");
	Sprite dummy_sprite(dummy);
	position dummy_position;
	//vector <Sprite> host_sprite;
	//vector <position> host_position;
	Sprite host_sprite;
	position host_position;

	//background & wall
	wall.loadFromFile("images/brick1.png");
	floor_texture.loadFromFile("images/floor2.png");
	box_texture.loadFromFile("images/box2.png"); //box
	vector < vector <Sprite> > background_sprite(height - 1, vector <Sprite>(width - 1));

	//set the object position
	setPosition(map, dummy_position, host_position);
	//count = host_position.size();

	while (window.isOpen() and gameOver == false) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::EventType::KeyPressed) {
				movement(map, dummy_position);
			}
		}
		window.clear(Color::White);
		//render (floor -> character -> box -> wall)
		renderFloor(map, background_sprite);
		renderCharacter(map, dummy_sprite, dummy_position);
		renderBox(map, background_sprite);
		if (rescue != true) {
			renderHost(map, host_sprite, host_position);
		}
		renderWall(map, background_sprite);
		if (check_game(map, dummy_position, host_position, count)) {
			cout_gameOver;
			cout << "end game" << endl;
		}
		window.display();
	}
	close();
	return 0;
}