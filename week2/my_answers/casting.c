#include <stdio.h>


int main() {
    int num = 0, digit1, digit2, digit3;
    while (num > 999 || num < 100) {
        printf("Please enter a number with 3 digits: ");
        scanf("%d", &num);
    }
    digit1 = num / 100;
    digit2 = (num / 10) % 10;
    digit3 = num % 10;
    printf("digit1: %d\ndigit2: %d\ndigit3: %d\n", digit1, digit2, digit3);
    return 0;
}