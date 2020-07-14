#include <stdio.h>

typedef double DISTANCE;

int main() {
    DISTANCE miles;
    printf("Please enter distance in miles: ");
    scanf("%lf", &miles);
    printf("%lf miles are %lf kilometers.\n", miles, miles * 1.609344);
    return 0;
}