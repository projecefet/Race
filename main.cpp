// MAIN

#include "levels.hpp"
#include "level1.hpp"
#include <SFML/Graphics.hpp>
#include "wins.hpp"

void menu(sf::RenderWindow *window, int *janelaControle);

int main() {
	std::setbuf(stdout, NULL);
	int frameCounter_Player1 = 0;
	int frameCounter_Player2 = 0;

	Levels level;
	StarButton button01(0, sf::Vector2f(90, 190), 1);
	StarButton button02(2, sf::Vector2f(90, 280), 0);
	StarButton button03(3, sf::Vector2f(90, 370), 2);
	int janelaControle = 0;

	sf::RenderWindow window(sf::VideoMode(960, 540),
			"MARIO KART: Super Circuit",
			sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		frameCounter_Player1++;
		frameCounter_Player2++;

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
			if (button01.didGetClicked(&window)) {
				janelaControle = 2;
			}
			button02.didGetClicked(&window);
			button03.didGetClicked(&window);

			break;
		case 2:
			level1(&window, &frameCounter_Player1, &frameCounter_Player2, &janelaControle);
			break;
		case 3:
			telamario(&window, &janelaControle);
		case 4:
			telabowser(&window, &janelaControle);
		}


		window.display();
	}

	return 0;
}
