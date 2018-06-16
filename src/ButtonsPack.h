#ifndef BUTTONSPACK_H
#define BUTTONSPACK_H

#define MAX_LIGHT_NUMBER 5

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "EventsManager.h"

/** \brief Fornisce una serie di pulsanti predefiniti.*/

class ButtonsPack {
public:
	ButtonsPack();/**< \brief Costruttore della classe.*/
	virtual ~ButtonsPack();/**< \brief Distruttore della classe.*/


	sf::RectangleShape  drawLightButton(int id, sf::Vector2f pos);
	/**< \brief Disegna il pulsante light con l'id indicato.
	 *@param id Id del pulsante
	 *@param pos Posizione del pulsante
	 */
	sf::RectangleShape  drawLightManagerButton(sf::Vector2f pos);
	/**< \brief Disegna Il pulsante lightManager.
	 *@param pos Posizione del pulsante
	 */

	void eventListener(EventsManager *ev);
	/**< \brief Ascolta gli eventi generati dall'EventManager.
	 *@param ev Evento generato
	 */

protected:

private:
	Button light[MAX_LIGHT_NUMBER]; /**< \brief Array di pulsanti che rappresentano le lampadine.*/
	Button lightManager;    /**< \brief Pulsante che mostra la schermata per gestire le luci.*/

	void initLightButtons(); /**< \brief Inizializza il pulsante light.*/
	void initLightManagerButton(); /**< \brief Inizializza il pulsante lightManager.*/

	void lightButtonListener(Button &b);
	/**< \brief Ascolta gli eventi che riguardano i pulsanti light.
	 *@param b Pulsante da cui ascoltare gli eventi
	 */
	void lightManagerButtonListener();/**< \brief Ascolta gli eventi che riguardano il pulsante lightManager.*/


	EventsManager *event; /**< \brief Eventi generati dall'EventManager.*/

	bool buttonIsClicked(Button b);
	/**< \brief Ritorna true se il pulsante viene cliccato.
	 *@param b Pulsante su cui si compie l'azione
	 */

	sf::Clock clock;


};

#endif // BUTTONSPACK_H
