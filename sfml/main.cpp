#include <SFML/Graphics.hpp>
#include "classGameCore.hpp"
#include "thread"


int main()
{
    GameCore game(900,900);
    game.start();
    return 0;
}
