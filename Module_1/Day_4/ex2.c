#include <stdio.h>

int main() {
    int array[5] = {10, 20, 5, 30, 15};
    int size = sizeof(array) / sizeof(array[0]);  // Calculate the size of the array
    int min = array[0];  // Assume the first element as the minimum
    int max = array[0];  // Assume the first element as the maximum

    // Find the minimum and maximum values
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Print the minimum and maximum values
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
