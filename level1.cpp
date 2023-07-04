// PRIMEIRA FASE - CPP

#include "level1.hpp"

//#include "wins.hpp"

bool level1(sf::RenderWindow *window, int *frameCounter_Player1,
		int *frameCounter_Player2, int *janelaControle) {
	Texture texturaMapa;
	texturaMapa.loadFromFile("assets/maps/1.png");
	Sprite Mapa1;
	Mapa1.setTexture(texturaMapa);

	Texture texturaPlayer1;
	texturaPlayer1.loadFromFile("assets/cars/mario.png");
	Sprite spritePlayer1;
	spritePlayer1.setTexture(texturaPlayer1);

	float escala = 1.3;

	Vector2f currentPositionPlayer1(144, 250);
	static Player Player1(spritePlayer1, escala, currentPositionPlayer1);
	Player1.secondsCounter = *frameCounter_Player1 / 60;

	Texture texturaPlayer2;
	texturaPlayer2.loadFromFile("assets/cars/bowser.png");
	Sprite spritePlayer2;
	spritePlayer2.setTexture(texturaPlayer2);

	Vector2f currentPositionPlayer2(100, 250);
	static Player Player2(spritePlayer2, escala, currentPositionPlayer2);
	Player2.secondsCounter = *frameCounter_Player2 / 60;

	sf::Font font;
	font.loadFromFile("assets/text/arial.ttf");

	Player1.lapText.setFont(font);
	Player1.lapText.setCharacterSize(40);
	Player1.lapText.setFillColor(Color::White);
	Player1.lapText.setPosition(20, 2);

	Player2.lapText.setFont(font);
	Player2.lapText.setCharacterSize(40);
	Player2.lapText.setFillColor(Color::White);
	Player2.lapText.setPosition(740, 2);


	static Coins coins;

	std::vector<Hitbox> wallList_mapl = { Hitbox(Vector2f(180, 365),
			Vector2f(600, 10)), Hitbox(Vector2f(180, 178), Vector2f(600, 10)),
			Hitbox(Vector2f(180, 178), Vector2f(10, 195)), Hitbox(
					Vector2f(770, 178), Vector2f(10, 195)), Hitbox(
					Vector2f(55, 50), Vector2f(10, 450)), Hitbox(
					Vector2f(55, 50), Vector2f(850, 10)), Hitbox(
					Vector2f(900, 50), Vector2f(10, 450)), Hitbox(
					Vector2f(55, 490), Vector2f(850, 10)) };

	std::vector<Hitbox> checkpoints = { Hitbox(Vector2f(70, 270),
			Vector2f(100, 10)), Hitbox(Vector2f(480, 60), Vector2f(10, 120)),
			Hitbox(Vector2f(790, 270), Vector2f(100, 10)), Hitbox(
					Vector2f(480, 380), Vector2f(10, 120)) };

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

	//coins.areGet(Player1);

	if (Player1.checkLapCompletion(&checkpoints, &Player1.secondsCounter)) {
		Player1.lapCounter++;
		*frameCounter_Player1 = 0;
		Player1.secondsCounter = 0;
	}

	if (Player2.checkLapCompletion(&checkpoints, &Player2.secondsCounter)) {
		Player2.lapCounter++;
		*frameCounter_Player2 = 0;
		Player2.secondsCounter = 0;
	}

	Player1.lapText.setString(
			"P 1 Lap " + std::to_string(Player1.lapCounter) + " / 3");
			if (Player1.lapCounter > 3){
				*janelaControle = 3;
				Player1.zeraPlayer();
				Player2.zeraPlayer();
			}
	Player2.lapText.setString(
			"P 2 Lap " + std::to_string(Player2.lapCounter) + " / 3");
			if (Player2.lapCounter > 3){
				*janelaControle = 4;
				Player2.zeraPlayer();
				Player1.zeraPlayer();
			}
			std:cout << Player2.lapCounter << "\n";


	for (int i = 0; i < wallList_mapl.size(); i++) {
		window->draw(wallList_mapl.at(i).shape);
	}

	for (int i = 0; i < wallList_mapl.size(); i++) {
		window->draw(wallList_mapl.at(i).shape);
	}
	for (int i = 0; i < checkpoints.size(); i++) {
		window->draw(checkpoints.at(i).shape);
	}

	window->draw(Mapa1);
	window->draw(Player1.sprite);
	window->draw(Player2.sprite);
	window->draw(Player1.lapText);
	window->draw(Player2.lapText);

	coins.drawCoins(window);
	coins.updateAnimation();

	return false;
}
