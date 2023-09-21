#include <iostream>
#include "morze.hpp"
#include <string>

int main(){
    Morze morze("**** * *-** *-** --- *-- --- *-* *-** -** ");
    string text = morze.getText();
    std::cout << text << std::endl;

    return 0;
}
