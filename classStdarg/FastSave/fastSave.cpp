#include <iostream>
#include "fastSave.hpp"

int main() {
    int size;
    std::cin>>size;
    int a[] = {1,2,3,4,5,6,7,8};
    FastSave<char> fastsave("hello artem",size);
    fastsave.fastSaveFile();
    char* arr = fastsave.getDataFile("write.fsd");
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
    }
    return 0;
}
