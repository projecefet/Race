
#ifndef WINS_CPP_
#define WINS_CPP_



//#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

//CODIGO DA TELA DO BOWSER
void telabowser(sf::RenderWindow *window, int *janelaControle){

	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;
   	sf::Texture texture;
    sf::Sprite image;


    texture.loadFromFile("assets/wins/bowser.png");
    image.setTexture(texture);
    mouseplay.setSize(sf::Vector2f(243, 72));
    mouseplay.setPosition(639, 376);
    //Image image = sf::Image { };

    /*static sf::Music musica;

    	if (!musica.openFromFile("assets/sounds/wins.wav")) {
    	       std::cout << "Erro ao carregar o arquivo de música" << std::endl;
    	       return;
    	}
    	static int x =0;

    	musica.setVolume(20.0f);
    	if(x == 0){
    		musica.play();
    		x = 1;
    	}
	*/

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

//CODIGO DA TELA DO MARIO
void telamario(sf::RenderWindow *window, int *janelaControle){
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;
    sf::Texture texture;
    sf::Sprite image;

    texture.loadFromFile("assets/wins/mario.png");
    image.setTexture(texture);
    mouseplay.setSize(sf::Vector2f(242, 72));
    mouseplay.setPosition(64, 369);
    //Image image = sf::Image { };

    /*static sf::Music musica;

     	if (!musica.openFromFile("assets/sounds/wins.wav")) {
     	       std::cout << "Erro ao carregar o arquivo de música" << std::endl;
     	       return;
     	}
     	static int x =0;

     	musica.setVolume(2000.0f);
     	if(x == 0){
     		musica.play();
     		x = 1;
     	}
	*/

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


#endif /* WINS_CPP_ */
