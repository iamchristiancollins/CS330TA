#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 5;
    int result;

    result = factorial(num);

    printf("Factorial of %d is: %d\n", num, result);

    return 0;
}
