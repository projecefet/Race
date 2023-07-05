// CODIGO DA TELA INICIAL
#include <SFML/Graphics.hpp>

void menu(sf::RenderWindow *window, int *janelaControle) {
	sf::Texture imagem;
	sf::Sprite fundo;
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;

	imagem.loadFromFile("assets/menu.png");
	fundo.setTexture(imagem);
	mouseplay.setSize(sf::Vector2f(365, 145));
	mouseplay.setPosition(429, 288);
	sf::Image image = sf::Image { };

	leituramouse = sf::Mouse::getPosition(*window);
	cordenadatual = window->mapPixelToCoords(leituramouse);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (mouseplay.getGlobalBounds().contains(cordenadatual)) {
			*janelaControle = 1;
		}
	}

	window->draw(fundo);
}
