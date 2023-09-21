#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    sf::Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    do {
        
    }
    while (time != 1000);
    this_thread::sleep_for(chrono::milliseconds(1000));
    //float time = clock.getElapsedTime().asMicroseconds();
    std::cout<<time<<std::endl;
}
