#include "Button.h"

Button::Button() {
	idx = generateID();
	state = false;
}

Button::~Button() {

}

int Button::generateID() {
	static int s_id = 0;
	return s_id++;
}

int Button::getId() {
	return idx;
}

sf::RectangleShape Button::getRectangle() {
	return rect;
}


void Button::changeTexture() {
	if(!state) {
		rect.setTexture(&texture[1]);
		state = true;
	} else {
		rect.setTexture(&texture[0]);
		state = false;
	}
}

void Button::setTexures(std::string textureName1, std::string textureName2) {
	texture[0].loadFromFile(textureName1);
	texture[1].loadFromFile(textureName2);
	rect.setSize(sf::Vector2f(100, 128));
	rect.setTexture(&texture[0]);
}

void Button::setSize(sf::Vector2f s){
    rect.setSize(s);
}

void Button::setPosition(sf::Vector2f pos) {
	rect.setPosition(pos);
}




