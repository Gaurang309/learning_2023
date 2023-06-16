#include <stdio.h>

int deleteDigit(int num) {
    int divisor = 1;
    int largest = 0;

    while (divisor <= num) {
        int deletedNum = (num / (divisor * 10)) * divisor + (num % divisor);
        if (deletedNum > largest) {
            largest = deletedNum;
        }
        divisor *= 10;
    }

    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    int largest = deleteDigit(num);
    printf("Largest number after deleting a single digit: %d\n", largest);
    return 0;
}