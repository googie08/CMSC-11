#include <stdio.h>

/* pyramid */

int main() {
    int n, i, j, space;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (space = 1; space <= n - i; space++) {
            printf("  ");
        }

        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Print descending numbers
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n"); // 3move to next row
    }

    return 0;
}
