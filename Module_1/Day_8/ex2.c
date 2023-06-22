#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 4096

void changeCase(char *buffer, int option) {
    switch (option) {
        case 1: // -u: Change to Upper Case
            for (int i = 0; buffer[i] != '\0'; ++i) {
                buffer[i] = toupper(buffer[i]);
            }
            break;
        case 2: // -l: Change to Lower Case
            for (int i = 0; buffer[i] != '\0'; ++i) {
                buffer[i] = tolower(buffer[i]);
            }
            break;
        case 3: // -s: Change to Purely Upper Case
            for (int i = 0; buffer[i] != '\0'; ++i) {
                if (islower(buffer[i])) {
                    buffer[i] = toupper(buffer[i]);
                }
            }
            break;
        default: // No option: Normal copy
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    int option = 0;
    char *sourcePath = argv[2];
    char *destinationPath = argv[3];

    // Get the option if provided
    if (argc > 3) {
        if (strcmp(argv[1], "-u") == 0) {
            option = 1;
        } else if (strcmp(argv[1], "-l") == 0) {
            option = 2;
        } else if (strcmp(argv[1], "-s") == 0) {
            option = 3;
        }
    }

    FILE *sourceFile, *destinationFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the destination file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        changeCase(buffer, option);
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}
