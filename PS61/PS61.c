#include <stdio.h>

int main(void) {
    int numbers[10];
    int SIZE = 0, i = 0, count = 0;
    int *p;

    printf("Enter size: ");
    scanf("%d", &SIZE);

    if (SIZE <= 0 || SIZE > 10) {
        printf("Invalid size\n");
        return 0;
    }

    while (i < SIZE) {
        printf("Enter number[%d]: ", i + 1);
        scanf("%d", &numbers[i]);
        i++;
    }

    for (p = numbers; p < numbers + SIZE; p++) {
        if (*p == 3) {
            count++;
            if ((p + 1 < numbers + SIZE) && (*(p + 1) == 3)) {
                printf("\nFALSE\n");
                return 0;
            }
        }
    }

    if (count == 3)
        printf("\nTRUE\n");
    else
        printf("\nFALSE\n");

    return 0;
}
