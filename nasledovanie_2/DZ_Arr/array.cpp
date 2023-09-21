#include <stdio.h>
#include <string.h>
#include "array.hpp"

Array::Array(const char *string) {
    this->len = strlen(string) + 1;
    this->string = new char[this->len];
    for (int i = 0; i < len; i++) {
        this->string[i] = string[i];
    }
    this->string[len - 1] = '\0';

};
Array::~Array(){
    delete[] this->string;
};
void Array::countString() {
    int countForWord = 0;
    char* buf = new char[this->len];
    strcpy(buf, this->string);
    char *arrWord;
    char **arrWords;
    char box;
    int start = 0;
    int end = 0;
   for (int i = 0;i < this->len;i++) {
        if (buf[i] == ' ' || buf[i] == '\0') {
            end = i - 1;
            countForWord+=end - start + 1;
            *arrWord = new char[end - start + 1];
            start = i + 1;
        }      
   }
   printf("%d\n",countForWord);
   printf("%s\n",buf);
}

