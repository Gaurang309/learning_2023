#include <stdio.h>
#include <stdlib.h>

typedef struct ComplexNumber {
    int real;
    int imaginary;
} ComplexNumber;

typedef struct ComplexNode {
    ComplexNumber data;
    struct ComplexNode* next;
} ComplexNode;

void addAtBeginning(ComplexNode** head, int real, int imaginary) {
    ComplexNode* newNode = (ComplexNode*)malloc(sizeof(ComplexNode));
    newNode->data.real = real;
    newNode->data.imaginary = imaginary;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(ComplexNode** head, int real, int imaginary) {
    ComplexNode* newNode = (ComplexNode*)malloc(sizeof(ComplexNode));
    newNode->data.real = real;
    newNode->data.imaginary = imaginary;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    ComplexNode* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void addInBetween(ComplexNode* prevNode, int real, int imaginary) {
    if (prevNode == NULL) {
        printf("Previous node should be valid.\n");
        return;
    }

    ComplexNode* newNode = (ComplexNode*)malloc(sizeof(ComplexNode));
    newNode->data.real = real;
    newNode->data.imaginary = imaginary;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void printList(ComplexNode* head) {
    ComplexNode* currNode = head;
    while (currNode != NULL) {
        printf("%d + %di -> ", currNode->data.real, currNode->data.imaginary);
        currNode = currNode->next;
    }
    printf("None\n");
}

void freeList(ComplexNode* head) {
    ComplexNode* currNode = head;
    while (currNode != NULL) {
        ComplexNode* temp = currNode;
        currNode = currNode->next;
        free(temp);
    }
}

int main() {
    ComplexNode* complexList = NULL;

    addAtEnd(&complexList, 1, 2);
    addAtEnd(&complexList, 3, 4);
    addAtBeginning(&complexList, 5, 6);
    addInBetween(complexList, 7, 8);

    printList(complexList);

    freeList(complexList);

    return 0;
}
