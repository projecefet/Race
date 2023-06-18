#include "race.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using sf::Color;
using sf::Texture;
using sf::Sprite;
using sf::Vector2f;

int jogo(sf::RenderWindow *window) {

	window->setFramerateLimit(60);

	Texture texturaMapa;
	texturaMapa.loadFromFile("assets/mapas/1.png");
	Sprite Mapa1;
	Mapa1.setTexture(texturaMapa);

	Texture texturaMario;
	texturaMario.loadFromFile("assets/carros/mario.png");
	Sprite Mario;
	Mario.setTexture(texturaMario);

	float escala = 1.3;

	Vector2f currentPositionPlayer1(144, 300);
	Player Player1(Mario, escala, currentPositionPlayer1);
	Player1.montaPlayer();

	Texture texturaPeach;
	texturaPeach.loadFromFile("assets/carros/bowser.png");
	Sprite Peach;
	Peach.setTexture(texturaPeach);

	Vector2f currentPositionPlayer2(100, 300);
	Player Player2(Peach, escala, currentPositionPlayer2);
	Player2.montaPlayer();

	Wall map1_wall1(Vector2f(180, 365), Vector2f(600, 10));
	Wall map1_wall2(Vector2f(180, 178), Vector2f(600, 10));
	Wall map1_wall3(Vector2f(180, 178), Vector2f(10, 195));
	Wall map1_wall4(Vector2f(770, 178), Vector2f(10, 195));
	Wall map1_wall5(Vector2f(55, 50), Vector2f(10, 450));
	Wall map1_wall6(Vector2f(55, 50), Vector2f(850, 10));
	Wall map1_wall7(Vector2f(900, 50), Vector2f(10, 450));
	Wall map1_wall8(Vector2f(55, 490), Vector2f(850, 10));

	std::vector<Wall> wallList_map1;
	wallList_map1.push_back(map1_wall1);
	wallList_map1.push_back(map1_wall2);
	wallList_map1.push_back(map1_wall3);
	wallList_map1.push_back(map1_wall4);
	wallList_map1.push_back(map1_wall5);
	wallList_map1.push_back(map1_wall6);
	wallList_map1.push_back(map1_wall7);
	wallList_map1.push_back(map1_wall8);

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

		Player1.applyColision(wallList_map1);
		Player2.applyColision(wallList_map1);

		window->clear();

		window->draw(map1_wall1.shape);
		window->draw(map1_wall2.shape);
		window->draw(map1_wall3.shape);
		window->draw(map1_wall4.shape);
		window->draw(map1_wall5.shape);
		window->draw(map1_wall6.shape);
		window->draw(map1_wall7.shape);
		window->draw(map1_wall8.shape);

		window->draw(Mapa1);
		window->draw(Player1.sprite);
		window->draw(Player2.sprite);

		window->display();
		sf::sleep(sf::milliseconds(20.0f)); //Aguarda.
	}

	return 0;
}
