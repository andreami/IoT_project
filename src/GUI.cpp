#include "GUI.h"

GUI::GUI() {
	screen.setSize(sf::Vector2f(480,640));
	background.loadFromFile("img/background.png");
}

GUI::~GUI() {
	//dtor
}

sf::RectangleShape GUI::drawWaitingScreen() {
	screen.setFillColor(sf::Color::Magenta);
	return screen;
}

sf::RectangleShape GUI::drawErrorScreen() {
	screen.setFillColor(sf::Color::Transparent);
	return screen;
}

sf::RectangleShape GUI::drawBackground()
{
    screen.setTexture(&background);
	return screen;
}

