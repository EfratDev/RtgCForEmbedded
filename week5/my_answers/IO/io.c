#include <stdio.h>

void store_single_char(){
    int ch = getchar();
    while (ch!=EOF) {
        printf(".");
        putchar(ch);
        ch = getchar();
    }
}

void store_into_string() {
    char string[256];
    gets(string);
    puts(string);
}

int main() {
    store_into_string();
    store_single_char();
    return 0;
}