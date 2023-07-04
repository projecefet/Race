//CODIGO DA TELA DO BOWSER
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;


void tocarmusica(Music mus){
	if (!musica.openFromFile("wins.wav")) {
        	cout << "Erro ao carregar o arquivo de música" << std::endl;
        return -1;
    	}
	music.play();
	music.setLoop(false);
	music.setVolume(20.0f);
}

void telabowser(sf::RenderWindow *window, int *janelaControle){
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;
   	sf::Texture texture;
    	sf::Sprite image;
	

    texture.loadFromFile("bowser.png");
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

//CODIGO DA TELA DO MARIO
void telamario(sf::RenderWindow *window, int *janelaControle){
	sf::RectangleShape mouseplay;
	sf::Vector2i leituramouse;
	sf::Vector2f cordenadatual;
    sf::Texture texture;
    sf::Sprite image;

    texture.loadFromFile("mario.png");
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
