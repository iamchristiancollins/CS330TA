#include <stdio.h>

int main(){
    int firstNum, secondNum;
    firstNum = secondNum = 10;
    secondNum /= 2;
    int answer = ++firstNum + secondNum--;
    printf("%d\n", answer);
    return 0;
}

/* What is the answer?
    a. error
    b. 14
    c. 15
    d. 16
    e. something else _____
*/