#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    char c[4];
    int i;
    for(i = 0; i < 4; ++i){
        printf("alamat dari c[%d] = %x\n", i, &c[i]);
    }
}