//CODIGO DA TELA DO MARIO


#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


void telamario(sf::RenderWindow *window, int *janelaControle){
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;
    sf::Texture texture;
    sf::Sprite image;

    texture.loadFromFile("assets/mario.png");
    image.setTexture(texture);
    mouseplay.setSize(sf::Vector2f(242, 72));
    mouseplay.setPosition(64, 369);
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


