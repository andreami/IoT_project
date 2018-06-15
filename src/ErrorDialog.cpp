#include "ErrorDialog.h"

ErrorDialog::ErrorDialog()
{
    //ctor
}

ErrorDialog::~ErrorDialog()
{
    //dtor
}

sf::RectangleShape ErrorDialog::showConnectionErrorDialog()
{
    window.setSize(sf::Vector2f(480,640));
    window.setFillColor(sf::Color::Red);
    return window;
}
