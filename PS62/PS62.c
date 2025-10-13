#include <stdio.h>
int numCounter(int[], int, int, int*);

int main() {
    int numbers[10], toCheck;
    int SIZE = 0;
    int *p;

    printf("How many numbers do you want to store (1-10)? ");
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

    printf("\nNumber to Count: ");
    scanf("%d", &toCheck);

    int count = numCounter(numbers, SIZE, toCheck, p);
    printf("Instance Count: %d\n", count);

    return 0;
}

int numCounter(int numbers[], int SIZE, int toCheck, int *p) {
    int count = 0;
    for (p = numbers; p < numbers + SIZE; p++) {
        if (*p == toCheck) count++;
    }
    return count;
}


