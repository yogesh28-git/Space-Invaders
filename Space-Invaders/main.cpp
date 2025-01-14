
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //sf::RenderWindow window(sf::VideoMode(800,800), "SFML Works !!");
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Resizable Window", sf::Style::Resize | sf::Style::Close);
    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fullscreen Window", sf::Style::Fullscreen | sf::Style::Close);


    sf::Texture outscal_logo_tex;
    if (!outscal_logo_tex.loadFromFile("assets/textures/outscal_logo.png"))
    {
        std::cout<<"Texture did not load";
    }
    sf::Sprite outscal_logo;
    outscal_logo.setTexture(outscal_logo_tex);
    outscal_logo.setPosition(10, 10);

    sf::Font font;
    font.loadFromFile("assets/fonts/bubbleBobble.ttf");

    sf::Text text("Hello Fucking World!!", font, 50);
    text.setPosition(10, 150);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(outscal_logo);
        window.draw(text);
        window.display();
    }
    
    return 0;
}