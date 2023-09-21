#include "classGameCore.hpp"
#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>

using namespace sf;

void GameCore::draw() {
    window->clear();
    entity->createSprite(sprite);
    // entity->getPosition(sprite);
    // entity->getPosition(sprite);
    window->draw(*sprite);
    sprite = move->moving(sprite);
    sprite = move->gravity(sprite);
    window->display();
}

void GameCore::start() {
    while (window->isOpen()) {
       while (window->pollEvent(*event)) {
             if (event->type == Event::Closed) {
                 window->close();
             }
              draw();
        }
    }

}

GameCore::~GameCore() {
    delete window;
    delete event;
    delete move;
    delete entity;
    delete sprite;
}

GameCore::GameCore(int weight, int height) {
    window = new RenderWindow(VideoMode(weight, height),"FlyBall");
    event = new Event();
    move = new Move();
    sprite = new Sprite();
    window->setFramerateLimit(60);
}


