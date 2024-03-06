#include <stdio.h>

int main(){
    int a = 2;
    a *= ++a + a++;
    printf("a is now %d\n", a);
    
    return 0;
}

// What is a?