#ifndef ICONSPACK_H
#define ICONSPACK_H
#include "Icon.h"

class IconsPack {
public:
	IconsPack();
	virtual ~IconsPack();

	void initIcons();

	sf::RectangleShape drawConnectionIcon(bool connectionStatus);

    void setIconStatus(Icon &i, bool s);

protected:

private:
	Icon conncetionIcon;
	void iconListener(Icon &i);

    sf::Clock clock;
};

#endif // ICONSPACK_H
