#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DIGITS (10)
#define NO_DUPLICATES -1

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

int find_longest_homogeneous_subarray(int * array, size_t size) {
    int max = 0, max_i = NO_DUPLICATES, duplicates_counter = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] == array[i-1]) {
            duplicates_counter++;
            if (duplicates_counter > max) {
                max = duplicates_counter;
                max_i = i - max;
            }

        } else {
            duplicates_counter = 0;
        }
    }

    return max_i;
}

int main() {
    size_t size = rand_size(100, 100);

    int * array = get_filled_array(size);
    printf("Created array with %d elememnts.\n", size);
    print_array(array, size);

    int i = find_longest_homogeneous_subarray(array, size);
    if (i != NO_DUPLICATES) {
        printf("The longest homogeneous subarray is starting at %d.\n", i);
    } else {
        printf("No duplications in the array.\n");
    }

    free(array);
    return EXIT_SUCCESS;
}
