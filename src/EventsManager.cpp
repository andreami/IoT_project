#include "EventsManager.h"
#include <string>

//#define DEBUG_MODE

#ifdef DEBUG_MODE
#define DEB(a) {a; }
#else
#define DEB(a)
#endif

using namespace serial;


EventsManager::EventsManager() {
	serial.setPort("/dev/ttyUSB0");  // /dev/ttyUSB0  /dev/ttyACM0
	serial.setBaudrate(9600);
	t.simpleTimeout(2000);
	serial.setTimeout(t);
	openConnection();
	temperature = "--";
	showLightButton = false;
}

EventsManager::~EventsManager() {
	serial.close();
}

void EventsManager::changeLightStatus(int idx) {
	if (serialIsOpen()) {
		if(!lightStatus[idx]) {
			turnOnLight(idx);
			DEB(printf("La lampadina %i è accesa\n", idx+1));
		} else {
			turnOffLight(idx);
			DEB(printf("La lampadina %i è spenta\n", idx+1));
		}
	} else
		DEB(printf("Dispositivo non connesso\n"));
}


bool EventsManager::serialIsOpen() {
	return serial.isOpen();
}

void EventsManager::openConnection() {
	try {
		serial.open();
		DEB(printf("Dispositivo connesso\n"));
	} catch(IOException) {

		serial.close();
	} catch(SerialException) {
		serial.close();
	}
}

void EventsManager::trackMousePositionOnWindow(sf::RenderWindow &window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	clickedPoint = sf::Vector2f(mousePos.x, mousePos.y);
}

sf::Vector2f EventsManager::getClickedPoint() {
	return clickedPoint;
}

void EventsManager::turnOnLight(int idx) {
	try {
		switch(idx) {
		case 0:
			serial.write("A");
			break;
		case 1:
			serial.write("C");
			break;
		case 2:
			serial.write("E");
			break;
        case 3:
			serial.write("G");
			break;
        case 4:
			serial.write("I");
			break;
		}
		lightStatus[idx] = 1;
	} catch(PortNotOpenedException) {
		serial.close();
	} catch(SerialException) {
		serial.close();
	}

}

void EventsManager::turnOffLight(int idx) {
	try {
		switch(idx) {
		case 0:
			serial.write("B");
			break;
		case 1:
			serial.write("D");
			break;
		case 2:
			serial.write("F");
			break;
        case 3:
			serial.write("H");
			break;
        case 4:
			serial.write("L");
			break;
		}
		lightStatus[idx] = 0;
	} catch(PortNotOpenedException) {
		serial.close();
	} catch(SerialException) {
		serial.close();
	}

}

std::string EventsManager::readTemperatureFromSerial() {
	try {
		if(clock.getElapsedTime() > sf::seconds(2.0f)) {
			serial.write("T");
			temperature = serial.readline(2);
			serial.read(3);
			clock.restart();
		}
		return temperature;
	} catch(PortNotOpenedException) {
		serial.close();
        DEB(printf("Dispositivo non connesso\n"));
	} catch(SerialException) {
		serial.close();
		DEB(printf("Dispositivo non connesso\n"));
	}
}

bool EventsManager::getShowLightButtons()
{
    return showLightButton;
}

void EventsManager::changeShowLightButtons()
{
    if(!showLightButton)
        showLightButton = true;
    else
        showLightButton = false;
}


/*
EventsManager::EventsManager() {
   // connectionStatus = false;
}

EventsManager::~EventsManager() {
}

void EventsManager::changeLightStatus(int idx) {
	if (checkConnection()) {
		if(!lightStatus[idx]) {
			request.turnOnLight(idx);
			lightStatus[idx] = 1;
		} else {
			request.turnOffLight(idx);
			lightStatus[idx] = 0;
		}
	} else
		printf("Connection error!\n");
}

void EventsManager::trackMousePositionOnWindow(sf::RenderWindow &window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	clickedPoint = sf::Vector2f(mousePos.x, mousePos.y);
}

sf::Vector2f EventsManager::getClickedPoint() {
	return clickedPoint;
}

bool EventsManager::checkConnection() {
	if(clock.getElapsedTime() > sf::seconds(4.0f)) {
		clock.restart();
		connectionStatus = request.testConnection();
		printf("Check connection....%i\n", connectionStatus);
	}
	return connectionStatus;
}
*/


