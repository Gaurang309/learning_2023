#include <stdio.h>

void printExponent(double x) {
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long exponent = (*ptr >> 52) & ((1ULL << 11) - 1);

    // Printing the exponent in hexadecimal format
    printf("Hexadecimal: 0x%llx\n", exponent);

    // Printing the exponent in binary format
    printf("Binary: 0b");
    for (int i = 10; i >= 0; i--) {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%llu", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

   return 0;
}