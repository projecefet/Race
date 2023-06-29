// MAIN


#include "levels.hpp"
#include "level1.hpp"
#include <SFML/Graphics.hpp>

void menu(sf::RenderWindow *window, int *janelaControle);

int main() {
	Levels level;
	StarButton button01(0, sf::Vector2f(90, 190), 0);
	StarButton button02(0, sf::Vector2f(90, 280), 1);
	StarButton button03(0, sf::Vector2f(90, 370), 2);
	int janelaControle = 0;

	sf::RenderWindow window(sf::VideoMode(960, 540),
			"MARIO KART: Super Circuit",
			sf::Style::Titlebar | sf::Style::Close);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		switch (janelaControle) {
		case 0:
			menu(&window, &janelaControle);
			break;
		case 1:
			level.render(&window);
			button01.render(&window);
			button02.render(&window);
			button03.render(&window);
			break;
		case 2:
			level1(&window);
			break;
		}

		window.display();
	}

	return 0;
}
