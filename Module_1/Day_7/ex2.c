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
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    initializeStructArray(students, numStudents);

    // Display the initialized struct array
    printf("Initialized struct array:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}
