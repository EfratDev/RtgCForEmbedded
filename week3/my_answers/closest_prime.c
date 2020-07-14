#include <stdio.h>


int is_prime(unsigned int num) {
    for (unsigned int i = 2; i < num; i ++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}


unsigned int get_closest_prime(unsigned int num) {
    unsigned int unit = 0;
    while (1) {
        if (is_prime(num + unit)) {
            return num + unit;
        } else if (is_prime(num - unit)) {
            return num - unit;
        } else {
            unit ++;
        }
    }
}


int main() {
    unsigned int num, closest_prime;
    printf("Please enter an integer: ");
    scanf("%d", &num);
    closest_prime = get_closest_prime(num);
    printf("The closest prime is %d.\n", closest_prime);
    return 0;
}
