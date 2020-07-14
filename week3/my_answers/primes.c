#include <stdio.h>


int is_prime(unsigned int num) {
    for (unsigned int i = 2; i < num; i ++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}


unsigned int get_next_prime(unsigned int num) {
    unsigned int next_prime = num + 1;
    if (next_prime <= 3) {
        return next_prime;
    }

    while (!is_prime(next_prime)) {next_prime++;} // for loop?
   
    return next_prime;
}


long int product(unsigned int primes[], size_t primes_size) {
    long int product = 1;
    for (int i = 0; i < primes_size; i++) {
        if (primes[i] == 0) {
            return 0;
        }

        product *= primes[i];
    }

    return product;
}

void get_primes_factors(unsigned int primes[],size_t size, unsigned int num) {
    unsigned int temp_factor = num, 
        next_prime = 2,
        i = 0;
    while (product(primes, size) < num) {
        while (temp_factor % next_prime != 0) {
            next_prime = get_next_prime(next_prime);
        }
        temp_factor /= next_prime;
        primes[i] = next_prime;
        i++;
    }
}


int main() {
    unsigned int num, primes[32] = {[0 ... 31] = 1};
    printf("Get me the primes factors of the number: ");
    scanf("%u", &num);
    
    get_primes_factors(primes, sizeof(primes), num);

    for (unsigned int j = 0; (j < 32) && (primes[j] != 1); j++) {
        switch (j) {
            case 0:
                printf("%u = %u", num, primes[j]);
                break;
            default:
                printf(" * %u", primes[j]);
        }
    }

    printf("\n");
    return 0;
}
