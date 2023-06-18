#include <stdio.h>

int main() {
    int array[7] = {10, 15, 20, 25, 30, 35, 40};
    int size = sizeof(array) / sizeof(array[0]);  // Calculate the size of the array
    int countOdd = 0;
    int countEvenIndex = 0;

    // Count the number of odd elements and even indexed elements
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 1) {
            countOdd++;
        }
        if (i % 2 == 0) {
            countEvenIndex++;
        }
    }

    // Calculate the difference between the count of odd elements and even indexed elements
    int difference = countEvenIndex - countOdd;

    // Print the difference
    printf("Difference: %d\n", difference);

    return 0;
}
