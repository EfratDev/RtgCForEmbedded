#include <stdio.h>

void get_dividing_nums(int num1, int num2, int nums[]) {
    unsigned int j = 0;

    for (int i = -99; i <= 99; i++) {
        if (i % num1 == 0 && i % num2 == 0 && (i <= -10 || i >= 10)) {
            nums[j] = i;
            j++;
        }
    }
}

int main() {
    int two_digits_thirds_nums[67] = {};
    int two_digits_seventh_fifth_nums[29] = {};

    get_dividing_nums(3, 1, two_digits_thirds_nums);
    get_dividing_nums(7, 5, two_digits_seventh_fifth_nums);

    printf("The 2 digits numbers that divide in 3: \n");
    for (int i = 0; i < 67; i++) {
        if (two_digits_thirds_nums[i] != 0) {
            printf("%d\n", two_digits_thirds_nums[i]);
        }
    }
    
    printf("The 2 digits numbers that divide in 5 and in 7: \n");
    for (int i = 0; i < 29; i++) {
        if (two_digits_seventh_fifth_nums[i] != 0) {
            printf("%d\n", two_digits_seventh_fifth_nums[i]);
        }
    }
    return 0;
}
