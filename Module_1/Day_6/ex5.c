#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person* person1, struct Person* person2) {
    // Swap name field
    char tempName[50];
    strcpy(tempName, person1->name);
    strcpy(person1->name, person2->name);
    strcpy(person2->name, tempName);

    // Swap age field
    int tempAge = person1->age;
    person1->age = person2->age;
    person2->age = tempAge;
}

int main() {
    struct Person person1, person2;

    // Input data for person 1
    printf("Enter details for person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &(person1.age));

    // Input data for person 2
    printf("\nEnter details for person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &(person2.age));

    printf("\nBefore swapping:\n");
    printf("Person 1 - Name: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2 - Name: %s, Age: %d\n", person2.name, person2.age);

    // Swap fields of person 1 and person 2
    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1 - Name: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2 - Name: %s, Age: %d\n", person2.name, person2.age);

    return 0;
}
