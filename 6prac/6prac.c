#include <stdio.h>

int main() {
    int a = 1;
    int *b = &a;
    int *c = &a;

    printf("c is %d\n", (*c)++);
    printf("b + a is %d\n", ++(*b) + a++);
    printf("a - b * c is %d\n", a-- - (*b)++ * --(*c));
}
