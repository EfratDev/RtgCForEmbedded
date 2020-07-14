#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
        nums[i] = rand() % DIGITS - DIGITS / 2;
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


void print_digits_of_array(int * array, size_t size) {
    int printed;
    for (int i = 0; i < size; i++) {
        printed = false;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                printed = true;
            }
        }
        if (!printed) {
            printf("%d) %d.\n", i, array[i]);
        }
    }
}

int main() {
    size_t array_size = rand_size(50, 50);
    int * array = get_filled_array(array_size);

    print_array(array, array_size);
    printf("Unique digits: \n");
    print_digits_of_array(array, array_size);
    free(array);
    return EXIT_SUCCESS;
}
