#include <stdio.h>

int main()
{
    int a = 5;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;
    printf("%x\n", ptr2);
    /* What will this print?
        a. 5
        b. the address of ptr1
        c. the address of a
        d. the value of ptr1

    */
    printf("\n");
    printf("=======================\n");
    printf("\n");
    printf("value of a: %d\n", a);
    printf("address to a: %p\n", &a);
    printf("value of ptr1: %x\n", ptr1);
    printf("address of ptr1: %p\n", &ptr1);
    printf("value of ptr2: %x\n", ptr2);
    printf("address of ptr2: %p\n", &ptr2);
    return 0;
}
/* This code from one of Ian Toy's C Reviews */