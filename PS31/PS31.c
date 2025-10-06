#include <stdio.h>

int main() {
    int num;

    printf("---------------------------------\n\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num%11 == 0) {
        printf("%d is a special number", num);
    }
    else if (((num-1)%11) == 0) {
        printf("%d is a special number", num);
    }
    else {
        printf("%d is NOT a special number", num);
    }

    printf("\n\n---------------------------------\n\n");

    return 0;
}
