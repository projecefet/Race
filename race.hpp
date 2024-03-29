// HPP GERAL DO JOGO

#ifndef RACE_HPP_
#define RACE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using sf::Color;
using sf::Texture;
using sf::Sprite;
using sf::Vector2f;

enum Id_Player {
	Id_Player1, Id_Player2
};

class Hitbox {
public:
	Vector2f wallPosition;
	Vector2f size;

	sf::FloatRect hitbox;
	sf::RectangleShape shape;

	bool touch = false;

	Hitbox(Vector2f wallPosition, Vector2f size) {

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

class Player {
public:

	float secondsCounter = 0;

	Sprite sprite;
	float escala;

	Vector2f currentPosition;
	Vector2f lastPosition;
	Vector2f initialPosition;

	sf::FloatRect hitbox;

	sf::Text lapText;
	int lapCounter = 1;
	vector<int> checkpointCounter = { 0, 0, 0, 0 };

	Player(Sprite &sprite, float escala, Vector2f currentPosition) {

		this->sprite = sprite;
		this->escala = escala;
		this->currentPosition = currentPosition;
		this->initialPosition = this->currentPosition;
		this->lastPosition = currentPosition;

		this->montaPlayer();
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

	void applyCollision(std::vector<Hitbox> &wallList) {
		for (int i = 0; i < wallList.size(); i++) {
			if (wallList[i].checkCollision(sprite)) {
				currentPosition = lastPosition;
			}
		}
	}

	bool checkLapCompletion(vector<Hitbox> *checkpoints,
			float *secondsCounter) {
		int soma = 0;

		for (int i = 0; i < 4; i++) {
			if (checkpoints->at(i).checkCollision(sprite)
					&& *secondsCounter >= 1) {
				checkpointCounter[i] = 1;
			}
		}

		for (int i = 0; i < 4; i++) {
			soma += checkpointCounter[i];
		}

		if (soma == checkpointCounter.size()) {

			*secondsCounter = 0;
			for (int i = 0; i < 4; i++) {
				checkpointCounter[i] = 0;
			}
			return true;
		} else {
			return false;
		}

	}
	void zeraPlayer() {
			this->currentPosition = this->initialPosition;
			this->lapCounter = 1;
		}
};

class Coins {
private:
	sf::Texture coinTextures[6]; // Vetor para armazenar todas as texturas da moeda
	sf::Sprite spriteCoin;
	std::vector<sf::Sprite> coins;
	std::vector<sf::FloatRect> coinsHitbox;
	sf::Clock clock;
	sf::RectangleShape shape;
	std::vector<sf::RectangleShape> coinShapes;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	int currentFrame = 0;
	int c = 0;

	bool verificarValor(const vector<int> &vetor, int valor) {
		for (int elemento : vetor) {
			if (elemento == valor) {
				return true;
			}
		}
		return false;
	}
public:
	Coins() {

		// Carregar todas as texturas da moeda em um vetor
		coinTextures[0].loadFromFile("assets/coins/1.png");
		coinTextures[1].loadFromFile("assets/coins/2.png");
		coinTextures[2].loadFromFile("assets/coins/3.png");
		coinTextures[3].loadFromFile("assets/coins/4.png");
		coinTextures[4].loadFromFile("assets/coins/5.png");
		coinTextures[5].loadFromFile("assets/coins/6.png");

		// Configurar sprite da moeda
		spriteCoin.setTexture(coinTextures[c]);
		spriteCoin.setScale(0.01, 0.01); // Reduzir a escala da moeda

		// Configurar animação da moeda com menos frames
		buffer.loadFromFile("assets/sounds/mueda.wav");
		sound.setBuffer(buffer);

	}
	sf::Text qtdCoinsCollected;

	void updateAnimation() {
		std::random_device rd;
		std::mt19937 gen(rd());

		currentFrame++;
		// Atualizar a animação da moeda com intervalo maior
		if (currentFrame == 3) {
			if (c < 5) {
				c++;
			} else {
				c = 0;
			}
			currentFrame = 0;
		}
		static bool create = false;
		static const int numCoins = 10; // Reduzir o número de moedas
		vector<int> numGerados;
		coins.reserve(numCoins);

		std::mt19937 randomNumberGenerator((time(nullptr)));
		std::uniform_int_distribution<int> gap(1, 10);

		if (create == false) {
			for (int i = 0; i < numCoins; ++i) {

				sf::Sprite coinSprite(spriteCoin);

				int randomNumber = gap(randomNumberGenerator);

				if (numGerados.empty()) {
					numGerados.push_back(randomNumber);
				} else if (verificarValor(numGerados, randomNumber) == false) {
					numGerados.push_back(randomNumber);
				}

				switch (randomNumber) {
				case 1:
					coinSprite.setPosition(90, 90);
					shape.setPosition(90, 90);
					break;
				case 2:
					coinSprite.setPosition(130, 330);
					shape.setPosition(130, 330);
					break;
				case 3:
					coinSprite.setPosition(500, 90);
					shape.setPosition(500, 90);
					break;
				case 4:
					coinSprite.setPosition(750, 130);
					shape.setPosition(750, 130);
					break;
				case 5:
					coinSprite.setPosition(850, 300);
					shape.setPosition(850, 300);
					break;
				case 6:
					coinSprite.setPosition(320, 130);
					shape.setPosition(320, 130);
					break;
				case 7:
					coinSprite.setPosition(390, 400);
					shape.setPosition(390, 400);
					break;
				case 8:
					coinSprite.setPosition(700, 445);
					shape.setPosition(700, 445);
					break;
				case 9:
					coinSprite.setPosition(150, 445);
					shape.setPosition(150, 445);
					break;
				case 10:
					coinSprite.setPosition(810, 400);
					shape.setPosition(810, 400);
					break;
				}

				shape.setFillColor(Color::Transparent);
				shape.setSize(Vector2f(20, 20));

				coinShapes.push_back(shape);

				coinsHitbox.push_back(shape.getLocalBounds());

				coins.push_back(coinSprite);



			}
			create = true;
		}

		for (int i = 0; i < numCoins; ++i) {
			coins[i].setTexture(coinTextures[c], true);
		}

	}

	void areGet(Player *player, int (&coinsLeft)[10]) {

		sf::FloatRect rect1 = player->sprite.getGlobalBounds();

		for (int i = 0; i < coinsHitbox.size(); i++) {
			if (rect1.contains(coinShapes[i].getPosition())) {
				coinShapes.at(i).setPosition(0, 0);
				this->sound.play();
				coinsLeft[i] = 0;
			}
		}
	}

	int coinsCollected(int (&coinsLeft)[10]) {
		int qtdCoinsLeft;
		int qtdCoinsCollected;
		for (int i = 0; i < 10; i++) {
			qtdCoinsLeft += coinsLeft[i];
		}
		qtdCoinsCollected = 10 - qtdCoinsLeft;
		return qtdCoinsCollected;
	}

	void drawCoins(sf::RenderWindow *window, Player *player1, Player *player2,
			int (&coinsLeft)[10]) {
		for (int i = 0; i < coins.size(); i++) {

			areGet(player1, coinsLeft);
			areGet(player2, coinsLeft);

			if (coinsLeft[i] != 0) {
				window->draw(coinShapes.at(i));
				window->draw(coins[i]);
			}

		}
	}

};

#endif
