#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE(x) (sizeof(x) / sizeof(x[0]))

void fill_array(int nums[], size_t size, int digits) 
{
    srand(time(0));
    for(size_t i = 0; i < size; i++) {
        nums[i] = (rand() % digits) - (digits / 2);
    }
}

int order_by_closest_bigger(int nums[], int steps[], size_t size)
{
    int j = 0;
    steps[j] = nums[0];

    for(size_t i = 1; i < size; i++) {
        if (nums[i] > steps[j]) {
            steps[++j] = nums[i];
        }
    }

    return j + 1;
}

void print_elements(int nums[], int elements)
{
    for(int i = 0; i < elements; i++) {
        printf("%d: %d\n", i + 1, nums[i]);
    }
}

int main() 
{
    int steps, nums[100] = {}, ordered[100] = {};

    fill_array(nums, SIZE(nums), 200);
    steps = order_by_closest_bigger(nums, ordered, SIZE(nums));
    print_elements(ordered, steps);

    return 0;
}
