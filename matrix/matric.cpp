#include<stdio.h>
#include"matric.hpp"
#include"string.h"
//(filename,)
Matric::Matric(const char* filename){
    FILE* file  = fopen(filename, "r");
    if (file == NULL) {
        printf("no file");
        return;
    }
    char g;
    while((g = fgetc(file)) !=EOF) {
        if (g == '\n')
            this->lines++;
        if (g == '\t')
            this->cols++;
    }
    fseek(file, 0, SEEK_SET);
    this->stolbec = this->cols/this->lines + 1 ;
    double number = 0;
    this->matric = new double*[this->lines];
     for (int i = 0;i < this->lines ;i++){
        this->matric[i] =new double[this->stolbec];
        for (int j = 0;j < this->stolbec + 1 ;j++){
             fscanf(file, "%lf", &number);
             this->matric[i][j] = number;
        }
     }
     for (int i = 0;i < this->lines ;i++){
        for (int j = 0; j < this->stolbec + 1;j++){
            printf("%lf ",this->matric[i][j]);
        }
        printf("\n");
     }
           
    fclose(file);
}
Matric::~Matric() {
    for (int i=0;i< this->stolbec + 1;i++){
        delete[] this->matric[i];
    }
    delete[] this->matric;
}
void Matric::getElement(int a, int b) {
    a = a%this->lines;
    b = b%this->stolbec;

    printf("%lf\n",this->matric[a][b]);
}
double** Matric::getMatric(double** buf){
    buf = new double*[this->lines];
        for (int i = 0; i < this->lines;i++) {
            buf[i] = new double[this->stolbec];
            for (int j = 0; j < this->stolbec + 1; j++) 
                buf[i][j] = this->matric[i][j];
        }
    return buf;
} 
void Matric::removeMatric(double** buf){
     for (int i=0;i< this->stolbec + 1;i++){
        delete[] buf[i];
    }
    delete[] buf;
}
double* Matric::getStolbec(double** buf,int a){
    double* stolbecMatric = new double[this->lines];
    for (int i=0;i< this->lines;i++) {
        stolbecMatric[i] = buf[i][a];
        printf("%lf \n",stolbecMatric[i]);
    }
    return stolbecMatric;
}
void Matric::removeStolbec(double* stolbecMatric){
    delete[] stolbecMatric;
}
