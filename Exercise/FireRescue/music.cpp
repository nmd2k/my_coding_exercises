#include "music.h"

void loadMusic() {
	menuMusic.openFromFile("sound/menu.ogg");
	backgroundMusic.openFromFile("sound/background.ogg");
	menuMusic.setVolume(50);
	backgroundMusic.setVolume(10);
	menuMusic.setLoop(true);
	backgroundMusic.setLoop(true);
}

void menu_music(bool &startgame)
{
	if (!startgame) {
		if (menuMusic.getStatus() != Music::Status::Playing) {
			menuMusic.play(); cout << "play!" << endl;
		}
	}
	else if (startgame == true) {
		menuMusic.pause();
	}
}

void background_music(bool &gameOver)
{
	if (!gameOver) {
		if(backgroundMusic.getStatus() != Music::Status::Playing)
		backgroundMusic.play();
	}
	else backgroundMusic.pause();
}
