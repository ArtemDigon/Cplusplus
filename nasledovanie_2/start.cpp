#include <stdio.h>
#include <iostream> 
class Gun{
    private:
    public:
    int a;
    void print(){
        printf("buum\n");
    }
    virtual void perez(){//вертуальный метод,можно изменить реализацию
        printf("perez\n");
    }
};
class pictol : public Gun  {
    private:
    int b;
    public:
    void perez() override{//перереализация виртуального метода
        printf("chponk\n");
    }
    void print(){
        printf("piuu\n");
    }
};
int main() {
    Gun gun;
    pictol pictol;
    Gun* weap = &gun;//апкастинг
    weap->perez();
    weap->print();
    }
    