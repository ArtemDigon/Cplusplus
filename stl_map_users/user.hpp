#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class User {

    public:
        User(int count);
        ~User();
        void print();
        void newUser();
        void kickUser();

    private:
    int count;
    map<string,vector<string> > users;
    vector<string> name_pizza;
    string name;
    int count_pizza;


};
