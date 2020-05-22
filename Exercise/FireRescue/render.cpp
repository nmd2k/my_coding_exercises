#include "render.h"

void loadtexture() {
	bookshelf1.loadFromFile("material/bookshelf.png");
	bookshelf2.loadFromFile("material/bookshelf2.png");
	desk.loadFromFile("material/desk.png");
	armchair.loadFromFile("material/armchair.png");
	floor_texture.loadFromFile("material/floor/floor3.png");
	host.loadFromFile("material/characters/hostage_sheet.png");
}

void renderBox(RenderWindow& window, vector < vector <char> >& map) {
	ifor(i, map_height) {
		ifor(j, map_width) {
				if (map[i][j] == '3') {
					//render box
					object_sprite[i][j].setTexture(bookshelf1);
					object_sprite[i][j].setPosition(j * width, i * height - 10);
					window.draw(object_sprite[i][j]);
				}
				//else if (map[i][j] == '4') { //can't move
				//	//render box
				//	object_sprite[i][j].setTexture(bookshelf2);
				//	object_sprite[i][j].setPosition(j * width, i * height - 10);
				//	window.draw(object_sprite[i][j]);
				//}
				//else if (map[i][j] == '5') {
				//	//render box
				//	object_sprite[i][j].setTexture(desk);
				//	object_sprite[i][j].setPosition(j * width, i * height - 10);
				//	window.draw(object_sprite[i][j]);
				//}
				//else if (map[i][j] == '6') {
				//	//render box
				//	object_sprite[i][j].setTexture(armchair);
				//	object_sprite[i][j].setPosition(j * width, i * height - 10);
				//	window.draw(object_sprite[i][j]);
				//}
		}
	}
}

void renderFloor(RenderWindow& window, vector < vector <char> >& map) {
	ifor(i, map_height) {
		ifor(j, map_width) {
			background_sprite[i][j].setTexture(floor_texture);
			background_sprite[i][j].setPosition(j * width, i * height);
			window.draw(background_sprite[i][j]);
		}
	}
}


void renderHost(RenderWindow& window, position& host_position, int& countFramePassed) {
	host_sprite.setTexture(host);
	host_sprite.setTextureRect(characterSprite);
	host_sprite.setPosition((float)host_position.x * width, (float)host_position.y * height - extra_size);
	if (countFramePassed == 8) {
		if (characterSprite.left == 144) {
			characterSprite.left = 0;
		}
		else {
			characterSprite.left += 48;
		}
		//countFramePassed = 0;
	}
	host_sprite.setTextureRect(characterSprite);
	window.draw(host_sprite);
}

void renderBloodbar(RenderWindow& window, Clock& clock) {
	bloodbar.loadFromFile("material/bloodbar/bloodbar.png");
	//IntRect rectSourceSprite(0, 0, 480, 16);
	bloodbar_sprite.setTexture(bloodbar);
	bloodbar_sprite.setTextureRect(rectBBsprite);
	bloodbar_sprite.setPosition((map_width * width - 480)/2, height * 9);

	if (clock.getElapsedTime().asSeconds() > 5.45f) {
		rectBBsprite.top += 16;
		bloodbar_sprite.setTextureRect(rectBBsprite);
		clock.restart();
	}

	window.draw(bloodbar_sprite);
}


void renderWall(RenderWindow& window, vector<vector<char>>& map) {
	wall1.loadFromFile("material/wall/wall5.png");
	wall2.loadFromFile("material/wall/wall6.png");
	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '2') {
				background_sprite[i][j].setTexture(wall1);
				background_sprite[i][j].setPosition(j * width, i * height ); //- extra_size
				window.draw(background_sprite[i][j]);
			}
			else if (map[i][j] == '1') {
				background_sprite[i][j].setTexture(wall2);
				background_sprite[i][j].setPosition(j * width, i * height); //- extra_size
				window.draw(background_sprite[i][j]);
			}
		}
	}
}

//
//void setView(RenderWindow& window, View view,position dummy_position) {
//	view.setCenter((float)dummy_position.x * width, (float)dummy_position.y * height);
//	window.setView(view);
//}