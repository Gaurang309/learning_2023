#include <stdio.h>

int main() {
    int array[5] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]);  // Calculate the size of the array
    int sum = 0;
    float average;

    // Calculate the sum
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    // Calculate the average
    average = (float)sum / size;

    // Print the sum and average
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
