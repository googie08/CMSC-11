#include <stdio.h>
#include <string.h>

int main() {
    char dest[5];              // Only space for 4 chars + '\0'
    char src[] = "Hello!";     // 6 characters + '\0'

    printf("Before strcpy: dest = \"%s\"\n", dest);

    strcpy(dest, src);         // <-- Overflow happens here!

    printf("After strcpy: dest = \"%s\"\n", dest);

    return 0;
}
