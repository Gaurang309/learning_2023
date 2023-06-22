#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringAndInitializeStructArray(const char* inputString, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token;

    // Parse the input string and initialize the struct array
    for (int i = 0; i < numStudents; i++) {
        // Extract the rollno from the input string
        token = strtok((char*)inputString, delimiter);
        students[i].rollno = atoi(token);

        // Extract the name from the input string
        token = strtok(NULL, delimiter);
        strcpy(students[i].name, token);

        // Extract the marks from the input string
        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        // Move to the next student in the input string
        inputString = strchr(inputString, '\0') + 1;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    printf("Enter the student details in the format: rollno name marks\n");

    // Read the input for each student
    for (int i = 0; i < numStudents; i++) {
        char inputString[100];
        printf("Student %d: ", i + 1);
        scanf(" %[^\n]", inputString);
        parseStringAndInitializeStructArray(inputString, &students[i], 1);
    }

    // Display the initialized struct array
    printf("\nInitialized struct array:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}
