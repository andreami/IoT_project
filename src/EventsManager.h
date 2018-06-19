#ifndef EVENTSHANDLER_H
#define EVENTSHANDLER_H

#define MAX_LIGHT_NUMBER 5
#include <serial.h>
#include <SFML/Graphics.hpp>
#include "HTTP.h"
#include "TextsPack.h"

/** \brief Gestore degli eventi (mouse, porta seriale, pulsanti)*/

class EventsManager {
public:
	EventsManager();/**< \brief Costruttore della classe.*/
	virtual ~EventsManager();/**< \brief Distruttore della classe.*/

	bool serialIsOpen();/**< \brief Restituisce lo stato della connessione con la porta seriale.*/

    void trackMousePositionOnWindow(sf::RenderWindow &window);
    /**< \brief Tiene traccia della posizione del puntatore del mouse.
	 *@param window La finestra dell'applicazione
	 */
    void openConnection();/**< \brief Apre la connessione con la porta seriale.*/
    void changeLightStatus(int idx);
    /**< \brief Invia un segnale alla porta seriale modificando lo stato della lampadina con id=idx.
	 *@param idx Id della lampadina
	 */

    bool getShowLightButtons();/**< \brief Restituisce lo stato del pulsante lightManager (show/hide).*/
    void changeShowLightButtons();/**< \brief Modifica lo stato del pulsante lightManager (show/hide).*/

    std::string readTemperatureFromSerial();/**< \brief Legge la temperatura dalla porta seriale.*/

    sf::Vector2f getClickedPoint();/**< \brief Restituisce il punto cliccato dal mouse.*/

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
	bool showLightButton;

	TextsPack tp;

};

#endif // EVENTSHANDLER_H
