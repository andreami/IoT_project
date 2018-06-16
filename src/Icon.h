#ifndef ICON_H
#define ICON_H
#include <SFML/Graphics.hpp>
#include "EventsManager.h"

/** \brief Modello che definisce un'icona.*/

class Icon {
public:
	Icon();/**< \brief Costruttore della classe.*/
	virtual ~Icon();/**< \brief Distruttore della classe.*/

	sf::RectangleShape getRect();/**< \brief Restituisce la grafica dell'icona.*/

	void setTexures(std::string textureName1, std::string textureName2);
	/**< \brief Imposta le texture collegate agli stati dell'icona.
	 *@param textureName1 Texture dello stato positivo
	 *@param textureName2 Texture dello stato negativo
	 */
	void setPosition(sf::Vector2f pos);
	/**< \brief Imposta la posizione dell'icona.
	 *@param pos La posizione in termini di (x,y)
	 */
	void changeTexture(bool state = false);
	/**< \brief Modifica la texture dell'icona.*/
	bool getStatus();/**< \brief Restituisce lo stato dell'icona (Success/Error).*/
	void setStatus(bool s);
	/**< \brief Imposta lo stato dell'icona.
	 *@param s Stato(true/false)
	 */

protected:

private:
	sf::RectangleShape rect;
	sf::Texture texture[2];
	bool status;

};

#endif // ICON_H
