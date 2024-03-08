#include <stdio.h>

void bubbleSort(int arr[], int n, int *numSwaps, int *swapCounts) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*numSwaps)++;
                swapCounts[arr[j]]++;
                swapCounts[arr[j + 1]]++;
            }
        }
    }
}

void resetArray(int arr[], int original[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = original[i];
    }
  }

void selectionSort(int arr[], int n, int swapCounts[]) {
    int i, j, minIndex, temp, totalSwaps = 0;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCounts[arr[i]]++;
            swapCounts[arr[minIndex]]++;
            totalSwaps++;
        }
    }
    printf("Total swaps: %d\n", totalSwaps);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swapCounts[arr[i]]);
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int originalArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int originalArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;

    int numSwapsBubble1 = 0, numSwapsBubble2 = 0;
    int swapCounts1[100] = {0}, swapCounts2[100] = {0};

    bubbleSort(array1, n, &numSwapsBubble1, swapCounts1);
    bubbleSort(array2, n, &numSwapsBubble2, swapCounts2);

    resetArray(array1, originalArray1, n);
    resetArray(array2, originalArray2, n);

    int numSwapsSelection1 = 0, numSwapsSelection2 = 0;
    int swapCountsSelection1[100] = {0}, swapCountsSelection2[100] = {0};

    printf("array1 bubble sort:\n");
  printf("Total swaps: %d\n", numSwapsBubble1);
    for (int i = 0; i < 100; i++) {
        if (swapCounts1[i] > 0) {
            printf("%d: %d\n", i, swapCounts1[i]);
        }
    }
  
    printf("\narray2 bubble sort:\n");
  printf("Total swaps: %d\n", numSwapsBubble2);
    for (int i = 0; i < 100; i++) {
        if (swapCounts2[i] > 0) {
            printf("%d: %d\n", i, swapCounts2[i]);
        }
    }

  printf("\narray1 selection sort:\n");
  selectionSort(array1, n, swapCountsSelection1);

  printf("\narray2 selection sort:\n");
  selectionSort(array2, n, swapCountsSelection2);
  
    return 0;
}