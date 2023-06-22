#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* boxPtr) {
    double volume = boxPtr->length * boxPtr->width * boxPtr->height;
    return volume;
}

double calculateSurfaceArea(struct Box* boxPtr) {
    double surfaceArea = 2 * (boxPtr->length * boxPtr->width +
                              boxPtr->length * boxPtr->height +
                              boxPtr->width * boxPtr->height);
    return surfaceArea;
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;

    // Input values for the box dimensions
    printf("Enter the length of the box: ");
    scanf("%lf", &(boxPtr->length));

    printf("Enter the width of the box: ");
    scanf("%lf", &(boxPtr->width));

    printf("Enter the height of the box: ");
    scanf("%lf", &(boxPtr->height));

    // Calculate and display the volume and surface area
    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Volume: %.2lf\n", volume);
    printf("Surface Area: %.2lf\n", surfaceArea);

    return 0;
}
