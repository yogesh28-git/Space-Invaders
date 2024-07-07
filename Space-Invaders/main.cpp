#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow window(videoMode, "Space-Invaders");
    window.setFramerateLimit(60);

    // Image
    sf::Texture outscal_logo;
    if (!outscal_logo.loadFromFile("assets/textures/outscal_logo.png"))
    {
        printf("Cannot load image");
        return 0;
    }
  
    sf::Sprite outscalSprite(outscal_logo);
    outscalSprite.setScale(0.5, 0.5);
    outscalSprite.setRotation(-45);
    outscalSprite.setPosition(100, 300);

    // Text
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/bubbleBobble.ttf"))
    {
        printf("Cannot load image");
        return 0;
    }
    sf::Text text("SFML is Awesome", font, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(outscalSprite);
        window.draw(text);

        window.display();
    }

    return 0;
}