#include <stdio.h>

int main() {
    char c;
    printf("Please  type a character: ");
    scanf("%c", &c);
    printf(
        "The ASCII number is: %d\n"
        "THe ASCII character is: %c\n"
        "The next ASCII number is: %d\n"
        "The next ASCII character is:%c\n",
        c, c, c + 1, c + 1);
    return 0;
}