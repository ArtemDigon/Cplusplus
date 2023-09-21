#include <SFML/Graphics.hpp>
#include "classEntity.hpp"

using namespace sf;

Sprite* Entity::createSprite(Sprite *sprite) {
    Texture* texture;
    texture->loadFromFile("/Users/artem/Cplusplus/sfml/Texture/Enimy (фон удален).png");
    sprite->setTexture(*texture);
    return sprite;
}
// Sprite* Entity::getPosition(Sprite *sprite) {
//     double arr[2];
//     FILE* file = fopen("safePosition.txt", "r");
//     if (file == NULL) {
//         arr[0] = 0;
//         arr[1] = 0;
//     }
//     double number;
//     fseek(file, 0, SEEK_SET);
//     for (int i = 0;i < 2 ;i++){
//          fscanf(file, "%lf", &number);
//             arr[i] = number;
//     }
//     sprite->setPosition(arr[0],arr[1]);
//     fclose(file);
//     return sprite;
// }





