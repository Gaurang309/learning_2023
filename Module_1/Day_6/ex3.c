#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time* startTime, struct Time* endTime) {
    struct Time difference;
    int startSeconds, endSeconds, diffSeconds;

    // Convert start time to seconds
    startSeconds = startTime->hours * 3600 + startTime->minutes * 60 + startTime->seconds;

    // Convert end time to seconds
    endSeconds = endTime->hours * 3600 + endTime->minutes * 60 + endTime->seconds;

    // Calculate the difference in seconds
    diffSeconds = endSeconds - startSeconds;

    // Convert difference back to hours, minutes, and seconds
    difference.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    difference.minutes = diffSeconds / 60;
    difference.seconds = diffSeconds % 60;

    return difference;
}

int main() {
    struct Time startTime, endTime, difference;

    // Input values for start time
    printf("Enter the start time\n");
    printf("Hours: ");
    scanf("%d", &(startTime.hours));
    printf("Minutes: ");
    scanf("%d", &(startTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(startTime.seconds));

    // Input values for end time
    printf("\nEnter the end time\n");
    printf("Hours: ");
    scanf("%d", &(endTime.hours));
    printf("Minutes: ");
    scanf("%d", &(endTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(endTime.seconds));

    // Calculate the difference between the time periods
    difference = calculateTimeDifference(&startTime, &endTime);

    // Display the difference
    printf("\nTime difference: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
