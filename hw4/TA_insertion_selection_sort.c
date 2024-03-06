#include <stdio.h>
#include <limits.h>     // for INT_MAX
void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = *(arr + i);
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && *(arr+j) > key) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = key;
    }
    return;
}  // end insertionSort

void selectionSort(int *arr, int arrayLength){
    int i = 0;
    int j = 0;
    int minValueIndex = 0;
    int tempValue = 0;
    for(i = 0; i < (arrayLength - 1); i++){
        minValueIndex = i;
        for(j=i+1; j < arrayLength; j++){
            if( *(arr + j) < *(arr + minValueIndex)){
                minValueIndex = j;
            }
        }
        if(minValueIndex != i){
            tempValue = *(arr + i);
            *(arr + i) = *(arr + minValueIndex);
            *(arr + minValueIndex) = tempValue;
        }
    }
    return;
} // end selectionSort

int main() {

    int arr[] = {9, 7, 5, 3, 2, 5, 4, 2, 6, 7};
    int arr2[] = {9, 7, 5, 3, 2, 5, 4, 2, 6, 7};
    int len = 10;

    

    int i;
    printf("before sort\n");
    for (i = 0; i < len; i++) {
        printf(" %d ", *(arr + i));
    }
    printf("\n");

    insertionSort(arr, len);
    selectionSort(arr2, len);

    printf("\ninsertion sorted:\n");
    for (i = 0; i < len; i++) {
        printf(" %d ", *(arr + i));
    }
    printf("\n");

    printf("\nselection sorted:\n");
    for (i = 0; i < len; i++) {
        printf(" %d ", *(arr2 + i));
    }
    printf("\n");


}
