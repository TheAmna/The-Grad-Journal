#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
private:
    sf::RectangleShape paddle;
    float speed;
    
public:
    Player(float x, float y, float width, float height) {
        paddle.setSize(sf::Vector2f(width, height));
        paddle.setFillColor(sf::Color::Green);
        paddle.setPosition(x, y);
        speed = 0.8f;
    }    
    void moveLeft() {
        sf::Vector2f pos = paddle.getPosition();
        if (pos.x > 0) {
            paddle.move(-speed, 0);
        }
    }
    void moveRight() {
        sf::Vector2f pos = paddle.getPosition();
        if (pos.x + paddle.getSize().x < 400) {
            paddle.move(speed, 0);
        }
    }
    sf::FloatRect getBounds() {
        return paddle.getGlobalBounds();
    }
    void draw(sf::RenderWindow& window) {
        window.draw(paddle);
    }
    void setPosition(float x, float y) {
        paddle.setPosition(x, y);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Paddle Ball Game");
    sf::CircleShape ball(20);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(100, 100);
    sf::Vector2f velocity(0.05f, 0.05f);
    Player player(160, 280, 80, 10);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }
    
    sf::Text messageText;
    messageText.setFont(font);
    messageText.setString("Press Space bar to continue");
    messageText.setCharacterSize(18);
    messageText.setFillColor(sf::Color::Red);

    sf::FloatRect textBounds = messageText.getLocalBounds();
    messageText.setOrigin(textBounds.left + textBounds.width / 2.0f, 
                         textBounds.top + textBounds.height / 2.0f);
    messageText.setPosition(400 / 2.0f, 200);
    
    bool gamePaused = false;
    bool showMessage = false;
    sf::Vector2f initialBallPosition(100, 100);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (showMessage) {
                    showMessage = false;
                    gamePaused = false;
                    // reset intial pos and velocity
                    ball.setPosition(initialBallPosition);
                    velocity = sf::Vector2f(0.05f, 0.05f);
                }
            }
        }
        if (!gamePaused) {  // handle keyboard movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                player.moveLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                player.moveRight();
            }
        }
        if (!gamePaused) {
            ball.move(velocity);

            sf::Vector2f position = ball.getPosition();
            if (position.x <= 0 || position.x + ball.getRadius() * 2 >= 400) {
                velocity.x = -velocity.x;
            }
            if (position.y <= 0) {
                velocity.y = -velocity.y;
            }
            if (position.y + ball.getRadius() * 2 >= 300) {
                gamePaused = true;
                showMessage = true;
            }
            sf::FloatRect ballBounds = ball.getGlobalBounds();
            sf::FloatRect paddleBounds = player.getBounds();
            if (ballBounds.intersects(paddleBounds)) {
                velocity.y = -velocity.y;
                float ballCenterX = ballBounds.left + ballBounds.width / 2;
                float paddleCenterX = paddleBounds.left + paddleBounds.width / 2;
                float hitPosition = (ballCenterX - paddleCenterX) / (paddleBounds.width / 2);
                velocity.x = hitPosition * 0.05f; 
            }
        }
        window.clear();
        window.draw(ball);
        player.draw(window);
        if (showMessage) {
            window.draw(messageText);
        }
        window.display();
    }
    return 0;
}