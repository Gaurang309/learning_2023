#include <stdio.h>

int main() {
    int i, x,n;
    
    printf("Enter a number of rows : ");
    scanf("%d",&n);
    for (i = n, x = 0; i >= 1; i--, x += 2) {
        int j, y, k;

        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        for (y = 1; y <= x; y++) {
            printf(" ");
        }

        for (k = i; k >= 1; k--) {
            printf("%d", k);
        }

        printf("\n");
    }

    return 0;
}