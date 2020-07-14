#include <stdio.h>


void count_digits(unsigned int *, unsigned int);


void count_digits(unsigned int occurrences[], unsigned int num){
    unsigned int digit;
    while (num > 0) {
        digit = num % 10;
        num /= 10;
        occurrences[digit] += 1;
    }
}


int main() {
    unsigned int num, digit, occurrences[10] = {};
    printf("Please enter a positive num: ");
    scanf("%u", &num);
    count_digits(occurrences, num);
    printf("Digit: Occurrences\n");
    for (digit = 0; digit <= 9; digit++) {
        if (occurrences[digit]) {
            printf("%u: %u\n", digit, occurrences[digit]);
        }
    }

    return 0;
}