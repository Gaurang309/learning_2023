#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define MAX_SIZE 100

typedef struct {
    complex double data[MAX_SIZE];
    int top;
} ComplexStack;

void initialize(ComplexStack* stack) {
    stack->top = -1;
}

int is_empty(ComplexStack* stack) {
    return stack->top == -1;
}

int is_full(ComplexStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(ComplexStack* stack, complex double num) {
    if (is_full(stack)) {
        printf("Stack overflow.\n");
        return;
    }

    stack->data[++stack->top] = num;
}

complex double pop(ComplexStack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return 0.0 + 0.0 * I;
    }

    return stack->data[stack->top--];
}

complex double peek(ComplexStack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return 0.0 + 0.0 * I;
    }

    return stack->data[stack->top];
}

int main() {
    ComplexStack stack;
    initialize(&stack);

    push(&stack, 1.0 + 2.0 * I);
    push(&stack, 3.0 - 4.0 * I);
    push(&stack, 5.0 + 6.0 * I);

    printf("Peek: %lf + %lf i\n", creal(peek(&stack)), cimag(peek(&stack)));  

    complex double popped_element = pop(&stack);
    printf("Popped element: %lf + %lf i\n", creal(popped_element), cimag(popped_element));  

    printf("Peek after pop: %lf + %lf i\n", creal(peek(&stack)), cimag(peek(&stack)));  

    return 0;
}
