#include "IconsPack.h"

IconsPack::IconsPack() {
	initIcons();
}

IconsPack::~IconsPack() {
	//dtor
}

void IconsPack::initIcons() {
	conncetionIcon.setTexures("img/success.png", "img/error.png");
	conncetionIcon.setPosition(sf::Vector2f(10, 10));
}

void IconsPack::iconListener(Icon &i) {
	if(i.getStatus()) {
		i.changeTexture(true);
	} else{
        i.changeTexture(false);
    }
}

sf::RectangleShape IconsPack::drawConnectionIcon(bool connectionStatus)
{
    setIconStatus(conncetionIcon, connectionStatus);
    iconListener(conncetionIcon);
    return conncetionIcon.getRect();
}

void IconsPack::setIconStatus(Icon &i, bool s)
{
    i.setStatus(s);
}
