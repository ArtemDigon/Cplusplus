#include <stdio.h>
#include "arg.hpp"
#include "string"

 
int main(){
    FastSave<char> data("file.txt",8,'t');
    //FastSave<int> printf(120);
    return 0;
}
