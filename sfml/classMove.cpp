#include <SFML/Graphics.hpp>
#include "classMove.hpp"
#include <unistd.h>
#include <thread>


Sprite* Move::moving(Sprite* sprite) {
    sf::Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
        if ((Keyboard::isKeyPressed(Keyboard::Left) &&(time < 100))) {
         sprite->move(-8,0);
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right))&&(time < 100)) {
            sprite->move(+8,0);
        }
    // }
    // while (time != 10);
    return sprite;
    }
Sprite* Move::gravity(Sprite* sprite) {
    sprite->move(0,+2);
    return sprite;
}
   // }
    //while (sleep(3));

    // switch(ev.key.code) {
    //     case Keyboard::Up:
    //         sprite.move(0,-8);
    //         break;
    //     case Keyboard::Down:
    //         sprite.move(0,+8);
    //         break;
    //     case Keyboard::Left:
    //         sprite.move(-8,0);
    //         break;
    //     case Keyboard::Right:
    //         sprite.move(+8,0);
    //         break;
    //     default:
    //         break;
    // }

