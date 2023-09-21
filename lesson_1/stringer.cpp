#include <stdio.h>
#include <string.h>
#include "stringer.hpp"

Stringer::Stringer(const char* string){
    this->len = strlen(string) + 1;
    this->string = new char[len];
    for(int i = 0; i < this->len - 1;i++) {
        this->string[i] = string[i];
    }
    this->string[len - 1] = '\0';

    
}
Stringer::~Stringer(){
    delete[] string;
}
void Stringer::newWords(const char* string){
    this->len = strlen(string) + 1;
    delete[] this->string;
    this->string = new char[this->len];
    for (int i = 0; i < this->len; i++) {
        this->string[i] = string[i];
    }
    this->string[len - 1] = '\0';
    for (int i = 0; i < this->len; i++) {
        printf("%c", this->string[i]);
    }
    printf("\n");
}
void Stringer::print(){
    printf("%s\n", this->string);
}
void Stringer::reverseStrings(){   
    for (int i = 0; i < this->len; i++) {
        printf("%c", this->string[this->len]);
    }
    printf("\n");
}
void Stringer::reverseWord(char* buf,int start, int end) {
    for (int i = 0;i < ((end - start + 1)/2); i++){
        char box = buf[start + i];
        buf[start + i] = buf[end - i];
        buf[end - i] = box;
    }
}
void Stringer::reverseString(){
    char* buf = new char[this->len];
    strcpy(buf, this->string);
    char box;
    int start = 0;
    int end = 0;
   for (int i = 0;i < this->len;i++) {
        if (buf[i] == ' ' || buf[i] == '\0') {
            end = i - 1;
            printf("конец;%d\n",end); 
            reverseWord(buf,start,end);
            start = i + 1;
            printf("старт:%d\n",start); 
        }      
   }
   printf("%s\n",buf);
}
int Stringer::countWords() {
    int count = 1;
    for (int i = 0;i < this->len;i++){
        if (this->string[i] == ' ')
            count++;
    }
    return count;
}
