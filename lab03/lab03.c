#include <stdio.h>

int main(){

    int a, b, c;
    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter a second integer: ");
    scanf("%d", &b);

    c = a + b;

    printf("The sum of %d and %d is %d\n", a, b, c);

    return 0;
}