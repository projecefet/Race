
// Levels class

#include "levels.hpp"

Levels::Levels () {
	this->backgroundTexture.loadFromFile("assets/nivel/fundolevels.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
}
Levels::~Levels () {}

void Levels::render(sf::RenderWindow *window) {
	window->draw(this->backgroundSprite);
}

// Star Button
StarButton::StarButton (int stars, sf::Vector2f initialPos, int btnNum) {
	this->buttonTexture.loadFromFile("assets/nivel/" + std::to_string(stars) + "star.png");
	this->buttonSprite.setTexture(this->buttonTexture);
	this->buttonSprite.setScale(sf::Vector2f(0.75, 0.75));

	this->phaseNumTexture.loadFromFile("assets/nivel/" + std::to_string(btnNum) + ".png");
	this->phaseNumSprite.setTexture(this->phaseNumTexture);

	this->phaseNumSprite.setPosition(initialPos);
	this->phaseNumSprite.setScale(sf::Vector2f(0.19, 0.19));

	this->buttonSprite.setPosition(initialPos);
}

StarButton::~StarButton () {}

void StarButton::render(sf::RenderWindow *window) {
	window->draw(this->buttonSprite);
	window->draw(this->phaseNumSprite);
}
