#include <stdio.h>

int main() {
    int num = 0, count = 0;
    float sum = 0, average = 0;

    printf("---------------------------------\n\n");

    /* Will only work with integers */

    while (num != -1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num >= 0) {
            sum = sum + num;
            count++;
        }
    }

    if (count > 0) {
        average = sum / count;
    }

    printf("The average is %.1f", average);
    printf("\n\n---------------------------------\n");

    return 0;
}

