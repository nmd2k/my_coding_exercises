#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <SFML/Window.hpp>
#define ifor(i, m) for (int i = 0; i < (m); i++)

const int width = 48;
const int height = 49;
const int map_width = 50;
const int map_height = 50;
const int extra_size = 20;
static const float _VIEW_HEIGHT = 1568;
static const float _VIEW_WIDTH = 1176;
static enum State { STOPDOWN = 0, DOWN, STOPUP, UP, STOPRIGHT, RIGHT, STOPLEFT, LEFT };

using namespace std;
using namespace sf;


class position {
public:
	//position
	int x = 0, y = 0;
	//state
	State state = STOPDOWN;
	bool moving = false;
	//box only
	char type = 0;
};