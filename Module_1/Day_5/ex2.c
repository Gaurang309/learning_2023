#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int stringToInt(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handle the sign
    if (str[0] == '-') {
        sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }

    // Iterate through each character of the string
    while (str[i] != '\0') {
        // Check if the character is a digit
        if (isdigit(str[i])) {
            // Convert the character to its corresponding digit
            int digit = str[i] - '0';

            // Check for potential overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                printf("Integer overflow occurred.\n");
                exit(1);
            }

            // Update the result by multiplying it by 10 and adding the digit
            result = result * 10 + digit;
        } else {
            // Invalid character encountered, break out of the loop
            break;
        }

        i++;
    }

    // Apply the sign to the result
    result *= sign;

    return result;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int num = stringToInt(str);

    printf("Converted integer: %d\n", num);

    return 0;
}
