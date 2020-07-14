#include <stdio.h>

#define SIZE(x)  (sizeof(x) / sizeof(x[0]))

void left_array(int nums[], size_t size) {
    int temp = nums[0];

    for (int i = 1; i < size; i++) {
        nums[i - 1] = nums[i];
    }

    nums[size - 1] = temp;
}

void reverse_array(int nums[], size_t size) {
    int temp;

    for (int i = 0; i < size / 2; i++) {
        temp = nums[i];
        nums[i] = nums[size - 1 - i];
        nums[size -1 - i] = temp;
    }
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

int get_max(int nums[], size_t size) {
    int max = nums[0];
    
    for (size_t i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    return max;
}

void sort_large_to_small(int nums[], size_t size) {
    int j;
    for(int i = 1; i < size; i++) {
        j = i;
        while (nums[j] > nums[j - 1] && j > 0) {
            int temp = nums[j - 1];
            nums[j - 1] = nums[j];
            nums[j] = temp;
            j--;
        }
    }
}

int main() {
    int i, nums[10] = {};
    
    for (i = 0; i < SIZE(nums); i++) {
        printf("Please type the %d number: ", i + 1);
        scanf("%d", &nums[i]);
    }

    print_array(nums, SIZE(nums));

    if (SIZE(nums) == 0) {
        printf("No max number, empty array.\n");
    } else {
        printf("The max number in the array is %d.\n", get_max(nums, SIZE(nums)));
    }

    reverse_array(nums, SIZE(nums));
    printf("We reversed the array.\n");
    print_array(nums, SIZE(nums));

    left_array(nums, SIZE(nums));
    printf("We left the array with 1 place.\n");
    print_array(nums, SIZE(nums));

    sort_large_to_small(nums, SIZE(nums));
    printf("We sorted the array from the largest number to the smallest.\n");
    print_array(nums, SIZE(nums));
    
    return 0;
}
