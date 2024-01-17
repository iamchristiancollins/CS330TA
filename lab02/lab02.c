#include <stdio.h>

void myFunction();

int main() {
    printf("hello\n");

    int x;
    x = 7;

    printf("%d\n", x);

    myFunction();
    
    return 0;
}

void myFunction(){
    printf("you're all doing great\n");
}