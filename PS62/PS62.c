#include <stdio.h>
int numCounter(int[], int, int);

int main() {
    int numbers[10], toCheck;
    int SIZE = 0, i = 0;

    printf("Enter size(1-10)? ");
    scanf("%d", &SIZE);
    printf("\n");

    if (SIZE <= 0 || SIZE > 10) {
        printf("Invalid Input\n");
        return 0;
    }

    while(i < SIZE){
        printf("Enter number[%d]: ", i+1);
        scanf("%d", &numbers[i]);
        i++;
    }

    printf("\nNumber to Count: ");
    scanf("%d", &toCheck);

    int count = numCounter(numbers, SIZE, toCheck);
    printf("Instance Count: %d\n", count);

    return 0;
}

int numCounter(int numbers[], int SIZE, int toCheck) {
    int count = 0;
    int *p;
    for (p = numbers; p < numbers + SIZE; p++) {
        if (*p == toCheck) count++;
    }
    return count;
}


