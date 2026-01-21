
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "STOP Sign");
    float circleRadius = 80;
    float borderThickness = 20;
    sf::CircleShape circle(circleRadius);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineThickness(borderThickness);
    circle.setOutlineColor(sf::Color::Red);
    circle.setPosition(200 - circleRadius, 30);
    sf::RectangleShape post(sf::Vector2f(30, 200));
    post.setFillColor(sf::Color::Black);
    post.setPosition((400 - 30) / 2.0f, 100);

    // text part 
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }
    sf::Text text;
    text.setFont(font);                
    text.setString("STOP");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);

    sf::FloatRect textBox = text.getLocalBounds();
    text.setOrigin(textBox.left + textBox.width / 2.0f, textBox.top + textBox.height / 2.0f);
    text.setPosition(400 / 2.0f, 30 + circleRadius);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Cyan);
        window.draw(post);
        window.draw(circle);
        window.draw(text);
        window.display();
    }

    return 0;
}
