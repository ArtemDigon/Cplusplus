#include <string>
using namespace std;

class Morze {

public:
    Morze(string text);
    string getMorze();
    string getText();

private:
    size_t size;
    string text;
    string morze;
    string data;
};
