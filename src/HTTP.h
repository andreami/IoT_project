#ifndef HTTP_H
#define HTTP_H
#include <SFML/Network.hpp>

/** \brief Fornisce dei metodi per connettersi wireless con il microcontrollore.*/

class HTTP {
public:
	HTTP();/**< \brief Costruttore della classe.*/
	virtual ~HTTP();/**< \brief Distruttore della classe.*/
	void turnOnLight(int idx);
	/**< \brief Invia una richiesta http al microcontrollore per accendere la lampadina con id=idx.
	 *@param idx Id della lampadina
	 */
	void turnOffLight(int idx);
	/**< \brief Invia una richiesta http al microcontrollore per spegnere la lampadina con id=idx.
	 *@param idx Id della lampadina
	 */
	bool testConnection();/**< \brief Restituisce lo stato della connessione wireless con il microcontrollore.*/

protected:

private:
	sf::Http http;
	sf::Http::Request request;
	sf::Http::Response response;
	void initLight();

};

#endif // HTTP_H
