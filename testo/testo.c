#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[100];
    char str2[100];
    char *str3;

    printf("String 1: ");
    scanf("%s", str1);
    printf("String 2: ");
    scanf("%s", str2);

    strcat(str1,str2);
    int length=strlen(str1);

    str3 = (char *)malloc((sizeof(char) * length)+1);
    printf("Output: %s", str3);
    printf("\nLength: %d", length);
    return 0;
}
