#pragma once
#include "const.h"

static Texture texture, fire;
static Sprite sprite, fire_sprite;
static IntRect intRect(0, 0, 48, 65);
static IntRect intRect1(0, 0, 48, 65);
static IntRect intRect2(0, 0, 48, 65);
static IntRect rectBBsprite(0, 0, 480, 16);
static position movingBox;
static Clock clock1;
static Texture wall1, wall2, floor_texture, bookshelf1, bookshelf2, desk, armchair, host, dummy, bloodbar;
static Sprite host_sprite, bloodbar_sprite;
static vector < vector <Sprite> > object_sprite(map_height - 1, vector <Sprite>(map_width - 1));
static vector < vector <Sprite> > background_sprite(map_height, vector <Sprite>(map_width));
static Vector2f axis_x(4, 0);
static Vector2f axis_y(0, 5);

//setup
void loadtexture();
void setCharacterPos(RenderWindow& window, position& dummy);
//render player and object
void keyInput(vector < vector <char> >& map, Event event, position& dummy);
void characterMoving(RenderWindow& window, position& dummy);
void renderAnimation(RenderWindow& window, position& dummy, int& countFramePassed);
void renderBox(RenderWindow& window, vector < vector <char> >& map);
//render environment
void renderHost(RenderWindow& window, position& host_position, int& countFramePassed, bool& carring);
void renderWall(RenderWindow& window, vector<vector<char>>& map, int& countFramePassed);
void renderFloor(RenderWindow& window, vector < vector <char> >& map);
//set view and etc
void setView(RenderWindow& window, View view, position dummy_position);
void resetView(RenderWindow& window, View view);
void coutInfo(position& dummy);
void renderBloodbar(RenderWindow& window);