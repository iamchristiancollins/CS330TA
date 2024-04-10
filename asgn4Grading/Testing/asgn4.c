#include<stdio.h>
#include <stdlib.h>
#include "asgn4.h"

void insertionSort(int* arr, int size);
int* selectionSort(int* itemsList, int n);

int main() {
    /*
    takes the variable size as an user input integer
*/
    int size;
    printf("number of elements: ");
    scanf("%d", &size);

   /*
    This allocates the memory for sortInsertion and sortSelection
    in an array of integers via the malloc function, the 
    memory being required to store being the inputed size times the
    sizeof(int)
*/
    int* sortInsertion = (int*)malloc(size * sizeof(int));
    int* sortSelection = (int*)malloc(size * sizeof(int));

       /*
    This prompts for a user imput of the array with spaces 
    between each element of the array based on the 
    size of the number of elements given previously 
    and then sets this as the array for the sorting of the array 
    using insertion and selection sort
*/
    printf("%d elements separated: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &sortInsertion[i]);
        sortSelection[i] = sortInsertion[i];
    }

      /*
    This calls on the insertionSort function with the
    arguments of the inputed array and the iputed
    size of the array, and sorts the array and prints each
    element out via the loop into one sorted array
*/
    insertionSort(sortInsertion, size);
    printf("Insertion Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortInsertion[i]);
    }
    printf("\n");

      /*
    This calls on the selectionSort function with the
    arguments of the inputed array and the iputed
    size of the array, and sorts the array and prints each
    element out via the loop into one sorted array
*/
    selectionSort(sortSelection, size);
    printf("Selection Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortSelection[i]);
    }
    printf("\n");


    return 0;
}