#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
using namespace std;
using namespace sf;

static Texture wall1, wall2, floor_texture, bookshelf1, bookshelf2, desk, armchair, host, dummy, bloodbar;
static Sprite host_sprite, dummy_sprite, bloodbar_sprite;
static vector < vector <Sprite> > object_sprite(height - 1, vector <Sprite>(width - 1));
static vector < vector <Sprite> > background_sprite(height - 1, vector <Sprite>(width - 1));
static IntRect rectBBsprite(0, 0, 480, 16);
static IntRect characterSprite(0, 0, 48, 65);
static Clock clock_host;

//render (floor -> character -> box -> wall)
void loadtexture();
void renderFloor(RenderWindow& window, vector < vector <char> >& map);
void renderBox(RenderWindow& window, vector < vector <char> >& map);
void renderHost(RenderWindow &window, position& host_position, int& countFramePassed);
void renderWall(RenderWindow& window, vector < vector <char> >& map);
void renderBloodbar(RenderWindow& window, Clock& clock);
//void setView(RenderWindow& window, View view, position dummy_position);