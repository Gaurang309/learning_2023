#include <stdio.h>

void print_bits(int num) {
    int i;
    unsigned int mask = 1 << 31; // Start with the most significant bit

    for (i = 0; i < 32; i++) {
        int bit = (num & mask) ? 1 : 0;
        printf("%d", bit);
        
        // Print a space after every 8 bits for better readability
        if ((i + 1) % 8 == 0) {
            printf(" ");
        }
        
        mask >>= 1; // Move the mask to the right
    }
}

int main() {
    int num;
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);
    printf("Bits: ");
    print_bits(num);
    printf("\n");
    return 0;
}