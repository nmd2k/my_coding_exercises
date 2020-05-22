#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

static Texture menu_texture, tutorial_texture, button1, button2, button3;
static Sprite menu_sprite, tutorial_sprite, button1_sprite, button2_sprite, button3_sprite;

void loadmenu();
void menu(RenderWindow& window, Event& event, bool& startgame, bool& tutorial);
void tutorial_menu(RenderWindow& window, Event& event, bool& startgame);