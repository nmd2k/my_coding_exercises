#include "menu.h"

void tutorial_menu(RenderWindow& window, Event& event, bool& startgame) {
	auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
	auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
	while (window.pollEvent(event)) {
		window.draw(tutorial_sprite);
		button1_sprite.setPosition(401, 75);
		window.draw(button1_sprite);
		window.display();
		if (button1_sprite.getGlobalBounds().contains(translated_pos)) {
			if (event.type == Event::MouseButtonPressed) {
				cout << "Pressed!" << endl;
				startgame = true;
			}
		}
		else if (event.type == Event::Closed) window.close();
	}
}

void loadmenu() {
	//setup
	menu_texture.loadFromFile("menu/menu.png");
	tutorial_texture.loadFromFile("menu/tutorial_full.png");
	button1.loadFromFile("menu/startgame.png");
	button2.loadFromFile("menu/tutorial.png");
	button3.loadFromFile("menu/exitgame.png");
	menu_sprite.setTexture(menu_texture);
	tutorial_sprite.setTexture(tutorial_texture);
	button1_sprite.setTexture(button1);
	button2_sprite.setTexture(button2);
	button3_sprite.setTexture(button3);
	//render
}

void menu(RenderWindow& window, Event& event, bool& startgame, bool& tutorial)
{
	window.clear();
	button1_sprite.setPosition(401, 300);
	button2_sprite.setPosition(413.5, 385);
	button3_sprite.setPosition(413.5, 460);
	window.draw(menu_sprite);
	window.draw(button1_sprite);
	window.draw(button2_sprite);
	window.draw(button3_sprite);
	window.display();
	while (window.pollEvent(event)) {
		auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
		auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates

		if (button1_sprite.getGlobalBounds().contains(translated_pos)) { // Rectangle-contains-point check
			if (event.type == Event::MouseButtonPressed) {
				cout << "Pressed!" << endl;
				startgame = true;
			}
		}
		else if (button2_sprite.getGlobalBounds().contains(translated_pos))
		{
			if (event.type == Event::MouseButtonPressed) {
				cout << "Pressed!" << endl;
				tutorial = true;
			}

		}
		else if (button3_sprite.getGlobalBounds().contains(translated_pos)) {
			if (event.type == Event::MouseButtonPressed) {
				cout << "Pressed!" << endl;
				window.close();
			}
		}
		else if (event.type == Event::Closed) window.close();
	}
}
