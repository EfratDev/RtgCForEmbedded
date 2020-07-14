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

void order_by_negative_positive(int nums[], int ordered_nums[], size_t size)
{
    int s = 0, e = 1, zero_count = 0, number;
    for(size_t i = 0; i < size; i++) {
        number = nums[i];
        if (nums[i] > 0) {
            ordered_nums[s] = nums[i];
            s++;
        } else if (nums[i] < 0) {
            ordered_nums[size - e] = nums[i];
            e++;
        } else {
            zero_count++;
        }
    }

    for (int i = 0; i <= zero_count; i++) {
        ordered_nums[s] = 0;
    }
}

int main() 
{
    int nums[100] = {}, ordered_nums[100] = {};

    fill_array(nums, SIZE(nums), 200);
    order_by_negative_positive(nums, ordered_nums, SIZE(nums));

    return 0;
}