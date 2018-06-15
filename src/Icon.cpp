#include "Icon.h"

Icon::Icon() {
    status = false;
}

Icon::~Icon() {
	//dtor
}

sf::RectangleShape Icon::getRect()
{
    return rect;
}

void Icon::setTexures(std::string textureName1, std::string textureName2) {
	texture[0].loadFromFile(textureName1);
	texture[1].loadFromFile(textureName2);
	rect.setSize(sf::Vector2f(32, 32));
	rect.setTexture(&texture[0]);
}

void Icon::setPosition(sf::Vector2f pos) {
	rect.setPosition(pos);
}

void Icon::changeTexture(bool state) {
	if(!state) {
		rect.setTexture(&texture[1]);
		state = true;
	} else {
		rect.setTexture(&texture[0]);
		state = false;
	}
}

bool Icon::getStatus()
{
    return status;
}

void Icon::setStatus(bool s)
{
    status = s;
}

