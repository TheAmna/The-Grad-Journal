#include <SFML/Graphics.hpp>

int main() {

    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow window(videoMode, "Move Rectangle with Arrow Keys");
    window.setFramerateLimit(60);
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setPosition(350.f, 275.f); 
    rectangle.setFillColor(sf::Color::Green);
    float movementSpeed = 5.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rectangle.move(0.f, -movementSpeed); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rectangle.move(0.f, movementSpeed);   
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            rectangle.move(-movementSpeed, 0.f); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            rectangle.move(movementSpeed, 0.f);
        }

        sf:: Vector2f position = rectangle.getPosition();

        float rectWidth = rectangle.getSize().x;
        float rectHeight = rectangle.getSize().y;
        float WindowWidth= static_cast<float>(videoMode.width);
        float WindowHeight = static_cast<float>(videoMode.height);

        if (position.x > WindowWidth){
            rectangle.setPosition(-rectWidth, position.y);
        }
        else if (position.x + rectWidth <0){
            rectangle.setPosition(WindowWidth, position.y);
        }

        if (position.y > WindowHeight){
            rectangle.setPosition(rectangle.getPosition().x, -rectHeight);
        }
        else if (position.y + rectHeight <0){
            rectangle.setPosition(rectangle.getPosition().x, WindowHeight);
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
