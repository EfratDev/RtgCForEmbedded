#include <stdio.h>
#include <math.h>

int main() {
    int integer;
    printf(">>> ");
    scanf("%d", &integer);

    if ((integer % 2) == 0) {
        printf("The number is odd.\n");
    } else {
        printf("The number is even.\n");
    }

    int is_prime = 1;
    for (int i=2; i<integer; i++){
        if (integer % i == 0) {
            is_prime = 0;
        }
    }

    if (is_prime) {
        printf("The number is prime.\n");
    } else {
        printf("The number is not prime.\n");
    }

    double root = sqrt(integer);
    if (floor(root) == root) {
        printf("The number has root.\n");
    } else {
        printf("The number doesn't have root.\n");
    }
    
    return 0;
}
