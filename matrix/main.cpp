#include<stdio.h>
#include"matric.hpp"
#include<string.h>
#include <iostream>

template<class T>
void size(T* arr, int size) {
    T* buf = new T[3*3];
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3; j++) {

            std::cout << arr[i*3+j] <<std::endl;
        }
        std::cout << std::endl;
    }
}


int main() {
    Matric matric("DNA.txt");
    int lines;
    int stolbec;
    std::cout << "введите строку"<< std::endl;
    std::cin >> lines;
    std::cout << "введите столбец"<< std::endl;
    std::cin >> stolbec;
    matric.getElement(lines, stolbec);
    double** buf;
    buf = matric.getMatric(buf);
   
    int idStolbec;
    std::cout << "введите номер столбца"<< std::endl;
    std::cin >> idStolbec ;
    double* stolbecMatric = matric.getStolbec(buf,idStolbec);
    matric.removeMatric(buf);
    matric.removeStolbec(stolbecMatric);
    
    return 0;
}
