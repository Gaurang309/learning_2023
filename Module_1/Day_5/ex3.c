#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;  // Leap year
    } else {
        return 0;  // Not a leap year
    }
}

int countDays(int year, int month) {
    int daysInMonth;

    switch (month) {
        case 1: // January
        case 3: // March
        case 5: // May
        case 7: // July
        case 8: // August
        case 10: // October
        case 12: // December
            daysInMonth = 31;
            break;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            daysInMonth = 30;
            break;
        case 2: // February
            if (isLeapYear(year)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            printf("Invalid month!\n");
            return -1;
    }

    return daysInMonth;
}

int main() {
    int year, month;

    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    int numDays = countDays(year, month);

    if (numDays != -1) {
        printf("Number of days in the specified month: %d\n", numDays);
    }

    return 0;
}
