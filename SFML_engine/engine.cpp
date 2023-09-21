#include "engine.hpp"
#include <iostream>

Engine::Engine() {
    Vector2f position;
    position.x = VideoMode::getDesktopMode().width;
    position.y = VideoMode::getDesktopMode().height;
    std::cout<< position.y << std::endl;
    std::cout<< position.y << std::endl;

    window.create(VideoMode(1600,1000),"Game",Style::Fullscreen);
    backGroundTexture.loadFromFile("/Users/artem/Cplusplus/SFML_engine/texturs/show.png");
    backGroundSprite.setTexture(backGroundTexture);
}

void Engine::start() {
    Clock clock;

    while (window.isOpen()) {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}
