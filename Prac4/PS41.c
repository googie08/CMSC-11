#include <stdio.h>

void printMenu();
int getNumber();
int add(int, int);
int sub(int, int);
int mult(int, int);
double div(int, int);

int main() {
    int num1, num2, choice;
    double result;

    printf("Welcome to Simple Calculator!\n");
    num1 = getNumber();
    num2 = getNumber();

    printMenu();
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = add(num1, num2);
            printf("\nThe sum of %d and %d is %.0f.\n", num1, num2, result);
            break;

        case 2:
            result = sub(num1, num2);
            printf("\nThe difference between %d and %d is %.0f.\n", num1, num2, result);
            break;

        case 3:
            result = mult(num1, num2);
            printf("\nThe product of %d and %d is %.0f.\n", num1, num2, result);
            break;

        case 4:
            if (num2 == 0) {
                printf("Error: Undefined\n");
            } else {
                result = div(num1, num2);
                printf("\nThe quotient of %d and %d is %.2f.\n", num1, num2, result);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}



int getNumber() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("  1. Addition\n");
    printf("  2. Subtraction\n");
    printf("  3. Multiplication\n");
    printf("  4. Division\n");
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

double div(int a, int b) {
    return (double) a / b;
}

