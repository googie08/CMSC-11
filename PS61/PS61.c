#include <stdio.h>

int main() {
    int numbers[10];
    int SIZE = 0, count = 0, valid = 0;
    int *p;

    printf("How many numbers do you want to store in the array (1-10)? ");
    scanf("%d", &SIZE);
    printf("\n");

    if (SIZE <= 0 || SIZE > 10) {
        printf("Invalid Input\n");
        return 0;
    }

    for (p = numbers; p < numbers + SIZE; p++) {
        printf("Enter number[%ld]: ", p - numbers + 1);
        scanf("%d", p);
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

    if (count == 3 && valid == 0) printf("\nTRUE\n");
    else printf("\nFALSE\n");

    return 0;
}
