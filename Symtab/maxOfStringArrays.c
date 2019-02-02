#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){

    char data[][6] = {
        "Orange",
        "Apple",
        "Mango"
        };

    int i = 0;

    for(i=0; i < 3; ++i){
        printf("%s\n", data + i);
    }

getch();
}
