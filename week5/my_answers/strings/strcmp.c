#include <stdio.h>
#include <string.h>

int main() {
    char fruit[] = "apple";
    char guess[80];
    do {
        printf("Guess my favorite fruit? ");
        gets(guess);
    } while (strcmp(fruit, guess));
    puts("Correct Answer!");
    return 0;
}