#include <stdio.h>
#include <string>
#include <iostream>

template   <class T>
class FastSave {
    public:
    FastSave(const T* data,size_t size,char arg);
    ~FastSave();
    void printf();

    private:
    T* data;
    T** dataMatric;
    int stolbec;
    int lines;
    int cols;
    size_t size;

};
template<typename T>
inline FastSave<T>::FastSave(const T* data, size_t size,char arg)
{
    FILE* fpp = fopen("write.txt", "w");
    this->size = size;
    T g;
    T* buf;
    FILE* fp = fopen(data, "r");
        buf = new T[size];
        if (fp == NULL) {
            for (int i=0; i<size; i++) {
                buf[i] =data[i];
            }
            
        }
        else if (fp != NULL) {
            if (arg == 't') {
                fread(buf,size,sizeof(T),fp);
            }

            else if (arg == 'm') {
                while((g = fgetc(fp)) !=EOF) {
                    if (g == '\n') 
                        this->lines++;
                    else if (g == '\t')
                        this->cols++;
                }
                fseek(fp, 0, SEEK_SET);
                this->stolbec = this->cols/this->lines + 1 ;
                T number = 0;
                this->dataMatric = new T*[this->lines];
                for (int i = 0;i < this->lines ;i++){
                    this->dataMatric[i] = new T[this->stolbec];
                    for (int j = 0;j < this->stolbec + 1 ;j++){
                        fscanf(fp, "%s", &number);
                        this->dataMatric[i][j] = number;
                    }
                }

            }

        }
    if (arg == 't')
        //for (size_t i = 0; i < this->size; i++) {
        std::cout<<sizeof(T)<<std::endl;
        fwrite(&buf,size,sizeof(T),fpp);     
    //}
    if (arg == 'm') {
        for (int i = 0;i < this->lines + 1 ;i++){
            for (int j = 0; j < this->stolbec;j++){
                std::cout << this->dataMatric[i][j];
        }
     std::cout<<std::endl;
     
     }

    }
    //std::cout<<this->lines  <<std::endl;
    //std::cout<<this->stolbec  <<std::endl;

}

template<typename T>
inline FastSave<T>::~FastSave() {
}
