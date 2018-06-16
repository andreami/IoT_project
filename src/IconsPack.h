#ifndef ICONSPACK_H
#define ICONSPACK_H
#include "Icon.h"

/** \brief Fornisce una serie di icone predefinite.*/

class IconsPack {
public:
	IconsPack();/**< \brief Costruttore della classe.*/
	virtual ~IconsPack();/**< \brief Distruttore della classe.*/

	sf::RectangleShape drawConnectionIcon(bool connectionStatus);
	/**< \brief Disegna l'icona che mostra lo stato della connessione.
	 *@param connectionStatus Stato della connessione
	 */

	void setIconStatus(Icon &i, bool s);
	/**< \brief Modifica lo stato dell'icona (Success/Error).
	 *@param i Icona di cui modificare lo stato
	 *@param s Stato (true/false)
	 */

protected:

private:
	Icon conncetionIcon;

	void iconListener(Icon &i);
	void initIcons();

	sf::Clock clock;
};

#endif // ICONSPACK_H
