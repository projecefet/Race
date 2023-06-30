#include "level1.hpp"


int level1 (sf::RenderWindow *window) {

	Texture texturaMapa;
	texturaMapa.loadFromFile("assets/maps/1.png");
	Sprite Mapa1;
	Mapa1.setTexture(texturaMapa);

	Texture texturaPlayer1;
	texturaPlayer1.loadFromFile("assets/cars/mario.png");
	Sprite spritePlayer1;
	spritePlayer1.setTexture(texturaPlayer1);

	float escala = 1.3;

	Vector2f currentPositionPlayer1(144, 300);
	static Player Player1(spritePlayer1, escala, currentPositionPlayer1);

	Texture texturaPlayer2;
	texturaPlayer2.loadFromFile("assets/cars/peach.png");
	Sprite spritePlayer2;
	spritePlayer2.setTexture(texturaPlayer2);

	Vector2f currentPositionPlayer2(100, 300);
	static Player Player2(spritePlayer2, escala, currentPositionPlayer2);

	std::vector<Wall> wallList_mapl = {
		Wall (Vector2f(180, 365), Vector2f(600, 10)),
		Wall (Vector2f(180, 178), Vector2f(600, 10)),
		Wall (Vector2f(180, 178), Vector2f(10, 195)),
		Wall (Vector2f(770, 178), Vector2f(10, 195)),
		Wall (Vector2f(55, 50), Vector2f(10, 450)),
		Wall (Vector2f(55, 50), Vector2f(850, 10)),
		Wall (Vector2f(900, 50), Vector2f(10, 450)),
		Wall (Vector2f(55, 490), Vector2f(850, 10))
	};

	Player1.lastPosition = Player1.currentPosition;
	Player2.lastPosition = Player2.currentPosition;

	Player1.moveByPressing(Id_Player1);
	Player1.setRotation(Id_Player1);

	Player2.moveByPressing(Id_Player2);
	Player2.setRotation(Id_Player2);

	Player1.sprite.setPosition(Player1.currentPosition);
	Player2.sprite.setPosition(Player2.currentPosition);

	Player1.applyCollision(wallList_mapl);
	Player2.applyCollision(wallList_mapl);

	for (int i = 0; i <= wallList_mapl.size() - 1; i++){
		window->draw(wallList_mapl.at(i).shape);
	}

	window->draw(Mapa1);
	window->draw(Player1.sprite);
	window->draw(Player2.sprite);

	return 0;
}
