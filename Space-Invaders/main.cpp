#include <SFML/Graphics.hpp>

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    sf::Texture outscal_texture;
    outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

    sf::Sprite outscal_sprite;
    outscal_sprite.setTexture(outscal_texture);

    sf::Font font;
    font.loadFromFile("assets/fonts/OpenSans.ttf");


    // Game loop to keep the window open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Blue);


        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(300, 300); // Set position
        window.draw(circle);


        outscal_sprite.setPosition(200, 100); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.5, 0.5); // Scale factor

        window.draw(outscal_sprite);

       
        sf::Text text("Hello SFML!", font, 50);
        text.setFillColor(sf::Color::Red);
        window.draw(text);


        // Display what was drawn
        window.display();
    }

    return 0;
}