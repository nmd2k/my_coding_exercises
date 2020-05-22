#include "animation.h"

void loadtexture() {
	bookshelf1.loadFromFile("material/bookshelf.png");
	bookshelf2.loadFromFile("material/bookshelf2.png");
	desk.loadFromFile("material/desk.png");
	armchair.loadFromFile("material/armchair.png");
	floor_texture.loadFromFile("material/floor/floor4.png");
	host.loadFromFile("material/characters/hostage.png");
	texture.loadFromFile("material/characters/firerman_sheet_full.png");
	bloodbar.loadFromFile("material/bloodbar/bloodbar.png");
	fire.loadFromFile("material/fire.png");
	wall1.loadFromFile("material/wall/wall6.png");
	wall2.loadFromFile("material/wall/wall5.png");
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


void renderWall(RenderWindow& window, vector<vector<char>>& map, int &countFramePassed) {
	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '1') {
				background_sprite[i][j].setTexture(wall1);
				background_sprite[i][j].setPosition(j * width, i * height); //- extra_size
				window.draw(background_sprite[i][j]);
			}
			else if (map[i][j] == '2') {
				background_sprite[i][j].setTexture(wall2);
				background_sprite[i][j].setPosition(j * width, i * height); //- extra_size
				window.draw(background_sprite[i][j]);
			}
			else if (map[i][j] == '5') {
				fire_sprite.setTexture(fire);
				fire_sprite.setTextureRect(intRect2);
				if ((countFramePassed & 7) == 0) {
					if (intRect2.left == 144) {
						intRect2.left = 0;
					}
					else {
						intRect2.left += 48;
					}
					//countFramePassed = 0;
				}
				fire_sprite.setTextureRect(intRect2);
				background_sprite[i][j].setPosition(j * width, i * height);
				window.draw(fire_sprite);
			}
		}
	}
}

void renderHost(RenderWindow& window, position& host_position, int& countFramePassed, bool &carring) {
	host_sprite.setTexture(host);
	//host_sprite.setTextureRect(intRect);
	host_sprite.setPosition((float)host_position.x * width, (float)host_position.y * height - extra_size);
	if (carring == true) intRect1.top = 65;
	if ((countFramePassed & 7) == 0) {
		if (intRect1.left == 144) {
			intRect1.left = 0;
		}
		else {
			intRect1.left += 48;
		}
		
		//cout << host_position.x << ' ' << host_position.y << endl;
			 
	}
	host_sprite.setTextureRect(intRect1);
	//cout << countFramePassed << endl; 
	window.draw(host_sprite);
}

void keyInput(vector < vector <char> >& map, Event event, position& dummy)
{
	int x = dummy.x;
	int y = dummy.y;
	switch (event.key.code)
	{
	case Keyboard::Up:
		cout << "Up" << endl;
		if (map[y - 1][x] == '0' or map[y - 1][x] == '9') {
			dummy.y--;
			dummy.state = UP;
			dummy.moving = true;
		}
		else if ((map[y - 1][x] == '3' or map[y - 1][x] == '4' or map[y - 1][x] == '5' 
					or map[y - 1][x] == '6') and map[y - 2][x] == '0') { //if anytype of box
			movingBox.type = map[y - 1][x];
			map[y - 1][x] = '0';
		//	map[y - 2][x] = '3';
			//moving
			movingBox.x = x;
			movingBox.y = y - 1; 
			movingBox.moving = true;
			movingBox.state = UP;
			//player
			dummy.y--;
			dummy.state = UP;
			dummy.moving = true;
		}
		break;
	case Keyboard::Down:
		cout << "Down" << endl;
		if (map[y + 1][x] == '0' or map[y + 1][x] == '9') {
			dummy.y++;
			dummy.state = DOWN;
			dummy.moving = true;
		}
		else if ((map[y + 1][x] == '3' or map[y + 1][x] == '4' or map[y + 1][x] == '5'
			or map[y + 1][x] == '6') and map[y + 2][x] == '0') {
			movingBox.type = map[y + 1][x];
			map[y + 1][x] = '0';
			//map[y + 2][x] = '3';
			//moving
			movingBox.x = x;
			movingBox.y = y + 1;
			movingBox.moving = true;
			movingBox.state = DOWN;
			//player
			dummy.y++;
			dummy.state = DOWN;
			dummy.moving = true;
		}
		break;
	case Keyboard::Right:
		cout << "Right" << endl;
		if (map[y][x + 1] == '0' or map[y][x + 1] == '9') {
			dummy.x++;
			dummy.state = RIGHT;
			dummy.moving = true;
		}
		else if ((map[y][x + 1] == '3' or map[y][x + 1] == '4' or map[y][x + 1] == '5' 
			or map[y][x + 1] == '6' )and map[y][x + 2] == '0') {
			movingBox.type = map[y][x + 1];
			map[y][x + 1] = '0';
			//map[y][x + 2] = '3';
			//moving
			movingBox.x = x+1;
			movingBox.y = y;
			movingBox.moving = true;
			movingBox.state = RIGHT;
			//player
			dummy.x++;
			dummy.state = RIGHT;
			dummy.moving = true;
		}
		break;
	case Keyboard::Left:
		cout << "Left" << endl;
		if (map[y][x - 1] == '0' or map[y][x - 1] == '9') {
			dummy.x--;
			dummy.state = LEFT;
			dummy.moving = true;
		}
		else if ((map[y][x - 1] == '3' or map[y][x - 1] == '4' or map[y][x - 1] == '5'
			or map[y][x - 1] == '6') and map[y][x - 2] == '0') {
			movingBox.type = map[y][x - 1];
			map[y][x - 1] = '0';
			//map[y][x - 2] = '3';
			//moving
			movingBox.x = x - 1;
			movingBox.y = y;
			movingBox.moving = true;
			movingBox.state = LEFT;
			//player
			dummy.x--;
			dummy.state = LEFT;
			dummy.moving = true;
		}
		break;
	default:
		break;
	}
}

void renderBox(RenderWindow& window, vector < vector <char> >& map) {
	//object.setTexture(bookshelf1);
	int x = movingBox.x;
	int y = movingBox.y;

	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '3') {
				//render box
/*				object.setTexture(bookshelf1);
				object.setPosition(j * width, i * height - 8);*/
				object_sprite[i][j].setTexture(bookshelf1);
				object_sprite[i][j].setPosition(j * width, i * height - 8);
				window.draw(object_sprite[i][j]);
			}
			else if (map[i][j] == '4') {
				//render box
/*				object.setTexture(bookshelf1);
				object.setPosition(j * width, i * height - 8);*/
				object_sprite[i][j].setTexture(bookshelf2);
				object_sprite[i][j].setPosition(j * width, i * height - 8);
				window.draw(object_sprite[i][j]);
			}
//			else if (map[i][j] == '5') {
//				//render box
///*				object.setTexture(bookshelf1);
//				object.setPosition(j * width, i * height - 8);*/
//				object_sprite[i][j].setTexture(armchair);
//				object_sprite[i][j].setPosition(j * width, i * height - 8);
//				window.draw(object_sprite[i][j]);
//			}
			else if (map[i][j] == '6') {
				//render box
/*				object.setTexture(bookshelf1);
				object.setPosition(j * width, i * height - 8);*/
				object_sprite[i][j].setTexture(desk);
				object_sprite[i][j].setPosition(j * width, i * height - 8);
				window.draw(object_sprite[i][j]);
			}
		}
	}

	if (movingBox.moving == true) {
		switch (movingBox.state)
		{
		case UP:
			//if (object.getPosition().y >= movingBox.y * height - 8) {
			//	object.move(-axis_y);
			//}
			if (object_sprite[y][x].getPosition().y >= (movingBox.y-1) * height - 8) { // if này đe lam gi 
				object_sprite[y][x].move(-axis_y);
			}
			else {
				map[y-1][x] = movingBox.type;
				movingBox.moving = false;
				movingBox.state = STOPUP;
			}
			window.draw(object_sprite[y][x]);
			break;
		case DOWN:
			if (object_sprite[y][x].getPosition().y <= (movingBox.y+1) * height - 8) {
				object_sprite[y][x].move(axis_y);
			}
			else {
				map[y + 1][x] = movingBox.type;
				movingBox.moving = false;
				movingBox.state = STOPDOWN;
			}
			window.draw(object_sprite[y][x]);
			break;
		case RIGHT:
			if (object_sprite[y][x].getPosition().x <= (movingBox.x+1) * width) {
				object_sprite[y][x].move(axis_x);
			}
			else {
				map[y][x + 1] = movingBox.type;
				movingBox.moving = false;
				movingBox.state = STOPRIGHT;
			}
			window.draw(object_sprite[y][x]);
			break;
		case LEFT:
			if (object_sprite[y][x].getPosition().x >= (movingBox.x-1) * width) {
				object_sprite[y][x].move(- axis_x);
			}
			else {
				map[y][x - 1] = movingBox.type;
				movingBox.moving = false;
				movingBox.state = STOPLEFT;
			}
			window.draw(object_sprite[y][x]);
			break;
		default:
			break;

		}
	}
}

void characterMoving(RenderWindow& window, position& dummy)
{
	if (dummy.moving) {
		switch (dummy.state)
		{
		case UP:
			if (sprite.getPosition().y >= dummy.y * height - 25 ) {
				sprite.move(-axis_y);
				//axis_y là vector2f (0, 4) tức là mỗi lần move lên 4 đơn vị rồi draw cái nhân vật đấy
			}
			else {
				dummy.state = STOPUP;
				dummy.moving = false;
			}
			break;
		case DOWN:
			if (sprite.getPosition().y <= dummy.y * height - 25) {
				sprite.move(axis_y);
			}
			else {
				dummy.state = STOPDOWN;
				dummy.moving = false;
			}
			break;
		case RIGHT:
			if (sprite.getPosition().x <= dummy.x * width) {
				sprite.move(axis_x);
			}
			else {
				dummy.state = STOPRIGHT;
				dummy.moving = false;
			}
			break;
		case LEFT:
			if (sprite.getPosition().x >= dummy.x * width) {
				sprite.move(-axis_x);
			}
			else {
				dummy.state = STOPLEFT;
				dummy.moving = false;
			}
			break;
		default:
			break;
		}
	}
}

void renderAnimation(RenderWindow& window, position& dummy, int& countFramePassed)
{
	//texture.loadFromFile("material/characters/firerman_sheet_full.png");
	sprite.setTexture(texture);
	if ((countFramePassed & 7) == 0) {
		if (intRect.left == 48*3) {
			intRect.left = 0;
		}
		else {
			intRect.left += 48;
		}
		
	}
	intRect.top = dummy.state * 65;
	sprite.setTextureRect(intRect);
	window.draw(sprite);
}

void setCharacterPos(RenderWindow& window, position& dummy)
{
	sprite.setPosition((float)dummy.x * width, (float)dummy.y * height - 25);
	coutInfo(dummy);
}

void setView(RenderWindow& window, View view, position dummy_position) {
	view.setCenter((float)sprite.getPosition().x, (float)sprite.getPosition().y);
	window.setView(view);
}

void resetView(RenderWindow& window, View view)
{
	view.setSize(1080, 720);
	view.setCenter(540, 360);
	window.setView(view);
}

void renderBloodbar(RenderWindow& window) {
	bloodbar_sprite.setTexture(bloodbar);
	bloodbar_sprite.setTextureRect(rectBBsprite);
	if (clock1.getElapsedTime().asSeconds() > 10.5f) {
		rectBBsprite.top += 16;
		bloodbar_sprite.setTextureRect(rectBBsprite);
		clock1.restart();
	}
	bloodbar_sprite.setPosition(sprite.getPosition() + Vector2f(-270, 285));
	window.draw(bloodbar_sprite);
}

void coutInfo(position& dummy) {
	cout << "dummy.x = " << dummy.x << endl
		<< "dummy.y = " << dummy.y << endl
		<< "sprite.x = " << sprite.getPosition().x << endl
		<< "sprite.y = " << sprite.getPosition().y << endl;
}
