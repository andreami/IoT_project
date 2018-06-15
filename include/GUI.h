#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include "TextsPack.h"


class GUI : public TextsPack {
public:
	GUI();
	virtual ~GUI();
	sf::RectangleShape drawWaitingScreen();
	sf::RectangleShape drawErrorScreen();
	sf::RectangleShape drawBackground();

protected:

private:
	sf::RectangleShape screen;
	sf::Texture background;
};

#endif // GUI_H
