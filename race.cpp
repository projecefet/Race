//TELA DO JOGO _ FASE: 1
#include "race.hpp"
int jogo(sf::RenderWindow* window){

	window->setFramerateLimit(60);

	float tempo = 1.0;

	Texture texturaMario;
	texturaMario.loadFromFile("assets/Mario.png");
	Sprite Mario;
	Mario.setTexture(texturaMario);

	float escala = 1.5;

	Vector2f currentPositionPlayer1(window->getSize().x / 2,window->getSize().y / 2);
	Player Player1(Mario, escala, currentPositionPlayer1);
	Player1.montaPlayer(Mario);

	Texture texturaPeach;
	texturaPeach.loadFromFile("assets/Peach.png");
	Sprite Peach;
	Peach.setTexture(texturaPeach);

	Vector2f currentPositionPlayer2(window->getSize().x / 3,window->getSize().y / 3);
	Player Player2(Peach, escala, currentPositionPlayer2);
	Player2.montaPlayer(Peach);

	while (window->isOpen()) {
		sf::Event event;
		while (window-> pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window-> close();
			}
		}

		Player1.lastPosition = Player1.currentPosition;
		Player2.lastPosition = Player2.currentPosition;

		Player1.move(Id_Player1);
		Player1.setRotation(Mario, Id_Player1);

		Player2.move(Id_Player2);
		Player2.setRotation(Peach, Id_Player2);


		Mario.setPosition(Player1.currentPosition);
		Peach.setPosition(Player2.currentPosition);

		window->clear();
			//window.draw(shapeBola1);
			//window.draw(shapeBola2);
			//window.draw(shapeBola3);
			window->draw(Mario);
			window->draw(Peach);

			cout << "currentPosition (" << Player1.currentPosition.x << ", " << Player1.currentPosition.y << ")" << endl;
			cout << "lastPosition (" << Player1.lastPosition.x << ", " << Player1.lastPosition.y << ")" << endl;
			//window.draw(shapeRetangulo1);
			window->display();
			sf::sleep(sf::milliseconds(20.0f)); //Aguarda.
		}

		return 0;
	}

//EU COMENTEI O QUE JA TINHA PQ FIQUEI COM MEDO DE VC PERDER ALGO

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

 /* 
int main() {

	sf::RenderWindow window(sf::VideoMode(960, 540), "RACE",
			sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	float tempo = 1.0;

	Texture texturaMario;
	texturaMario.loadFromFile("assets/mario.png");
	Sprite Mario;
	Mario.setTexture(texturaMario);

	float escala = 1.5;

	Vector2f currentPositionPlayer1(window.getSize().x / 2,
			window.getSize().y / 2);
	Player Player1(Mario, escala, currentPositionPlayer1);
	Player1.montaPlayer(Mario);

	Texture texturaPeach;
	texturaPeach.loadFromFile("assets/peach.png");
	Sprite Peach;
	Peach.setTexture(texturaPeach);

	Vector2f currentPositionPlayer2(window.getSize().x / 3,
			window.getSize().y / 3);
	Player Player2(Peach, escala, currentPositionPlayer2);
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
	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		Player1.lastPosition = Player1.currentPosition;
		Player2.lastPosition = Player2.currentPosition;

		Player1.move(Id_Player1);
		Player1.setRotation(Mario, Id_Player1);

		Player2.move(Id_Player2);
		Player2.setRotation(Peach, Id_Player2);


		Mario.setPosition(Player1.currentPosition);
		Peach.setPosition(Player2.currentPosition);

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
		

		window.clear();
		//window.draw(shapeBola1);
		//window.draw(shapeBola2);
		//window.draw(shapeBola3);
		window.draw(Mario);
		window.draw(Peach);

		cout << "currentPosition (" << Player1.currentPosition.x << ", " << Player1.currentPosition.y << ")" << endl;
		cout << "lastPosition (" << Player1.lastPosition.x << ", " << Player1.lastPosition.y << ")" << endl;
		//window.draw(shapeRetangulo1);
		window.display();
		sf::sleep(sf::milliseconds(20.0f)); //Aguarda.
	}

	return 0;
}
*/
