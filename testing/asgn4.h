#ifndef __asgn4__
#define __asgn4__
/* the two lines above check to ensure
we haven't already included this header*/


/* ========================================================================= */
/* ~~~~~~~~~~~~~~~~~~~~~ your functions go here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Note: main() goes in the asgn4.c file                                     */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int ar[]){
    for(int i = 0; i < len(ar); i++){
        printf("%d", ar[i]);
        printf(" ");
    }
}

void insertionSort(int arr[], int len){
    int i, j, key;

    for(i = 1; i < len; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j];
            j = j-1
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int itemList[], int length){
    int n = len(itemList);
    int i, j, temp; 
    
    for(i = 0; i < n - 1; i++){
        minValueIndex = i;

        for(j = 1;  j < n; i++){
            if (itemList[j] < itemList[minValueIndex]){
                minValueIndex = j;

            }

            if( minValueIndex != i){
                temp = itemList[i];
                itemList[i] = itemList[minValueIndex];
                itemList[minValueIndex] = temp;
            }
        }
    }
}


    









#endif