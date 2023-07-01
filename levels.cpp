// TELA DOS NIVEIS 

#include "levels.hpp"

Levels::Levels () {
	this->backgroundTexture.loadFromFile("assets/levels/fundolevels.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
}
Levels::~Levels () {}

void Levels::render(sf::RenderWindow *window) {
	window->draw(this->backgroundSprite);
}

// Star Button
StarButton::StarButton (int stars, sf::Vector2f initialPos, int btnNum) {
	this->buttonTexture.loadFromFile("assets/levels/" + std::to_string(stars) + "star.png");
	this->buttonSprite.setTexture(this->buttonTexture);
	this->buttonSprite.setScale(sf::Vector2f(0.20, 0.20));

	this->phaseNumTexture.loadFromFile("assets/levels/" + std::to_string(btnNum) + ".png");
	this->phaseNumSprite.setTexture(this->phaseNumTexture);

	this->phaseNumSprite.setPosition(initialPos);
	this->phaseNumSprite.setScale(sf::Vector2f(0.20, 0.20));

	this->buttonSprite.setPosition(initialPos);
}

StarButton::~StarButton () {}

void StarButton::render(sf::RenderWindow *window) {
	window->draw(this->buttonSprite);
	window->draw(this->phaseNumSprite);
}
