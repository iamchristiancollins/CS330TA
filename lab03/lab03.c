#include <stdio.h>

void printUserInput();

int main(){

    printUserInput();


    return 0;
}
/*
Description: This functions prompts the user for two integers and prints the resulting sum
Argument: None
Returns: None
*/
void printUserInput(){
    int a, b, c;
    printf("Enter an integer: ");
    scanf("%d", &a);    // stores number that user types in a
    printf("Enter a second integer: ");
    scanf("%d", &b);    // stores number user types in b

    c = a + b;

    printf("The sum of %d and %d is %d\n", a, b, c);
}