#include <stdio.h>

int main() {
    int x, y, z, large, medium, small;

    /* Note that the code will only work for integers*/

    printf("---------------------------------\n\n");
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("Enter a number: ");
    scanf("%d", &y);
    printf("Enter a number: ");
    scanf("%d", &z);

    large = x;
    if (y > large) {
        large = y;
    }
    if (z > large) {
        large = z;
    }

    small = x;
    if (y < small) {
        small = y;
    }
    if (z < small) {
        small = z;
    }

    /* Note that if two inputs have the same value,
        the integers are not evenly spaced*/

    medium = x+y+z - (large + small);

    if ((large - medium) == (medium - small)) {
        printf("\n%d, %d, and %d are evenly spaced", x, y, z);
    } else {
        printf("\n%d, %d, and %d are NOT evenly spaced", x, y, z);
    }
    printf("\n\n---------------------------------");

    return 0;
}
