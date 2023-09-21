#include<iostream>
#include "stringer.hpp"

/*int sum(int x,int y) {
    return (x + y);
}
double sum(double x,double y) {
    return (x + y);
}
template<typename T>
T mul(T x,T y) { 
    return (x * y);
}
template<typename T, typename T2 >
T mul(T x,T2 y) {
    return (x * y);
}*/

int main()
{
    Stringer string("hello world");
    //string.print();
    //string.reverseStrings();
    string.newWords("hello world artem");
    string.reverseString();
    printf("кол-во слов в строке:%d\n",string.countWords());
    return 0;
}
