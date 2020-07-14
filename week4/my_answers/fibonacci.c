#include <stdio.h>

unsigned int get_fibo_num(unsigned int i) {
    if (i <= 2) {
        return 1;
    }

    unsigned int a = 1, b = 1;
    for (unsigned int j = 2; j <= i; j++) {
        b += a;
        a = b - a;
    }

    return b;
}

int main() {
    unsigned int i;
    
    printf("Which num in fibonacci would you like to see? (positive num) ");
    scanf("%u", &i);

    if (i == 0) {
        printf("No such fibonacci element.\n");
    } else {
        printf("The %u fibonacci num is: %u\n", i, get_fibo_num(i));
    }

    return 0;
}
