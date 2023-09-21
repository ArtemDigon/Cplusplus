#include "user.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    cout << "Привет! Введите количество пользователей "<< endl;
    int count;
    cin >> count;
    User user(count);
    user.newUser();
    user.print();
    user.kickUser();

    //     vector<string> name_pizza;
    //     int count_pizza;
    //     cout << "введите кол-во любимых пицц пользователя "<< name <<endl;
    //     cin>> count_pizza;
    //     cout << "введите  любимые пиццы пользователя "<< name <<endl;
    //     name_pizza.resize(count_pizza);
    //     for (vector<string>::iterator it = name_pizza.begin();it != name_pizza.end();it++) {
    //         cin >> *it;
    //     }
    //     User* per0 = new User(user.getName());
    //     map<User*,vector<string> > users;
    //     users.insert(pair<User*,vector<string> > (per0,name_pizza));
    //     for (int i = 1;i <count;i++) {
    //         cout << "Введи имя пользователя № "<< i + 1 <<endl;
    //         cin >> name;
    //         cout << "введите кол-во любимых пицц пользователя "<< name <<endl;
    //         cin>> count_pizza;
    //         cout << "введите любимые пиццы пользователя "<< name <<endl;
    //         for (int i =0; i < count_pizza;i++) {cin >> name_pizza[i];}
    //         user.newUser(name);
    //         per0 = new User(user.getName());
    //         users.insert(pair<User*,vector<string> > (per0,name_pizza));
    //         i++;
    //     }
    //     user.print();

    //     // for(map<User*,vector<string> >::iterator it = users.begin(); it != users.end();it++) {
    //     //         cout<< it->first->getName() << " ";
    //     //         for (size_t i = 0; i < it->second.size(); i++) {
    //     //             cout << it->second[i];
    //     //         }
    //     //     cout<<endl;
    //     // }
    //     cout<< "желаете ли вы удалить пользователя? Напишите:"<<endl<<" 1-да"<<endl<<"2-нет" << endl;
    //     int  answer;
    //     cin >> answer;
    //     if (answer == 1) {

    //     }
    //         //
    // users.clear();
    // delete per0;

    return 0;
}
