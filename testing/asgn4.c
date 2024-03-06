#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asgn4.h"

int main(){

    int num;
    printf("Enter number of elements in the array: ");
    scanf("%d", &num);

    int array[num];

    for (int i=0; i < num; i++){
        printf("Enter element: ");
        scanf("%d", &array[i]);

    }

    insertionSort(array);
    printf("%ls", array);
    selectionSort(array);
    printf("%ls", array);

    
}