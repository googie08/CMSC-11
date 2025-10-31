#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    int chars = 0, vowels = 0, consonants = 0, upper = 0, lower = 0;

    printf("Enter a string: ");
    gets(input);

    int length = strlen(input);

    for (int i = 0; i<length; i++) {
        if (!isspace(input[i]))
            chars++;

        if (isupper(input[i]))
            upper++;
        else if (islower(input[i]))
            lower++;

        if (isalpha(input[i])) {
            char temp = tolower(input[i]);
            if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("\nNumber of characters: %d\n", chars);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of uppercase: %d\n", upper);
    printf("Number of lowercase: %d\n", lower);

    return 0;
}
