#include <stdio.h>
#include <stdlib.h>

int get_sum(int x, int y) {
    return x + y;
}

int get_absolute_difference(int x, int y) {
    return abs(x - y);
}

int get_multyple(int x, int y) {
    return x * y;
}

float get_division(int x, int y) {
    return x / (float)y;
}

int main() {
    while (1) {
        int x, y;
        unsigned int operate;

        printf("Enter 2 numbers 'x,y': ");
        scanf("%d,%d", &x, &y);
        printf("Which operate would you want to do?\n"
            "1) %d + %d\n"
            "2) |%d - %d|\n"
            "3) %d * %d\n"
            "4) %d / %d\n"
            ">>> "
            , x, y, x, y, x, y, x, y);
        scanf("%u", &operate);

        switch(operate) {
            case 1:
                printf("%d + %d = %d\n", x, y, get_sum(x, y));
                break;
            case 2:
                printf("|%d - %d| = %d\n", x, y, get_absolute_difference(x, y));
                break;
            case 3:
                printf("%d * %d = %d\n", x, y, get_multyple(x, y));
                break;
            case 4:
                printf("%d / %d = %.3f\n", x, y, get_division(x, y));
        }
    }
    return 0;
}