#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE(x) (sizeof(x) / sizeof(x[0]))

void fill_array_with_rand_range_errors_check(
        unsigned int range_begin, 
        unsigned int range_end
    ) {
    if (range_end < range_begin) {
        fprintf(
            stderr, 
            "parameter range_end can't be bigger than parameter range_begin.\n"
        );
        exit(1);
    }
}

void fill_array_with_rand_range(
        unsigned int nums[], 
        size_t size, 
        unsigned int range_begin, 
        unsigned int range_end
    ) {
    fill_array_with_rand_range_errors_check(range_begin, range_end);
    srand(time(0));
    
    for (size_t i = 0; i < size; i++) {
        nums[i] = (rand() % (range_end - range_begin + 1)) + range_begin;
    }
}

void count_digits(unsigned int nums[], size_t size, unsigned int digits[]) {
    for (size_t i = 0; i < size; i++) {
        digits[nums[i]] += 1;
    }
}

void print_digits(
        unsigned int digits[], 
        unsigned int range_begin, 
        unsigned int range_end
    ) {
    int sum = 0;
    
    printf("Digit) Occurences.\n");
    for (unsigned int i = range_begin; i <= range_end; i++) {
        printf("%d) %d.\n", i, digits[i]);
        sum += digits[i];
    }

    printf("Sum of digits: %d.\n", sum);
}

int main() {
    unsigned int nums[100] = {}, digits[11] = {};

    fill_array_with_rand_range(
        nums, 
        SIZE(nums), 
        (unsigned int) 1, 
        (unsigned int) 10
        );
    count_digits(nums, SIZE(nums), digits);
    print_digits(digits, 1, 10);

    return 0;
}
