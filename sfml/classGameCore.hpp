#include "classEntity.hpp"
#include "classMove.hpp"
#include <SFML/Graphics.hpp>

class GameCore {
    private:
        Entity *entity;
        Move *move;
        Event *event;
        RenderWindow *window;
        Sprite *sprite;
        void draw();

    public:
        GameCore(int width, int height);
        ~GameCore();
        void start();

};

