#include "TextsPack.h"
#define W_HEIGHT 640
#define W_WIDTH 480

TextsPack::TextsPack()
{
	if (!font.loadFromFile("fonts/Dosis-Light.ttf")) {
		printf("Impossibile trovare il font.");
	}
    // select the font
	actualTemp.setFont(font);
	actualTemp.setCharacterSize(150);
	degrees.setFont(font);
	degrees.setCharacterSize(150);
    // set the string to display
    connectionError.setFont(font);
    connectionError.setCharacterSize(50);
	connectionError.setString("Impossibile \nconnettersi \nal dispositivo.");

}

TextsPack::~TextsPack()
{

}

void TextsPack::setTextPosition(sf::Text& t, sf::Vector2f pos)
{
    t.setPosition(pos);
}

sf::Text TextsPack::getActualTempText(std::string temp)
{
    actualTemp.setString(temp);
    actualTemp.setPosition(sf::Vector2f(W_WIDTH/2.5 - actualTemp.getCharacterSize()/1.5, actualTemp.getCharacterSize()/2));
    return actualTemp;
}

sf::Text TextsPack::getConnectionErrorText()
{
    connectionError.setPosition(sf::Vector2f(W_WIDTH/2.5 - connectionError.getCharacterSize()*1.5, W_HEIGHT/3));
    return connectionError;
}

sf::Text TextsPack::getDegreesSymbolText()
{
    degrees.setString(L"°C");
    degrees.setPosition(sf::Vector2f(actualTemp.getPosition().x + degrees.getCharacterSize(), degrees.getCharacterSize()/2));
    return degrees;
}
