#include <stdio.h>
#include <stdbool.h>

int main() {
    // BOOLEANS
    bool is_false = false;
    /*
        not actually 1-bit
        bool expands to _Bool, which is an alias for int
        true -> 1, false -> 0, both are integers too
    */
   printf("%d\n", is_false);

    // CONDITIONALS
    if ('\0') {
        printf("true\n");
    } else {
        printf("false\n");
    }

    // STRINGS
    char name[] = "John"; // J o h n \0
    printf("%d\n", name[4]); // 0
    for (int i = 0; name[i]; i++) {
        printf("%c\n", name[i]);
    }
    
    return 0;
}
