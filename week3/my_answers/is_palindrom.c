#include <stdio.h>


unsigned int reverse(unsigned int);


unsigned int reverse(unsigned int num) {
    unsigned int reversed = 0;
    while (num != 0) {
        reversed *= 10;
        reversed += num % 10;
        num /= 10;
    }
    return reversed;
}


int main() {
    unsigned int num;
    printf("Please enter a positive number: ");
    scanf("%u", &num);
    if (reverse(num) == num) {
        printf("The number is a palindrom number.\n");
    } else {
        printf("The number is not a palindrom number.\n");
    }
    return 0;
}
