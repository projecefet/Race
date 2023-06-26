
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using sf::Color;
using sf::Texture;
using sf::Sprite;
using sf::Vector2f;

class Coins
{
private:
    sf::Texture textureCoin;
    sf::Sprite spriteCoin;
    std::vector<sf::Sprite> coins;
    sf::Clock clock;
    int currentFrame;

public:
    Coins()
    {
        // Carregar textura da moeda
        if (!textureCoin.loadFromFile("assets/coins/1.png"))
        {
            std::cerr << "Erro ao carregar a imagem da moeda." << std::endl;
        }

        // Configurar sprite da moeda
        spriteCoin.setTexture(textureCoin);
        spriteCoin.setScale(0.009f, 0.009f);

        // Gerar moedas aleatoriamente
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> posXDist(0, 800);
        std::uniform_int_distribution<int> posYDist(0, 600);
        const int numCoins = 10;
        coins.reserve(numCoins);
        for (int i = 0; i < numCoins; ++i)
        {
            sf::Sprite coinSprite(spriteCoin);
            coinSprite.setPosition(posXDist(gen), posYDist(gen));
            coins.push_back(coinSprite);
        }

        // Configurar animação da moeda
        currentFrame = 1;
    }

    void update()
    {
        // Atualizar a animação da moeda a cada 0.2 segundos
        if (clock.getElapsedTime().asSeconds() >= 0.2f)
        {
            std::string filename = "assets/coins/" + std::to_string(currentFrame) + ".png";
            if (!textureCoin.loadFromFile(filename))
            {
                std::cerr << "Erro ao carregar a imagem da moeda." << std::endl;
            }
            spriteCoin.setTexture(textureCoin);
            clock.restart();

            // Avançar para o próximo quadro da animação
            currentFrame++;
            if (currentFrame > 6)
            {
                currentFrame = 1;
            }
        }
    }

    void draw(sf::RenderWindow& window)
    {
        for (const auto& coin : coins)
        {
            window.draw(coin);
        }
    }
};

enum Id_Player {
    Id_Player1, Id_Player2
};

class Wall {
public:
    Vector2f wallPosition;
    Vector2f size;

    sf::FloatRect hitbox;
    sf::RectangleShape shape;

    Wall(Vector2f wallPosition, Vector2f size) {

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

    Sprite sprite;
    float escala;
    Vector2f currentPosition;
    Vector2f lastPosition;
    sf::FloatRect hitbox;
    bool touch;

    Player(Sprite &sprite, float escala, Vector2f currentPosition) {

        this->sprite = sprite;
        this->escala = escala;
        this->currentPosition = currentPosition;
        this->lastPosition = currentPosition;

        this->montaPlayer();
    }

    void montaPlayer() {
        hitbox = sprite.getLocalBounds();

        sprite.setOrigin(hitbox.width / 2, hitbox.height / 2);
        sprite.setScale(escala, escala);
        sprite.setPosition(currentPosition);
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

    void applyCollision(std::vector<Wall> &wallList) {
        for (int i = 0; i <= 7; i++) {
            if (wallList[i].checkCollision(sprite)) {
                currentPosition = lastPosition;
            }
        }
    }
};
