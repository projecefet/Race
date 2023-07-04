// HPP GERAL DO JOGO

#include <SFML/Graphics.hpp>
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
	Vector2f initialPosition;
	Vector2f lastPosition;

	sf::FloatRect hitbox;

	sf::Text lapText;
	int lapCounter = 4;
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

	void zeraPlayer() {
		this->currentPosition = this->initialPosition;
		this->lapCounter = 1;
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
		for (int i = 0; i <= 7; i++) {
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
};

class Coins {
private:
	sf::Texture coinTextures[6]; // Vetor para armazenar todas as texturas da moeda
	sf::Sprite spriteCoin;
	std::vector<sf::Sprite> coins;
	std::vector<sf::FloatRect> coinsFloatRect;
	sf::Clock clock;
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

	}

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

		int randomNumber = gap(randomNumberGenerator);

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
					break;
				case 2:
					coinSprite.setPosition(130, 300);
					break;
				case 3:
					coinSprite.setPosition(500, 90);
					break;
				case 4:
					coinSprite.setPosition(750, 130);
					break;
				case 5:
					coinSprite.setPosition(850, 300);
					break;
				case 6:
					coinSprite.setPosition(320, 130);
					break;
				case 7:
					coinSprite.setPosition(430, 400);
					break;
				case 8:
					coinSprite.setPosition(700, 445);
					break;
				case 9:
					coinSprite.setPosition(150, 445);
					break;
				case 10:
					coinSprite.setPosition(810, 400);
					break;
				}

				coins.push_back(coinSprite);
				sf::FloatRect hitbox = coinSprite.getLocalBounds();
				coinsFloatRect.push_back(hitbox);

			}
			create = true;
		}

		for (int i = 0; i < numCoins; ++i) {
			coins[i].setTexture(coinTextures[c], true);
		}
	}

	bool areGet(Player player) {
		for (int i = 0; i < coinsFloatRect.size(); i++) {
			if (player.hitbox.intersects(coinsFloatRect.at(i))) {
				cout << "encostou";
				coins.erase(coins.begin() + i);
				break;

			}
		}
		return false;
	}


	void drawCoins(sf::RenderWindow *window) {
		for (int i = 0; i < coins.size(); i++) {
			window->draw(coins[i]);
		}
	}

};
