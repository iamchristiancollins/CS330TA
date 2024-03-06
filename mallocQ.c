#include <stdio.h>
#include <stdlib.h>

void printMyArray(float *theArray, int arraySize){
    //*(theArray + (arraySize - 1)) = 99.99;
    // printf("[ ");
    printf("\n");
    for(int i = 0; i < 20; i++){
        printf("%.2f (%p)\n", *(theArray + i), (theArray + i));
    }
    //printf(" ]\n");
    printf("\n");
    return;
}  //  end printMyArray


int main(){
    float myArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int numberOfElements = 5;
    float *myArr2 = malloc(1);  // what happens if we dont' allocate enough mem
    printMyArray(myArr, 5);
    float *myArr3 = malloc(1);
    *(myArr2 + 4) = 10.0;
    *(myArr3 + 0) = 33.3;
    printMyArray(myArr2, numberOfElements);
    printMyArray(myArr3, numberOfElements);
    free(myArr2);
    free(myArr3);
    float *myArr4 = malloc(1);
    printMyArray(myArr4, numberOfElements);


    return 0;
}