#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[20];
};

struct LogEntry logData[MAX_ENTRIES];
int numEntries = 0;

void extractData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    // Skip the header line
    fgets(line, MAX_LINE_LENGTH, file);

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line by comma
        char *token;
        token = strtok(line, ",");

        logData[numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logData[numEntries].sensorNo, token);

        token = strtok(NULL, ",");
        logData[numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        logData[numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        logData[numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logData[numEntries].timestamp, token);

        numEntries++;
    }

    fclose(file);
}

void displayData() {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t%.1f\t\t%d\t\t%d\t%s\n", logData[i].entryNo, logData[i].sensorNo, logData[i].temperature,
               logData[i].humidity, logData[i].light, logData[i].timestamp);
    }
}

int main() {
    extractData("data.csv");
    displayData();
    return 0;
}
