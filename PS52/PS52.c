#include <stdio.h>
int numCounter(int [], int, int);

int main() {
    int numbers[10], toCheck;
    int SIZE = 0, i = 0;

    printf("How many numbers do you want to store (1-10)? ");
    scanf("%d", &SIZE);
    printf("\n");

    if(SIZE<=0){
        printf("Invalid Input\n");
        return 0;
    }
    else if(SIZE>10){
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
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] == toCheck) {
            count++;
        }
    }
    return count;
}

