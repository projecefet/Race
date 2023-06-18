#include "race.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using sf::Color;
using sf::Texture;
using sf::Sprite;
using sf::Vector2f;


int jogo(sf::RenderWindow* window) {


	window->setFramerateLimit(60);

	float tempo = 1.0;

	Texture texturaMapa;
	texturaMapa.loadFromFile("assets/mapas/1.png");
	Sprite Mapa1;
	Mapa1.setTexture(texturaMapa);

	Texture texturaMario;
	texturaMario.loadFromFile("assets/carros/mario.png");
	Sprite Mario;
	Mario.setTexture(texturaMario);

	float escala = 1.5;

	Vector2f currentPositionPlayer1(window->getSize().x / 2,
			window->getSize().y / 2);
	Player Player1(Mario, escala, currentPositionPlayer1);
	Player1.montaPlayer();

	Texture texturaPeach;
	texturaPeach.loadFromFile("assets/carros/peach.png");
	Sprite Peach;
	Peach.setTexture(texturaPeach);

	Vector2f currentPositionPlayer2(window->getSize().x / 3,
			window->getSize().y / 3);
	Player Player2(Peach, escala, currentPositionPlayer2);
	Player2.montaPlayer();

	Wall wallMap1(Vector2f(600,300), Vector2f(100, 10));


	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
		}

		Player1.lastPosition = Player1.currentPosition;
		Player2.lastPosition = Player2.currentPosition;

		Player1.moveByPressing(Id_Player1);
		Player1.setRotation(Id_Player1);

		Player2.moveByPressing(Id_Player2);
		Player2.setRotation(Id_Player2);


		Player1.sprite.setPosition(Player1.currentPosition);
		Player2.sprite.setPosition(Player2.currentPosition);

		if(wallMap1.checkCollision(Player1.sprite)){
			Player1.currentPosition = Player1.lastPosition;
		}



		window->clear();

		window->draw(Mapa1);
		window->draw(Player1.sprite);
		window->draw(Player2.sprite);
		window->draw(wallMap1.shape);

		cout << "currentPosition (" << Player1.currentPosition.x << ", " << Player1.currentPosition.y << ")" << endl;
		cout << "lastPosition (" << Player1.lastPosition.x << ", " << Player1.lastPosition.y << ")" << endl;

		window->display();
		sf::sleep(sf::milliseconds(20.0f)); //Aguarda.
	}

	return 0;
}
