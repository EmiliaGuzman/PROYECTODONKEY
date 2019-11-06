#include <SFML/Graphics.hpp>
#include <iostream>
int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(235, 260), "Donkey Kong");
    sf::Event event;

    sf::Texture donkey;
    donkey.loadFromFile("donkey.gif");

    sf::Sprite kong(donkey);

    kong.setTexture(donkey);
    kong.setTextureRect(sf::IntRect(51,52,35,0));///anchopx,altura

    kong.move(50,100);

    sf::Texture texture;
    texture.loadFromFile("jumpman.gif");

    sf::Sprite sprite(texture);

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(10,0,45,23));

    sprite.move(50,100);

    sf::Texture texture1;
    texture1.loadFromFile("fondo.jpg");

    sf::Sprite background(texture1);
    background.setTexture(texture1);
    ///background.setTextureRect(sf::IntRect(0,100,0,0));

    ///background.move(100,100);
    sf::View vistaJuego= window.getDefaultView();
    vistaJuego.setViewport(sf::FloatRect(0,0,1,1));


    ///sprite.rotate(90.0f);

    kong.setScale(0.9f,0.9f);
    kong.setPosition(100.0f,200.0f);
    sprite.setScale(0.9f,0.9f);
    sprite.setPosition(20.0f,223.0f);

    ///sf::CircleShape circulo(100.f);
    ///circulo.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            ///std::cout << "D"<< std::endl;
            sprite.move(0.1f,0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite.move(-0.1f,0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sprite.move(0.0f,-0.1f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.move(0.0f,0.1f);
        }


        window.clear();
        ///window.draw(circulo);
        ///window.draw(background);
        window.setView(vistaJuego);
        window.draw(background);
        window.draw(kong);
        window.draw(sprite);

        window.display();
    }


    return 0;
}
