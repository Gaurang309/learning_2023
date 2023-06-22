#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStructArray(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &(students[i].rollno));
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
        printf("\n");
    }
}

void sortStructArrayDescending(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the elements
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStructArray(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

void searchByName(const struct Student* students, int numStudents, const char* name) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n\n");
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    initializeStructArray(students, numStudents);

    printf("Initialized struct array:\n");
    displayStructArray(students, numStudents);

    sortStructArrayDescending(students, numStudents);

    printf("After sorting (descending order based on marks):\n");
    displayStructArray(students, numStudents);

    char searchName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    searchByName(students, numStudents, searchName);

    free(students);

    return 0;
}
