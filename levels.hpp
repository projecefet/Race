// TELA DE NIVEIS - HPP

#ifndef LEVELS_HPP_
#define LEVELS_HPP_

#include <SFML/Graphics.hpp>

class Levels {
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

public:
	// Constructors / Destructors
	Levels();
	~Levels();

	//Funções
	void render(sf::RenderWindow *window);
};

class StarButton {
private:
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;

	sf::Texture phaseNumTexture;
	sf::Sprite phaseNumSprite;

public:
	StarButton(int stars, sf::Vector2f initialPos, int btnNum);
	~StarButton();

	void render(sf::RenderWindow *window);
};

#endif
