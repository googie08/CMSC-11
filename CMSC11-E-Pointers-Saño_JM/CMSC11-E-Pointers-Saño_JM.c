#include <stdio.h>

int Odd(int *, int, int, int *);
int Even(int *, int, int, int *);

int main() {
    long input;
    int num[100];
    int *ptr = num;
    int length = 0, max = 0;

    /* Asks for user input (code does not work for negative numbers T^T)*/
    printf("Enter a number: ");
    scanf("%ld", &input);

    /* Counts digits */
    long x = input;
    while (x > 0) {
        length++;
        x = x / 10;
    }

    /* Store digits into array */
    for (int i = length - 1; i >= 0; i--) {
        *(ptr + i) = input % 10;
        input = input / 10;
    }

    /* Checks for palindromes */
    int start = -1;
    for (int i = 1; i < length; i++) {
        int oddMax = Odd(ptr, length, i, &start);
        int evenMax = Even(ptr, length, i, &start);

        if (oddMax > max) max = oddMax;
        if (evenMax > max) max = evenMax;
    }

    /* Prints outputs */
    if (max >= 2) {
        printf("Longest Palindrome: ");
        for (int i = start; i < start + max; i++) {
            printf("%d", *(ptr + i));
        }
        printf("\nLength: %d\n", max);
    } 
    else printf("No palindromes in this number\n");
    return 0;
}

/* Function that checks odd palindromes */
int Odd(int *ptr, int length, int i, int *start) {
    int temp = 1;
    int max = 0;
    for (int k = 1; (i - k >= 0) && (i + k < length) && (*(ptr + i - k) == *(ptr + i + k)); k++) {
        temp += 2;
        if (temp > max) {
            max = temp;
            *start = i - k;
        }
    }
    return max;
}

/* Function that checks even palindromes */
int Even(int *ptr, int length, int i, int *start) {
    int temp = 0;
    int max = 0;
    for (int k = 0; (i - k >= 0) && (i + 1 + k < length) && (*(ptr + i - k) == *(ptr + i + 1 + k)); k++) {
        temp += 2;
        if (temp > max) {
            max = temp;
            *start = i - k;
        }
    }
    return max;
}
