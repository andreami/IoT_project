#ifndef TEXTSPACK_H
#define TEXTSPACK_H
#include <SFML/Graphics.hpp>

/** \brief Fornisce una serie di testi predefiniti.*/

class TextsPack {
public:
	TextsPack();/**< \brief Costruttore della classe.*/
	virtual ~TextsPack();/**< \brief Distruttore della classe.*/

	void setTextPosition(sf::Text &t, sf::Vector2f pos);
	/**< \brief Imposta la posizione del testo.
	 *@param t Testo di cui impostare la posizione
	 *@param pos Posizione in termini di (x,y)
	 */
	sf::Text getActualTempText(std::string temp);
	/**< \brief Restituisce un testo con la temperatura passata dal parametro.
	 *@param temp Temperatura da mostrare;
	 */
	sf::Text getConnectionErrorText();/**< \brief Restituisce il messaggio di errore connessione.*/
	sf::Text getDegreesSymbolText();/**< \brief Restituisce il simbolo dei gradi Celsius.*/

protected:

private:
	sf::Font font;
	sf::Text actualTemp;
	sf::Text errorTitle;
	sf::Text connectionError;
	sf::Text degrees;
};

#endif // TEXTSPACK_H
