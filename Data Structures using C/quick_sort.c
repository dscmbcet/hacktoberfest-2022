#include <stdio.h>

int partition(int[], int, int);
void quickSort(int[], int, int);
void print(int[], int);
void swap(int*, int*);

void swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];  // Last element is taken as pivot
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return i + 1;
}

void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pI = partition(arr, low, high);

    quickSort(arr, low, pI - 1);
    quickSort(arr, pI + 1, high);
  }
}

int main() {
  int n;

  printf("Enter size of array: ");
  scanf("%d", &n);

  int arr[n];

  printf("\nEnter the elements of array: \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nArray before sorting: \n");
  print(arr, n);

  quickSort(arr, 0, n - 1);

  printf("\nArray after sorting: \n");
  print(arr, n);

  return 0;
}