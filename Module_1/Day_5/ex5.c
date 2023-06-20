#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isValidEmail(const char* str) {
    int length = strlen(str);
    int atIndex = -1;
    int dotIndex = -1;
    int i;

    // Check if the string is empty or contains only whitespace characters
    if (length == 0 || isspace(str[0])) {
        return false;
    }

    // Iterate through the string to find the @ and the last dot (.)
    for (i = 0; i < length; i++) {
        if (str[i] == '@') {
            if (atIndex != -1) {
                return false;  // More than one @ symbol
            }
            atIndex = i;
        } else if (str[i] == '.') {
            dotIndex = i;
        }
    }

    // Check if the @ symbol and dot are present
    if (atIndex == -1 || dotIndex == -1) {
        return false;
    }

    // Check if the username, domain, and extension are valid
    for (i = 0; i < atIndex; i++) {
        if (!isalnum(str[i]) && str[i] != '.') {
            return false;  // Invalid character in username
        }
    }

    for (i = atIndex + 1; i < dotIndex; i++) {
        if (!isalpha(str[i]) || !islower(str[i])) {
            return false;  // Invalid character in domain
        }
    }

    for (i = dotIndex + 1; i < length; i++) {
        if (!isalpha(str[i]) || !islower(str[i])) {
            return false;  // Invalid character in extension
        }
    }

    return true;  // Email format is valid
}

int main() {
    char email[100];

    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove trailing newline if present

    if (isValidEmail(email)) {
        printf("Valid email address: %s\n", email);
    } else {
        printf("Invalid email address.\n");
    }

    return 0;
}
