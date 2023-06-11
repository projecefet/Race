#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 540), "RACE TIME");  //abrir a janela
    sf::Texture texture;
    sf::Event event;

    if (!texture.loadFromFile("menuum.png")) //conferir se a imagem foi carregada
    {
        std::cout << "Erro!!!!!!!!";
        return 1;
    }

    sf::Sprite image(texture);
    image.setPosition(0, 0);

    sf::FloatRect botaoArea(440, 287, 356, 115);
    //sf::RectangleShape butao(sf::Vector2f(botaoArea.width, botaoArea.height)); //botao branco

    //butao.setPosition(botaoArea.left, botaoArea.top);
    //buttao.setFillColor(sf::Color::White);

    while (window.isOpen()){
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (botaoArea.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        texture.loadFromFile("codigotto.png");
                    }
                }
            }
        }

        window.clear();
        window.draw(image);
        //window.draw(butao);
        window.display();
    }

    return 0;
}
