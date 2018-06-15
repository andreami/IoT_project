#ifndef TEXTSPACK_H
#define TEXTSPACK_H
#include <SFML/Graphics.hpp>


class TextsPack
{
    public:
        TextsPack();
        virtual ~TextsPack();

        void setTextPosition(sf::Text &t, sf::Vector2f pos);
        sf::Text getActualTempText(std::string temp);
        sf::Text getErrorTitleText();
        sf::Text getConnectionErrorText();
        sf::Text getDegreesText();

    protected:

    private:
        sf::Font font;
        sf::Text actualTemp;
        sf::Text errorTitle;
        sf::Text connectionError;
        sf::Text degrees;
};

#endif // TEXTSPACK_H
