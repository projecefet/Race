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
enum personagem {
	Personagem_Mario, Personagem_Peach
};
class Player {
public:

	Sprite sprite;
	float escala;
	Vector2f position;

	Player(Sprite &sprite, float escala, Vector2f position) {

		this->sprite = sprite;
		this->escala = escala;
		this->position = position;
	}

	void montaPlayer(Sprite &sprite) {
		sf::FloatRect bounds = sprite.getLocalBounds();

		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setScale(escala, escala);
		sprite.setPosition(position);
	}

	void setNewPosition(personagem personagem) {
		switch (personagem) {
		case Personagem_Mario:

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				position.y = position.y - 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				position.y = position.y + 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				position.x = position.x + 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				position.x = position.x - 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				position.y;
			}
			break;

		case Personagem_Peach:

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				position.y = position.y - 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				position.y = position.y + 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				position.x = position.x + 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.x = position.x - 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				position.y;
			}
			break;
		}
	}

	void setRotation(Sprite &sprite, personagem personagem) {
		switch (personagem) {
		case Personagem_Mario:
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

		case Personagem_Peach:
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
/*
 void define_Velocidade_E_Inverte_Direcao_Bola(int *velX, int *velY, int posX,
 int posY, sf::RenderWindow *window) {
 *velY = posY < window->getSize().y ? *velY : -*velY;
 *velX = posX < window->getSize().x ? *velX : -*velX;

 *velY = posY > 0 ? *velY : -*velY;
 *velX = posX > 0 ? *velX : -*velX;

 }

 void define_Posicao_Bola(int *posX, int velX, int *posY, int velY,
 float tempo) {
 *posX = *posX + velX * tempo;
 *posY = *posY + velY * tempo;
 }

 int define_Caracteristicas_Origem_Bola(sf::CircleShape shapeBola, int tamanho,
 int posX, int posY) {

 shapeBola.setOrigin(tamanho / 2, tamanho / 2);
 shapeBola.setPosition(posX, posY);

 return 0;
 }

 */
int main() {

	sf::RenderWindow window(sf::VideoMode(960, 540), "RACE",
			sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	float tempo = 1.0;

	Texture texturaMario;
	texturaMario.loadFromFile("assets/carros/mario.png");
	Sprite Mario;
	Mario.setTexture(texturaMario);

	float escala = 1.5;

	Vector2f positionMario(window.getSize().x / 2, window.getSize().y / 2);
	Player Player1(Mario, escala, positionMario);
	Player1.montaPlayer(Mario);

	Texture texturaPeach;
	texturaPeach.loadFromFile("assets/carros/peach.png");
	Sprite Peach;
	Peach.setTexture(texturaPeach);

	Vector2f positionPeach(window.getSize().x / 3, window.getSize().y / 3);
	Player Player2(Peach, escala, positionPeach);
	Player2.montaPlayer(Peach);

	/*

	 Retangulo retangulo1(50, window.getSize().x / 2, window.getSize().y / 2,
	 Color::Cyan);
	 sf::RectangleShape shapeRetangulo1;
	 shapeRetangulo1.setSize(Vector2f(200, 100));
	 shapeRetangulo1.setFillColor(retangulo1.cor);
	 shapeRetangulo1.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	 shapeRetangulo1.setOrigin(shapeRetangulo1.getSize().x / 2,
	 shapeRetangulo1.getSize().y / 2);

	 Bolinha bola1;
	 bola1.posX = window.getSize().x / 4;
	 bola1.posY = window.getSize().y / 4;
	 bola1.velX = -10, bola1.velY = 5;
	 bola1.tamanho = 20;

	 Bolinha bola2(15, window.getSize().x / 4, window.getSize().y / 4, -4, 5,
	 Color::Yellow);

	 Bolinha bola3(10, window.getSize().x / 4, window.getSize().y / 4, -5, 5,
	 Color::Magenta);

	 sf::CircleShape shapeBola1(bola1.tamanho);
	 sf::CircleShape shapeBola2(bola2.tamanho);
	 sf::CircleShape shapeBola3(bola3.tamanho);

	 define_Caracteristicas_Origem_Bola(shapeBola1, bola1.tamanho, bola1.posX,
	 bola1.posY);
	 define_Caracteristicas_Origem_Bola(shapeBola2, bola2.tamanho, bola2.posX,
	 bola2.posY);
	 define_Caracteristicas_Origem_Bola(shapeBola3, bola3.tamanho, bola3.posX,
	 bola3.posY);
	 shapeBola1.setFillColor(bola1.cor);
	 shapeBola2.setFillColor(bola2.cor);
	 shapeBola3.setFillColor(bola3.cor);
	 */

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		Player1.setNewPosition(Personagem_Mario);
		Player1.setRotation(Mario, Personagem_Mario);

		Player2.setNewPosition(Personagem_Peach);
		Player2.setRotation(Peach, Personagem_Peach);
		/*
		 sf::FloatRect hitbox1 = shapeRetangulo1.getGlobalBounds();
		 sf::FloatRect hitbox2 = shapeBola1.getGlobalBounds();
		 if (hitbox1.intersects(hitbox2)) {
		 if (bola1.velX < 0 && bola1.velY > 0) {
		 bola1.velX = -bola1.velX;
		 shapeBola1.setFillColor(Color::Red);
		 }
		 if (bola1.velX > 0 && bola1.velY < 0) {
		 bola1.velX = -bola1.velX;
		 shapeBola1.setFillColor(Color::Cyan);
		 }
		 if (bola1.velX > 0 && bola1.velY > 0) {
		 bola1.velX = -bola1.velX;
		 shapeBola1.setFillColor(Color::Green);
		 }
		 if (bola1.velX < 0 && bola1.velY < 0) {
		 bola1.velY = -bola1.velY;
		 shapeBola1.setFillColor(Color::Magenta);
		 }

		 }

		 define_Velocidade_E_Inverte_Direcao_Bola(&(bola1.velX), &(bola1.velY),
		 bola1.posX, bola1.posY, &window);

		 define_Velocidade_E_Inverte_Direcao_Bola(&(bola2.velX), &(bola2.velY),
		 bola2.posX, bola2.posY, &window);

		 define_Velocidade_E_Inverte_Direcao_Bola(&(bola3.velX), &(bola3.velY),
		 bola3.posX, bola3.posY, &window);

		 define_Posicao_Bola(&(bola1.posX), bola1.velX, &(bola1.posY),
		 bola1.velY, tempo);
		 define_Posicao_Bola(&(bola2.posX), bola2.velX, &(bola2.posY),
		 bola2.velY, tempo);
		 define_Posicao_Bola(&(bola3.posX), bola3.velX, &(bola3.posY),
		 bola3.velY, tempo);

		 shapeBola1.setPosition(bola1.posX, bola1.posY);
		 shapeBola2.setPosition(bola2.posX, bola2.posY);
		 shapeBola3.setPosition(bola3.posX, bola3.posY);
		 */

		Mario.setPosition(Player1.position);
		Peach.setPosition(Player2.position);

		window.clear();
		//window.draw(shapeBola1);
		//window.draw(shapeBola2);
		//window.draw(shapeBola3);
		window.draw(Mario);
		window.draw(Peach);
		//window.draw(shapeRetangulo1);
		window.display();
		sf::sleep(sf::milliseconds(20.0f)); //Aguarda.
	}

	return 0;
}
