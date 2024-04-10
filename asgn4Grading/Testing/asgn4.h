#ifndef __asgn4__
#define __asgn4__
/* the two lines above check to ensure
we haven't already included this header*/


/* ========================================================================= */
/* ~~~~~~~~~~~~~~~~~~~~~ your functions go here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Note: main() goes in the asgn4.c file                                     */



/*
 discription: This function takes an array of integers
 and a size input value that dictates the size of an array 
 and then loops through that array starting from index 1 and
 and then it takes this value and iterates backwards through the array
 and sorts it into its correct position by seeing wether or not
 this vaue at this index is less than or greater than any 
 previous index values, and if its less than the previous values
 it sorts the index into the position where its greater then the
 value of the index to the left and less than the index value to 
 the right, shifting all values to the right or left. If the value is
 already in the correct position it iterates to the next index and loops through
 again until the entire array is sorted

arguments: 
    int* arr: which represents the inputed array that can be changes
    via a pointer to the begining of said array
    int size: which represents the input of a set size of the given array by inputing 
    the number of elements in the array

returns:
    void:
    rerturns a sorted array when called via the array pointer

*/
void insertionSort(int* arr, int size){
    for(int i = 1; i < size; i++){
        int key = *(arr + i);
        int j = i -1;
        while(j >= 0 && key < *(arr + j)){
            *(arr + j + 1) = *(arr + j);
            j -= 1;
        }
        *(arr + j + 1) = key;
    }
    return;
}

/*
 discription: This function takes an array of integers, the
 itemsList, and a size input value, n, that dictates the size of an array 
 based on the number of elements chosen. It first starts at the first element
 or index 0 and loops through the entire array to find the smallest value.
 once it does it swaps this value with the current value that is at the begining
 of the array. It then loops through all the rest of the array finding the next
 min value and swaps it with first value of the unsorted array and then continues
 this process until the entire array is sorted.
 

arguments: 
    int* itemsList: which represents the inputed array that can be changes
    via a pointer to the begining of said array
    int n: which represents the input of a set size of the given array by inputing 
    the number of elements in the array

returns:
    itemsList:
    which is a sorted array via the array pointer, because it points to the first element
    of the sorted array

*/
int* selectionSort(int* itemsList, int n){
    for(int i = 0; i < n - 1; i++){
        int minValueIndex = i;
        for(int j = i + 1; j < n; j++){
            if(*(itemsList + j) < *(itemsList + minValueIndex)){
                minValueIndex = j;
            }
        }if(minValueIndex != i){
            int temp = *(itemsList + i);
            *(itemsList + i) = *(itemsList + minValueIndex);
            *(itemsList + minValueIndex) = temp;
            }
    }
    return itemsList;
}









#endif