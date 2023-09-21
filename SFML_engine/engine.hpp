#include "SFML/Graphics.hpp"
#include "players.hpp"

class Engine {

    public:
        Engine();
        void start();

    private:
        RenderWindow window;
        Texture backGroundTexture;
        Sprite backGroundSprite;
        Players playerOne;

        void input();
        void update(float dtAsSeconds);
        void draw();

};
