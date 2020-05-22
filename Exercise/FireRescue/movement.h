#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "const.h"

using namespace sf;
using namespace std;

void movement(Event event, vector < vector <char> >& map, position& dummy_position);
