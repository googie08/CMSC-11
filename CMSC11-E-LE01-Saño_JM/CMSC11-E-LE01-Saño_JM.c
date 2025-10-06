#include <stdio.h>

int main() {
    int num, a, b, c, d, e, reverse;                        /* Initialize variables where:
                                                                num = 5 digit user input
                                                                a, b, c, d, e = digits
                                                                reverse = reversed 5-digit number */

    printf("----------------------------------------\n\n"); /* Aesthetic purposes */
    printf("Reverse a 5-digit number\n\n");                 /* Title of the exercise */

    /* Note that the code will only function properly if the user inputs a 5-digit integer*/

    printf("Input a 5-digit number: ");                     /* Asks for user input */
    scanf("%d", &num);                                      /* Accepts integer input of user*/

    a = num / 10000;                                        /* Gets 1st digit of num*/
    b = (num % 10000) /1000;                                /* Gets 2nd digit of num*/
    c = (num % 1000) / 100;                                 /* Gets 3rd digit of num*/
    d = (num % 100) / 10;                                   /* Gets 4th digit of num*/
    e = num % 10;                                           /* Gets 5th digit of num*/

    reverse = e * 10000 + d * 1000 + c * 100 + b * 10 + a;  /* Rearranges digits into its reverse order,
                                                            multiplies each according to its corresponding place,
                                                            and combines them into a single number */

    printf("Reversed number: %d\n\n", reverse);             /* Displays the final output */
    printf("--------------------------------");             /* Aesthetic purposes */

    return 0;
}
