#include "user.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

User::User(int count) {
    this->count = count;
}
User::~User() {
    this->users.clear();
}
void User::newUser() {
    for (int i = 0;i <this->count;i++) {
        cout << "Введи имя пользователя № "<< this->users.size() + 1<<endl;
        cin >> this->name;
        cout << "введите кол-во любимых пицц пользователя "<< this->name <<endl;
        cin>> this->count_pizza;
        cout << "введите любимые пиццы пользователя "<< this->name <<endl;
        this->name_pizza.resize(this->count_pizza);
        for (int i =0; i < this->count_pizza;i++)
            cin >> this->name_pizza[i];
        this->users.insert(pair<string,vector<string> > (this->name,this->name_pizza));
    }
}

void User::print() {
    cout<<endl;
    cout<<"*****Users******"<<endl<<endl;
    for(map<string,vector<string> >::iterator it = this->users.begin();it != this->users.end();it++) {
        cout << it->first << " ";
        for (size_t i = 0; i < it->second.size(); i++) {
             cout<< it->second[i] << " ";
        }
        cout<<endl;
    }
}

void User::kickUser() {
    int  answer;
    do {
        cout<< "желаете ли вы удалить или добавить пользователя? Напишите:"<<endl<<"1-удалить"<<endl<<"2-добавить"<<endl<<"3-пока что хватит" << endl;
        cin >> answer;
        switch(answer) {
            case 1:
                cout<<"введите имя пользователя,которого нужно удалить"<<endl;
                print();
                cin >> this->name;
                while(users.find(this->name) == users.end()) {
                        cout<<"введите имя пользователя,которого нужно удалить еще раз"<<endl;
                        cin >> this->name;
                    }
                this->users.erase(this->name);
                print();
                break;
            case 2:
                cout<<"введите количество пользователей:"<<endl;
                cin >> this->count;
                newUser();
                print();
                break;
            default:
                return;
        }
    }
    while(this->users.size() > 0);
 }
