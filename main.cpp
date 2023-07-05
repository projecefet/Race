// MAIN

#include "race.hpp"
#include "levels.hpp"
#include "level1.hpp"
#include "level2.hpp"
#include "level3.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "wins.hpp"

void menu(sf::RenderWindow *window, int *janelaControle);

int main() {
	std::setbuf(stdout, NULL);
	int frameCounter_Player1 = 0;
	int frameCounter_Player2 = 0;
	bool ganhar2 = false;
	//int * qtestrela1 = 0;
	bool ganhar3 = false;

	Levels level;
	StarButton button01(1, sf::Vector2f(90, 190), 1); //numero de estrelas ---- nivel
	StarButton button02(2, sf::Vector2f(90, 280), 2);
	StarButton button03(3, sf::Vector2f(90, 370), 3);
	int janelaControle = 0;

	sf::Music ganhar;
	ganhar.openFromFile("assets/sounds/wins.wav");

	static Coins coins;
	int coinsLeft[10];


	for (int i = 0; i < 10; i++) {
		coinsLeft[i] = 1;
	}

	sf::RenderWindow window(sf::VideoMode(960, 540),
			"MARIO KART: Super Circuit 2600",
			sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	int coinsCollected = coins.coinsCollected(coinsLeft);

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
			if(button02.didGetClicked(&window) && ganhar2){
				janelaControle = 3;
			}
			if (button03.didGetClicked(&window) && ganhar3){
				janelaControle = 4;
			}

			break;
		case 2:
			level1(&window, &frameCounter_Player1, &frameCounter_Player2,
					&coins, coinsLeft, &ganhar2, &ganhar3, &janelaControle);
			break;
		case 3:
			level2(&window, &frameCounter_Player1, &frameCounter_Player2,
								&coins, coinsLeft, &janelaControle, &ganhar3);
			break;
		case 4:
			level3(&window, &frameCounter_Player1, &frameCounter_Player2,
								&coins, coinsLeft, &janelaControle);

			break;

		case 5:
			//ganhar.play();
			telamario(&window, &janelaControle);

			break;

		case 6:
			//ganhar.play();
			telabowser(&window, &janelaControle);

			break;
		}

		window.display();
		coinsCollected = coins.coinsCollected(coinsLeft);
	}

	return 0;
}
