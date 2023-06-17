// CODIGO DA TELA INICIAL

#include "race.hpp"

int main() {
	bool click, keygame;
	click = false;

	sf::RenderWindow window(sf::VideoMode(960, 540), "MARIO KART: Super Circuit",
			sf::Style::Titlebar | sf::Style::Close);
	sf::Texture imagem;
	sf::Sprite fundo;
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;

	imagem.loadFromFile("assets/menu.png");
	fundo.setTexture(imagem);
	mouseplay.setSize(sf::Vector2f(440, 287));
	mouseplay.setPosition(356, 115);
	sf::Image image = sf::Image { };

	image.loadFromFile("assets/icon.png");
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	while (window.isOpen()) {
		sf::Event event;
		leituramouse = sf::Mouse::getPosition(window);
		cordenadatual = window.mapPixelToCoords(leituramouse);

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && click == false) {
				click = true;
			}
		}

		if (click == true) {
			if (mouseplay.getGlobalBounds().contains(cordenadatual)) {
				keygame = true;

			}
			click = false;
		}

		if (keygame == true) {

			jogo(&window);
		}

		window.clear();
		window.draw(fundo);

		window.display();
	}

	return 0;
}
