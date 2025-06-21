#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "C_RandomNum/C_RandomNum.h"
// using namespace sf;

constexpr int HEIGHT = 512;
constexpr int WIDTH = 288;
constexpr float SPEED = 1.f;
constexpr float G = 9.8f;


int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Flappy Bird");
    window.setFramerateLimit(60);
    sf::Clock clock;

    float bg_move_x = 0 - WIDTH;
    float bg_move_x2 = 0.f;

    float timer = 0.f;
    float v0 = 0.f;
    float bird_x = 30.f;
    float bird_y = 200.f;
    float bird_y_dy = 0.f;

    float pipe_dx = 120.f;
    float pipe_x = 100.f;
    float pipe_x2 = pipe_x + pipe_dx;
    float pipe_x3 = pipe_x2 + pipe_dx;
    int pipe_position = -222;
    int pipe_down_y = RandomNum::range(pipe_position, 0);
    int pipe_up_y = 450 + pipe_down_y;
    int pipe_down_y2 = RandomNum::range(pipe_position, 0);
    int pipe_up_y2 = 450 + pipe_down_y2;
    int pipe_down_y3 = RandomNum::range(pipe_position, 0);
    int pipe_up_y3 = 450 + pipe_down_y3;

    const sf::Texture bg_day("../resource/bg_day.png");
    const sf::Texture bird("../resource/bird0_0.png");
    const sf::Texture pipe_up("../resource/pipe_up.png");
    const sf::Texture pipe_down("../resource/pipe_down.png");

    sf::Sprite bg_day_sprite(bg_day);
    sf::Sprite bg_day_sprite2(bg_day);
    sf::Sprite bird_sprite(bird);
    sf::Sprite pipe_down_sprite(pipe_down);
    sf::Sprite pipe_up_sprite(pipe_up);
    sf::Sprite pipe_down_sprite2(pipe_down);
    sf::Sprite pipe_up_sprite2(pipe_up);
    sf::Sprite pipe_down_sprite3(pipe_down);
    sf::Sprite pipe_up_sprite3(pipe_up);


    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
            else if (event->is<sf::Event::KeyPressed>()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                    v0 = -4;
                    timer = 0.f;
                    bird_y_dy *= -1.9;
                };
            }
        }

        window.clear(sf::Color::Black);
        // bg_day_sprite.setTextureRect(sf::IntRect({0, 0}, {288, 512}));
        bg_day_sprite.setPosition({bg_move_x + WIDTH, 0});
        bg_day_sprite2.setPosition({bg_move_x2 + WIDTH, 0});
        bird_sprite.setPosition({bird_x, bird_y});
        pipe_down_sprite.setPosition({pipe_x, static_cast<float>(pipe_down_y)});
        pipe_up_sprite.setPosition({pipe_x, static_cast<float>(pipe_up_y)});
        pipe_down_sprite2.setPosition({pipe_x2, static_cast<float>(pipe_down_y2)});
        pipe_up_sprite2.setPosition({pipe_x2, static_cast<float>(pipe_up_y2)});
        pipe_down_sprite3.setPosition({pipe_x3, static_cast<float>(pipe_down_y3)});
        pipe_up_sprite3.setPosition({pipe_x3, static_cast<float>(pipe_up_y3)});
        window.draw(bg_day_sprite);
        window.draw(bg_day_sprite2);
        window.draw(bird_sprite);
        window.draw(pipe_up_sprite);
        window.draw(pipe_down_sprite);
        window.draw(pipe_up_sprite2);
        window.draw(pipe_down_sprite2);
        window.draw(pipe_up_sprite3);
        window.draw(pipe_down_sprite3);
        window.display();

        //  让背景飞起来
        bg_move_x = std::fmod(bg_move_x, 2 * WIDTH) - SPEED;
        bg_move_x2 = std::fmod(bg_move_x2, 2 * WIDTH) - SPEED;

        //  让小鸟跳起来
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        bird_y_dy = (v0 * timer + 0.5f * G * timer * timer)*1.6f;
        std::cout << bird_y_dy << std::endl;
        bird_y += bird_y_dy;

        //  让水管飞起来
        pipe_x -= SPEED;
        pipe_x2 -= SPEED;
        pipe_x3 -= SPEED;
        if (pipe_x < -52) {
            pipe_x = pipe_x3 + pipe_dx;
            pipe_down_y = RandomNum::range(pipe_position, 0);
            pipe_up_y = 450 + pipe_down_y;
        }
        if (pipe_x2 < -52) {
            pipe_x2 = pipe_x + pipe_dx;
            pipe_down_y2 = RandomNum::range(pipe_position, 0);
            pipe_up_y2 = 450 + pipe_down_y2;
        }
        if (pipe_x3 < -52) {
            pipe_x3 = pipe_x2 + pipe_dx;
            pipe_down_y3 = RandomNum::range(pipe_position, 0);
            pipe_up_y3 = 450 + pipe_down_y3;
        }


    }


    return 0;
}
