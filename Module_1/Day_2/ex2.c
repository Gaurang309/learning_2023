#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generic swap function
void swap(void *a, void *b, size_t size) {
    char *temp = (char *)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    double d1 = 3.14, d2 = 6.28;
    printf("Before swap: d1 = %lf, d2 = %lf\n", d1, d2);
    swap(&d1, &d2, sizeof(double));
    printf("After swap: d1 = %lf, d2 = %lf\n", d1, d2);

    char c1 = 'A', c2 = 'B';
    printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swap: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}