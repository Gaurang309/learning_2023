#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

// Function to read a complex number
void readComplex(struct Complex* complexPtr) {
    printf("Enter the real part: ");
    scanf("%lf", &(complexPtr->real));

    printf("Enter the imaginary part: ");
    scanf("%lf", &(complexPtr->imaginary));
}

// Function to write a complex number
void writeComplex(struct Complex* complexPtr) {
    printf("Complex number: %.2lf + %.2lfi\n", complexPtr->real, complexPtr->imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex* complex1, struct Complex* complex2) {
    struct Complex sum;
    sum.real = complex1->real + complex2->real;
    sum.imaginary = complex1->imaginary + complex2->imaginary;
    return sum;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex* complex1, struct Complex* complex2) {
    struct Complex product;
    product.real = complex1->real * complex2->real - complex1->imaginary * complex2->imaginary;
    product.imaginary = complex1->real * complex2->imaginary + complex1->imaginary * complex2->real;
    return product;
}

int main() {
    struct Complex complex1, complex2;

    printf("Enter the first complex number\n");
    readComplex(&complex1);

    printf("\nEnter the second complex number\n");
    readComplex(&complex2);

    printf("\nFirst complex number:\n");
    writeComplex(&complex1);

    printf("\nSecond complex number:\n");
    writeComplex(&complex2);

    struct Complex sum = addComplex(&complex1, &complex2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(&sum);

    struct Complex product = multiplyComplex(&complex1, &complex2);
    printf("\nProduct of the complex numbers\n");
    writeComplex(&product);

    return 0;
}
