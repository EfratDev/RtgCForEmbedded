#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define DIGITS (10)
#define NOWHERE -1

void print_array(int nums[],size_t size) {
    printf("Array with %d elements.\n", size);
    for (size_t i = 0; i < size; i++) {
        printf("%d) %d\n", i, nums[i]);
    }
}

void check_malloc(int nums[]) {
    if (nums == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void fill_array(int nums[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        nums[i] = rand() % DIGITS;
    }
}

size_t rand_size(int min_elements, int max_elements) {
    srand(time(0));
    return rand() % (max_elements - min_elements + 1) + min_elements;
}

int * get_filled_array(int size) {
    int * nums = (int *) malloc( size * sizeof(int));
    check_malloc(nums);
    fill_array(nums, size);
    return nums;
}

void print_common_element(int * array, size_t size) {
    int * digits = (int *)malloc((size + 1)* sizeof(int));
    check_malloc(digits);
    memset(digits, 0, size);

    int max = 0, common_digit;
    for (int i = 0; i < size; i++) {
        if (++digits[array[i]] > max){
            max = digits[array[i]];
            common_digit = array[i];
        }
    }
    
    free(digits);
    printf("The most common digit in the array is %d, with %d duplications.\n", common_digit, max);
}

int main() {
    size_t size = rand_size(50, 50);
    int * array = get_filled_array(size);

    print_array(array, size);
    print_common_element(array, size);
    free(array);
    return EXIT_SUCCESS;
}
