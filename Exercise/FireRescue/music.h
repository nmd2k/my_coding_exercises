#pragma once
#include "const.h"
#include "SFML/Audio.hpp"

static Music menuMusic;
static Music backgroundMusic;

void loadMusic();
void menu_music(bool& startgame);
void background_music(bool& gameOver);