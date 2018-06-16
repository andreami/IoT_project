#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "EventsManager.h"

/** \brief Modello che definisce un pulsante.*/

class Button {
public:
	Button();/**< \brief Costruttore della classe.*/
	virtual ~Button();/**< \brief Distruttore della classe.*/

	int getId();/**< \brief Restituisce l'ID del pulsante.*/

	sf::RectangleShape getRectangle();/**< \brief Restituisce la grafica del pulsante.*/


	void setTexures(std::string textureName1, std::string textureName2);
	/**< \brief Imposta le texture collegate agli stati del pulsante.
	 *@param textureName1 Texture dello stato positivo
	 *@param textureName2 Texture dello stato negativo
	 */
	void changeTexture();/**< \brief Modifica la texture del pulsante.*/


	void setPosition(sf::Vector2f pos);
	/**< \brief Imposta la posizione del pulsante.
	 *@param pos La posizione in termini di (x,y)
	 */
	void setSize(sf::Vector2f s);
	/**< \brief Imposta la dimensione del pulsante.
	*@param s La dimensione in termini di larghezza e altezza
	*/

protected:

private:
	int idx;
	int generateID();

	bool state;

	sf::RectangleShape rect;
	sf::Texture texture[2];

};

#endif // BUTTON_H
