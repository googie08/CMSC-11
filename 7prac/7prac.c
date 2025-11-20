#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("=== MALLOC EXAMPLE ===\n");

    int *a = malloc(3 * sizeof(int));  // allocate space for 3 integers

    if (a == NULL) {
        printf("malloc failed!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++)
        a[i] = (i + 1) * 10;

    printf("malloc data: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", a[i]);
    printf("\n\n");



    printf("=== CALLOC EXAMPLE ===\n");
    int *b = calloc(5, sizeof(int));  // 5 integers, all initialized to 0

    if (b == NULL) {
        printf("calloc failed!\n");
        free(a);
        return 1;
    }

    printf("calloc initial data: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", b[i]);  // prints zeros
    printf("\n");

    // assign values
    for (int i = 0; i < 5; i++)
        b[i] = i + 1;

    printf("calloc after assigning: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n\n");



    printf("=== REALLOC EXAMPLE ===\n");

    // resize array b from size 5 → size 8
    int *temp = realloc(b, 8 * sizeof(int));

    if (temp == NULL) {
        printf("realloc failed! Keeping original block.\n");
        free(b);
        free(a);
        return 1;
    }

    b = temp;  // update pointer after successful realloc

    // initialize new extra space
    for (int i = 5; i < 8; i++)
        b[i] = (i + 1) * 100;

    printf("realloc new data: ");
    for (int i = 0; i < 8; i++)
        printf("%d ", b[i]);
    printf("\n\n");

    printf("=== FREE EXAMPLE ===\n");
    free(a);
    free(b);

    printf("Memory freed successfully.\n");

    return 0;
}

