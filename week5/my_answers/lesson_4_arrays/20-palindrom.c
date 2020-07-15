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

bool is_palindrom(int *nums, size_t size) {
    for(int i = 0; i < size / 2; i++) {
        if (nums[i] != nums[size - i - 1]) {
            return false;
        }
    }
    return true;
}


bool is_subpalindrom(int *nums, int start, size_t palindrom_size) {
    for(int i = 0; i < palindrom_size / 2; i++) {
        if (nums[start + i] != nums[start + palindrom_size - i - 1]) {
            return false;
        }
    }
    return true;
}

int get_max_palindrom_subarray(int *nums, size_t size, int *palindrom_i) {
    *palindrom_i = NOWHERE;
    int max_palindrom_units = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 2; j < size; j ++){
            if (is_subpalindrom(nums, i, j) && j > max_palindrom_units) {
            max_palindrom_units = j;
            *palindrom_i = i;
            }
        }
    }

    return max_palindrom_units;
}

int main() {
    int palindrom_i;
    size_t size = rand_size(10, 10);
    int *nums = get_filled_array(size);
    
    print_array(nums, size);

    int max_palindrom_units = get_max_palindrom_subarray(nums, size, &palindrom_i);
    if (max_palindrom_units > 1) {
        printf("The biggest palindrom in the array is of %d units, starts at %d place.\n", max_palindrom_units, palindrom_i);
    } else {
        printf("No subarray which is palindrom.\n");
    }
    
    if (is_palindrom(nums, size)) {
        printf("Palindrom.\n");
    } else {
        printf("Not a palindrom.\n");
    }

    free(nums);
    return EXIT_SUCCESS;
}
