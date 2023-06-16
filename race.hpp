/*
 * header.hpp
 *
 *  Created on: 15 de jun. de 2023
 *      Author: ottin
 */

#ifndef HEADER_HPP_
#define HEADER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using sf::Color;
using sf::Texture;
using sf::Sprite;
using sf::Vector2f;

/*
 class Bolinha {

 public:
 int tamanho;
 int posX, posY;
 int velY, velX;
 Color cor;

 Bolinha() {
 tamanho = 10;
 posX = 320;
 posY = 240;
 velY = -5;
 velX = 5;
 cor = Color::Blue;
 }

 Bolinha(int tamanho, int posX, int posY, int velX, int velY, Color cor) {
 this->tamanho = tamanho;
 this->posX = posX;
 this->posY = posY;
 this->velX = velX;
 this->velY = velY;
 this->cor = cor;
 }

 };

 class Retangulo {
 public:
 float tamanho;
 int posX, posY;
 Color cor;

 Retangulo(float tamanho, int posX, int posY, Color cor) {
 this->tamanho = tamanho;
 this->posX = posX;
 this->posY = posY;
 this->cor = cor;
 }
 };
 */
enum Id_Player {
	Id_Player1, Id_Player2
};

class Player {
public:

	Sprite sprite;
	float escala;
	Vector2f currentPosition;
	Vector2f lastPosition;

	Player(Sprite &sprite, float escala, Vector2f currentPosition) {

		this->sprite = sprite;
		this->escala = escala;
		this->currentPosition = currentPosition;
		this->lastPosition = currentPosition;
	}

	void montaPlayer(Sprite &sprite) {
		sf::FloatRect bounds = sprite.getLocalBounds();

		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setScale(escala, escala);
		sprite.setPosition(currentPosition);
	}

	void move(Id_Player Id_Player) {
		switch (Id_Player) {
		case Id_Player1:

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				currentPosition.y = currentPosition.y - 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				currentPosition.y = currentPosition.y + 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				currentPosition.x = currentPosition.x + 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				currentPosition.x = currentPosition.x - 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				currentPosition.y;
			}
			break;

		case Id_Player2:

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				currentPosition.y =currentPosition.y - 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				currentPosition.y = currentPosition.y + 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				currentPosition.x = currentPosition.x + 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				currentPosition.x = currentPosition.x - 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				currentPosition.y;
			}
			break;
		}
	}


	Vector2f getFramePositions(sf::RenderWindow& window, Sprite& player)
	{
	    static sf::Vector2f lastPosition;
	    sf::Vector2f currentPosition = player.getPosition();

	    lastPosition = currentPosition;

	    return lastPosition;
	}


	void setRotation(Sprite &sprite, Id_Player Id_Player) {
		switch (Id_Player) {
		case Id_Player1:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (sprite.getRotation() != 0) {
					sprite.setRotation(0);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (sprite.getRotation() != 180) {
					sprite.setRotation(180);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (sprite.getRotation() != 90) {
					sprite.setRotation(90);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (sprite.getRotation() != 270) {
					sprite.setRotation(270);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (sprite.getRotation() != 315) {
					sprite.setRotation(315);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (sprite.getRotation() != 45) {
					sprite.setRotation(45);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (sprite.getRotation() != 225) {
					sprite.setRotation(225);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (sprite.getRotation() != 135) {
					sprite.setRotation(135);
				}
			}
			break;

		case Id_Player2:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (sprite.getRotation() != 0) {
					sprite.setRotation(0);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				if (sprite.getRotation() != 180) {
					sprite.setRotation(180);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (sprite.getRotation() != 90) {
					sprite.setRotation(90);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (sprite.getRotation() != 270) {
					sprite.setRotation(270);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (sprite.getRotation() != 315) {
					sprite.setRotation(315);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (sprite.getRotation() != 45) {
					sprite.setRotation(45);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (sprite.getRotation() != 225) {
					sprite.setRotation(225);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (sprite.getRotation() != 135) {
					sprite.setRotation(135);
				}
			}
			break;
		}
	}

};

#endif /* HEADER_HPP_ */
