#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define DIGITS (1000)

void print_array(int nums[],size_t size) {
    printf("%d elememnts Array:\n", size);
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

bool check_same_digits(int *nums1, int *nums2, size_t size) {
    int same = true;
    int *digits = (int *)malloc(size * sizeof(int));
    check_malloc(digits);
    memset(digits, 0, size);
    
    for (int i = 0; i < size; i++) {
        digits[nums1[i]] = 1;
    }

    for (int i = 0; i < size; i++) {
        if (digits[nums2[i]] == 0) {
            same = false;
        } else {
            digits[nums2[i]] = 2;
        }
    }

    for (int i = 0; i < size; i++) {
        if (digits[i] == 1) {
            same = false;
        }
    }

    free(digits);
    return same;
}

int main() {
    size_t size = rand_size(100, 100);
    int *nums1 = get_filled_array(size);
    int *nums2 = get_filled_array(size);

    print_array(nums1, size);
    print_array(nums2, size);

    int is_same = check_same_digits(nums1, nums2, size);
    if (is_same) {
        printf("Same digits.\n");
    } else {
        printf("Not the same digits.\n");
    }

    free(nums1);
    free(nums2);
    return EXIT_SUCCESS;
}
