#include "players.hpp"
Players::Players() {
    onGround = true;
    float cur = 0;
    dx = dy = 0;
    ground = 320;
    m_speed = 400;
    position.x = 500;//
    position.y = 320;
    texture.loadFromFile("/Users/artem/Cplusplus/SFML_engine/texturs/Саб_Зиро.png");
    sprite.setTexture(texture);
    sprite.setTextureRect( IntRect(0,0,250,560));
}

Players::~Players() {

}

void Players::goLeft() {
    m_LeftPressed = true;
    currentFrame += 0.003;
    if (currentFrame > 6) {
        currentFrame = 0;
    }
    if (position.y == ground) {
        sprite.setTextureRect( IntRect(250 * (int)floor(currentFrame) + 250, 0, -250, 560));//* int(currentFrame) + 250
    }
}

void Players::defaultPosition() {
    if (dx > 0)
        sprite.setTextureRect(IntRect(0,0,250,560));
    else
        sprite.setTextureRect(IntRect(250,0,-250,560));
}

void Players::stopLeft() {
    m_LeftPressed = false;
}

void Players::goRight() {
    m_RightPressed = true;
    currentFrame += 0.003;
    if (currentFrame > 6) {
       currentFrame = 0;
    }
    if (position.y == ground) {
        sprite.setTextureRect( IntRect(250 * (int)floor(currentFrame), 0, 250, 560));//* int(currentFrame)
    }

}

void Players::stopRight() {
    m_RightPressed = false;

}

void Players::goJump() {
    onGround = false;
    currentFrame += 0.003;//отрисовка
    dy = -40;
    if (currentFrame > 1) {
       currentFrame = 0;
    }
    if (dx > 0)
        sprite.setTextureRect(IntRect(0,580,260,460));
    else
        sprite.setTextureRect(IntRect(260,580,-260,460));
}
void Players::stopJump() {
    onGround = true;
}
Sprite Players::getSprite(){
    return sprite;
}
// void Players::goSitDown() {
//     sitDown = true;
//     if (m_RightPressed || m_LeftPressed) {
//         if (dx > 0)
//         {

//         }
//     }
// }

void Players:: update(float elapsedtime) {

    if (m_RightPressed) {
        position.x += elapsedtime * m_speed;
            if (position.x > 1200)
                position.x = 1200;
    }
    if (m_LeftPressed) {
        position.x -= elapsedtime * m_speed;
            if (position.x < 0)
                position.x = 0;
    }
    if (onGround == false) {
        dy +=150 * elapsedtime;
        position.y +=dy * elapsedtime * 35;
        onGround = false;
    }
    if (position.y > ground) {
        position.y = ground;
        dy = 0;
        onGround = true;
        defaultPosition();
    }
    sprite.setPosition(position);
}
