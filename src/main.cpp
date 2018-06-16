#include <SFML/Graphics.hpp>
#include "EventsManager.h"
#include "ButtonsPack.h"
#include "IconsPack.h"
#include "TextsPack.h"

#define W_HEIGHT 640
#define W_WIDTH 480


int main() {
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "SFML window", sf::Style::Titlebar | sf::Style::Close  );
	window.setFramerateLimit(60);

	sf::RectangleShape background;
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("img/background.png");
	background.setSize(sf::Vector2f(W_WIDTH,W_HEIGHT));
	background.setTexture(&backgroundTexture);

	EventsManager em;
	ButtonsPack bp;
	IconsPack ip;
	TextsPack tp;


	// Start the loop
	while (window.isOpen()) {
		// Process events
		sf::Event event;

		em.trackMousePositionOnWindow(window);

		bp.eventListener(&em);

		while (window.pollEvent(event)) {
			switch (event.type) {
			// window closed
			case sf::Event::Closed:
				window.close();
				break;

			// S key pressed
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					em.changeShowLightButtons();
				}
				break;

			// we don't process other types of events
			default:
				break;
			}
		}

		// Clear screen
		window.clear();
		window.draw(background);
		window.draw(ip.drawConnectionIcon(em.serialIsOpen()));

		if(!em.serialIsOpen()) {
			window.draw(tp.getConnectionErrorText());
			em.openConnection();
		} else {
		    window.draw(tp.getActualTempText(em.readTemperatureFromSerial()));
            window.draw(tp.getDegreesSymbolText());
			if (!em.getShowLightButtons()) {
				window.draw(bp.drawLightManagerButton(sf::Vector2f(W_WIDTH/3.3, W_HEIGHT/2)));
			} else {
				window.draw(bp.drawLightButton(2, sf::Vector2f(W_WIDTH/4.5, W_HEIGHT/1.5 - 140)));
				window.draw(bp.drawLightButton(1, sf::Vector2f(W_WIDTH/1.8, W_HEIGHT/1.5 - 140)));
				window.draw(bp.drawLightButton(0, sf::Vector2f(W_WIDTH/4.5, W_HEIGHT/1.5)));
				window.draw(bp.drawLightButton(4, sf::Vector2f(W_WIDTH/1.8, W_HEIGHT/1.5)));
			}
		}

		window.display();
	}
	return EXIT_SUCCESS;
}
