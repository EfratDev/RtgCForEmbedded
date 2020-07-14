#include <stdio.h>
// #include <ctype.h>

char lower(char letter) {
    if (65 <= letter && letter <= 90) {
        return letter + 32;
    } else {
        return letter;
    }
}

int main() {
    char a, b;
    printf(">>> ");
    scanf("%c%c", &a, &b);
    // a = tolower(a);
    // b = tolower(b);
    a = lower(a);
    b = lower(b);

    if (a >= b) {
        printf("%c%c\n", b, a);
    } else {
        printf("%c%c\n", a, b);
    }

    return 0;
}
