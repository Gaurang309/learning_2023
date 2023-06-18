#include <stdio.h>

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move the indices towards the center
        start++;
        end--;
    }
}

int main() {
    int array[5] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]);  // Calculate the size of the array

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Reverse the array
    reverseArray(array, size);

    printf("Reversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
