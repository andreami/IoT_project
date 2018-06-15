#ifndef EVENTSHANDLER_H
#define EVENTSHANDLER_H

#define MAX_LIGHT_NUMBER 5
#include "serial/serial.h"
#include <SFML/Graphics.hpp>
#include "HTTP.h"
#include "TextsPack.h"

class EventsManager {
public:
	EventsManager();
	virtual ~EventsManager();

	bool serialIsOpen();

    void trackMousePositionOnWindow(sf::RenderWindow &window);
    void openConnection();
    void changeLightStatus(int idx);
    std::string readTemperatureFromSerial();

    sf::Vector2f getClickedPoint();

protected:



private:

    int lightStatus[MAX_LIGHT_NUMBER] = {0,0,0,0,0};

    std::string temperature;

    sf::Vector2f clickedPoint;
    sf::Clock clock;

    serial::Serial serial;
    serial::Timeout t;

    void turnOnLight(int idx);
	void turnOffLight(int idx);
	HTTP request;
	bool connectionStatus;

	TextsPack tp;

};

#endif // EVENTSHANDLER_H
