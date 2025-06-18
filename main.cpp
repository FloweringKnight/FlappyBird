#include <iostream>
#include <SFML/Graphics.hpp>
// using namespace sf;

constexpr int HEIGHT = 512;
constexpr int WIDTH = 280;


int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Flappy Bird");
    window.setFramerateLimit(60);

    const sf::Texture bg_day("../resource/bg_day.png");
    const sf::Texture bird("../resource/bird0_0.png");
    const sf::Texture pipe_up("../resource/pipe_up.png");
    const sf::Texture pipe_down("../resource/pipe_down.png");

    sf::Sprite bg_day_sprite(bg_day);
    sf::Sprite bird_sprite(bird);
    sf::Sprite pipe_up_sprite(pipe_up);
    sf::Sprite pipe_down_sprite(pipe_down);

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
            else if (event->is<sf::Event::KeyPressed>()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                    continue;
                };
            }
        }

        window.clear(sf::Color::Black);
        bg_day_sprite.setTextureRect(sf::IntRect({0, 0}, {282, 512}));
        bird_sprite.setPosition({10 , 240});
        pipe_up_sprite.setPosition({150, 300});
        pipe_down_sprite.setPosition({150, -150});
        window.draw(bg_day_sprite);
        window.draw(bird_sprite);
        window.draw(pipe_up_sprite);
        window.draw(pipe_down_sprite);
        window.display();




    }


    return 0;
}
