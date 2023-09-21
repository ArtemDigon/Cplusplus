/*                                                 
               _______________________            _________
              /    __________________/           /  ______  \  
             /    /                             /  /       \_\
            /    /________________             /  /
           /    _________________/             \  \
          /    /                                \  \_________
         /    /                                  \_________  \
        /    /                                             \  \
       /    /                                    ___        |  |
      /    /                                     \  \_______/ /
     /____/                                       \ _________/
    
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>

template<class T>
class FastSave {

    public:
    FastSave(const T* data,size_t size);
    ~FastSave();
    void fastSaveFile(const char* filename);
    void fastSaveFile();
    T* getDataFile(const char* filename);

    private:
    int  size;
    T* buf;
    int key;
};

template<class T>
inline FastSave<T>::FastSave(const T* data,size_t size){
    this->key = sizeof(T);
    this->size = 0;
    while(data[this->size] != '\0') {
        this->size++;
    }
    if (this->size < size) {
        size = this->size;
    }
    size_t len = *(data + 1) - data[0];
    this->size = size;
    this->buf = new T[size]; //////////////////////////////////////////////////////////////////
    for (size_t i = 0;i < size;i++){
        this->buf[i] = data[i];
    }
}
template<class T>
inline FastSave<T>::~FastSave(){
    delete[] this->buf;
}
template<class T>
void FastSave<T>::fastSaveFile() {
    FILE* fw = fopen("write.fsd", "w");
    fprintf(fw,"%d %d ",key,this->size);
    fputs("FastSave\n", fw);
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    fputs(asctime(timeinfo),fw);
    //cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    fwrite(this->buf,sizeof(T),this->size,fw);
    //std::cout <<sizeof(T) << std::endl;  
    fprintf(fw,"\n");
    fclose(fw);
    delete[] this->buf;
}
template<class T>
void FastSave<T>::fastSaveFile(const char* filename) {

    FILE* fw = fopen(filename, "w"); 
    fprintf(fw,"%d %d ",key,this->size);
    fputs("FastSave\n", fw);
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    fputs(asctime(timeinfo),fw);
    //cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    fwrite(this->buf,this->key,this->size,fw);
    //std::cout <<sizeof(T) << std::endl;  
    fprintf(fw,"\n");
    delete[] this->buf;
    fclose(fw);
}
template<class T>
T* FastSave<T>::getDataFile(const char* filename) {
    int key;
    int size;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return nullptr;
    fscanf(fp,"%d %d",&key,&size);
    char temp[99];
    fgets(temp,99,fp);
    fgets(temp,99,fp);
    this->buf = new T[size];
    fread(this->buf, key, size, fp);
    fclose(fp);
    return this->buf;
}