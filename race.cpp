#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 540), "Mario Kart: Super Circuit",
                            sf::Style::Titlebar | sf::Style::Close);

    sf::Image image;
    image.loadFromFile("imagens/icon.png");
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
