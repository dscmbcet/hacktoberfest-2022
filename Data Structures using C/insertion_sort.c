
#include <stdio.h>
#include <stdlib.h>

//Quick Sort - Recursion Function -----------------
int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

void quickSort(int array[], int low, int high){

    if(low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
//-------------------------------------------------

int main(){

    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n);

    //Sorted array
    printf("Sorted array: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
