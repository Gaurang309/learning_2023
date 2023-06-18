#include <stdio.h>

int main() {
    int array[5] = {10, 15, 20, 25, 30};
    int size = sizeof(array) / sizeof(array[0]);  // Calculate the size of the array
    int sumOdd = 0;
    int sumEven = 0;

    // Calculate the sum of odd and even numbers
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            sumEven += array[i];
        } else {
            sumOdd += array[i];
        }
    }

    // Calculate the difference between the sum of odd and even numbers
    int difference = sumEven - sumOdd;

    // Print the difference
    printf("Difference: %d\n", difference);

    return 0;
}
