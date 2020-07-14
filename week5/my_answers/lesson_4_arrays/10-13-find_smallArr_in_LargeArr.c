#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DIGITS (10)
#define NOWHERE -1

void print_array(int nums[],size_t size) {
    if (size == 0) {
        printf("Empty array.\n");
        return;
    }

    printf("This is what's inside the array:\n");
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

void check_params(size_t large_size, size_t small_size) {
     if (small_size > large_size) {
        exit(EXIT_FAILURE);
    }
}

bool is_here(int * small_array, size_t small_size, int * large_array, size_t l) {
    for (size_t s = 0; s < small_size; s++) {
        if (large_array[l + s] != small_array[s]) {
            return false;
        }
    }
    return true;
}

int where(int * large_array, size_t large_size, int * small_array, size_t small_size) {
    check_params(large_size, small_size);
    for (size_t l = 0; l < large_size; l++) {
        if (is_here(small_array, small_size, large_array, l)) {
            return l;
        }
    }
    return NOWHERE;
}

int main() {
    size_t large_array_size = rand_size(1000, 1000);
    size_t small_array_size = rand_size(3, 3);

    int * large_array = get_filled_array(large_array_size);
    int * small_array = get_filled_array(small_array_size);

    printf("Created array with %d elememnts.\n", large_array_size);
    print_array(large_array, large_array_size);

    
    printf("Created array with %d elememnts.\n", small_array_size);
    print_array(small_array, small_array_size);

    int i = where(large_array, large_array_size, small_array, small_array_size);
    if (i != NOWHERE) {
        printf("The second array is inside the first array, it starts at the %d index.\n", i);
    } else {
        printf("The second array is not a subarray of the first array.\n");
    }

    free(large_array);
    free(small_array);
    return EXIT_SUCCESS;
}