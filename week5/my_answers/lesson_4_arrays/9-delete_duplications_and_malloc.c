#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS (100)
#define DIGITS (400)

void fill_array(int nums[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        nums[i] = rand() % DIGITS - DIGITS / 2;
    }
}

void sort(int nums[], size_t size) {
    int temp;
    for (size_t i = 1; i < size; i++) {
        for (size_t j = i; j > 0; j--) {
            if (nums[j] < nums[j - 1]) {
                temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
}

void check_malloc(int nums[]) {
    if (nums == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

size_t rand_elements_num() {
    srand(time(0));
    size_t elements_num = rand() % (MAX_ELEMENTS + 1);
    return elements_num;
}

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

size_t delete_duplications(int * nums, size_t size) {
    int i = 1;
    for (int j = 1; j < size; j++) {
        if (nums[j] != nums[j - 1]) {
            nums[i++] = nums[j];
        }
    }
    return i;
}

int main() {
    size_t elements_num = rand_elements_num();
    int * nums = (int *) malloc( elements_num * sizeof(int));
    check_malloc(nums);
    printf("Created array with %d elememnts.\n", elements_num);
    fill_array(nums, elements_num);
    sort(nums, elements_num);
    print_array(nums, elements_num);
    size_t new_size = delete_duplications(nums, elements_num);
    printf("Deleted duplictions, new size is %d.\n", new_size);
    print_array(nums, new_size);
    free(nums);
    nums = NULL;
    return 0;
}
