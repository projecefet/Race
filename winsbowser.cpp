//CODIGO DA TELA DO BOWSER

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


void telabowser(sf::RenderWindow *window, int *janelaControle){
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;
    sf::Texture texture;
    sf::Sprite image;

    texture.loadFromFile("assets/bowser.png");
    image.setTexture(texture);
    mouseplay.setSize(sf::Vector2f(243, 72));
    mouseplay.setPosition(639, 376);
    Image image = sf::Image { };


    //sf::FloatRect botaoArea(64, 369, 242, 72);
    //sf::RectangleShape butao(sf::Vector2f(botaoArea.width, botaoArea.height)); //botao branco

    //butao.setPosition(botaoArea.left, botaoArea.top);
    //butao.setFillColor(sf::Color::White);

    leituramouse = Mouse::getPosition(*window);
    cordenadatual = window->mapPixelToCoords(leituramouse);

     if(Mouse::isButtonPressed(Mouse::Left)){
    	 if (mouseplay.getGlobalBounds().contains(cordenadatual)) {
    		 *janelaControle = 1;
         }
     }
     window->draw(image);

}

