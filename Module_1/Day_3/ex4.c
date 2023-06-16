#include <stdio.h>
#include <limits.h>

void findSmallestAndLargestDigits(int n, int numbers[]) {
    int smallestDigit = INT_MAX;
    int largestDigit = INT_MIN;
    int i, num, digit;

    for (i = 0; i < n; i++) {
        num = numbers[i];
        while (num != 0) {
            digit = num % 10;
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }
            if (digit > largestDigit) {
                largestDigit = digit;
            }
            num /= 10;
        }
    }

    if (smallestDigit == INT_MAX || largestDigit == INT_MIN) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int numbers[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    findSmallestAndLargestDigits(n, numbers);
    return 0;
}