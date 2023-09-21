#include <SFML/Graphics.hpp>

using namespace sf;

class Players {

    public:
        float dx,dy;
        FloatRect rect;
        float currentFrame;
        bool onGround;
        Players();
        ~Players();
        void goLeft();
        void goRight();
        void stopLeft();
        void stopRight();
        void update(float elasedTime);
        void goJump();
        void stopJump();
        void defaultPosition();
        void goSitDown();
        void stopSitDown();
        Sprite getSprite();


    private:
        float ground;
        Vector2f position;
        Texture texture;
        Sprite sprite;
        bool m_LeftPressed;
        bool m_RightPressed;
        bool sitDown;
        float m_speed;

};
