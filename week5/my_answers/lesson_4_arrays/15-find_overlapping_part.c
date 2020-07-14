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


void overplap_func_variables_check(size_t overlapping_size, size_t array1_size, size_t array2_size) {
    if (overlapping_size > array1_size || overlapping_size > array2_size) {
        printf("overlapping size must be smaller than arrays to overlap.\n");
        exit(EXIT_FAILURE);
    }
}

void overlap_end_with_beginning(
    size_t overlapping_size, 
    int * array1, 
    size_t array1_size, 
    int * array2,
    size_t array2_size
    ) {
    overplap_func_variables_check(overlapping_size, array1_size, array2_size);
    for (int i = 0; i < overlapping_size; i++) {
        array1[array1_size - overlapping_size + i] = array2[i];
    }
}


int get_overlapping_end_with_beginning_size(
    int * array1, 
    size_t array1_size, 
    int * array2,
    size_t array2_size
    ) {
    int is_size_overlap, size;
    int smallest = (array1_size > array2_size) ? array2_size : array1_size;

    for (size = smallest; size > 0; size--) {
        is_size_overlap = true;
        for (int j = 0; j < size; j++) {
            if (array1[array1_size - size + j] != array2[j]) {
                is_size_overlap = false;
            }
        }

        if (is_size_overlap) {
            return size;
        }
    }
    return size;
}

int main() {
    int reversed_overlapping_size;
    size_t array1_size = rand_size(10, 10);
    size_t array2_size = rand_size(10, 10);
    size_t overlapping_size = rand_size(1, array1_size);

    int * array1 = get_filled_array(array1_size);
    int * array2 = get_filled_array(array2_size);
    overlap_end_with_beginning(
        overlapping_size, 
        array1, 
        array1_size, 
        array2, 
        array2_size
    );

    printf("Created array with %d elememnts.\n", array1_size);
    print_array(array1, array1_size);

    
    printf("Created array with %d elememnts.\n", array2_size);
    print_array(array2, array2_size);

    reversed_overlapping_size = get_overlapping_end_with_beginning_size(
        array1, 
        array1_size, 
        array2, 
        array2_size
    );
    printf(
        "The last %d elements in the first array "
        "are the overlapping with the first element"
        "in the second array.\n"
        , reversed_overlapping_size
    );

    free(array1);
    free(array2);
    return EXIT_SUCCESS;
}