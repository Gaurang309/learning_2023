#include <stdio.h>
#include <string.h>

void rotateString(char* str, int positions) {
    int length = strlen(str);

    // Calculate the effective number of rotations
    positions = positions % length;
    if (positions < 0) {
        positions += length; // Convert negative rotations to positive
    }

    // Rotate the string in-place
    for (int i = 0; i < positions; i++) {
        char temp = str[0];

        for (int j = 0; j < length - 1; j++) {
            str[j] = str[j + 1];
        }

        str[length - 1] = temp;
    }
}

int main() {
    char str[100];
    int positions;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline if present

    printf("Enter the number of positions to rotate: ");
    scanf("%d", &positions);

    rotateString(str, positions);

    printf("Rotated string: %s\n", str);

    return 0;
}
