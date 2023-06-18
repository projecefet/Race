/*
 * header.hpp
 *
 *  Created on: 15 de jun. de 2023
 *      Author: ottin
 */

#ifndef RACE_HPP_
#define RACE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using sf::Color;
using sf::Texture;
using sf::Sprite;
using sf::Vector2f;

int jogo(sf::RenderWindow *window);

class Wall {
public:
	Vector2f wallPosition;
	Vector2f size;

	sf::FloatRect hitbox;
	sf::RectangleShape shape;

	Wall(Vector2f wallPosition, Vector2f size) {

		this->wallPosition = wallPosition;
		this->size = size;

		shape.setSize(size);
		shape.setFillColor(Color::Blue);
		shape.setPosition(wallPosition);

		hitbox = shape.getGlobalBounds();

	}

	bool checkCollision(const sf::Sprite &sprite1) {
		sf::FloatRect rect1 = sprite1.getGlobalBounds();
		return hitbox.intersects(rect1);
	}

};

enum Id_Player {
	Id_Player1, Id_Player2
};

class Player {
public:

	Sprite sprite;
	float escala;
	Vector2f currentPosition;
	Vector2f lastPosition;
	sf::FloatRect hitbox;
	bool touch;

	Player(Sprite &sprite, float escala, Vector2f currentPosition) {

		this->sprite = sprite;
		this->escala = escala;
		this->currentPosition = currentPosition;
		this->lastPosition = currentPosition;

	}

	void montaPlayer() {
		hitbox = sprite.getLocalBounds();

		sprite.setOrigin(hitbox.width / 2, hitbox.height / 2);
		sprite.setScale(escala, escala);
		sprite.setPosition(currentPosition);
	}

	void moveByPressing(Id_Player Id_Player) {
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
			}
			break;

		case Id_Player2:

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				currentPosition.y = currentPosition.y - 4;
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
			}
			break;
		}
	}

	void setRotation(Id_Player Id_Player) {
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
	void applyColision(std::vector<Wall> &wallList) {
		if (wallList[0].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}
		if (wallList[1].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}

		if (wallList[2].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}
		if (wallList[3].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}

		if (wallList[4].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}
		if (wallList[5].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}

		if (wallList[6].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}
		if (wallList[7].checkCollision(sprite)) {
			currentPosition = lastPosition;
		}
	}

};



#endif /* RACE_HPP_ */
