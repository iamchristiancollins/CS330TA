#include <stdio.h>

int main(){
    int a = 4, b = 2;
    a += 6;
    a *= b + 3;
    a -= b + 8;
    a /= b;
    a %= b + 1;
    printf("a is now: %d\n", a);
    return 0;
}
/* What is a?
(a) 0
(b) 1
(c) 2
(d) 3
(e) 6

(example provided by Ian Toy)
*/