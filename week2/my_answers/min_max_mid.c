#include <stdio.h>


int get_max(int num1, int num2) {
    if (num1 >= num2) {
        return num1;
    } else {
        return num2, num2;
    }
}


int get_min(int num1, int num2) {
    if (num1 <= num2) {
        return num1;
    } else {
        return num2;
    }
}


int get_doubled(num1, num2, num3) {
    if (num1 == num2 || num2 == num3) {
        return num2;
    } else if (num1 == num3) {
        return num1;
    }
}


int main() {
    int num1, num2, num3, max, min, mid;
    printf("Please enter 3 numbers [x,y,z]: ");
    scanf("%d,%d,%d", &num1, &num2, &num3);
    max = get_max(get_max(num1, num2), num3);
    min = get_min(get_min(num1, num2), num3);
    if (num1 != max && num1 != min) {
        mid = num1;
    } else if (num2 != max && num2 != min) {
        mid = num2;
    } else if (num3 != max && num3 != min) {
        mid = num3;
    } else {
        mid = get_doubled(num1, num2, num3);
    }
    printf("MAX: %d\nMID: %d\nMIN: %d\n", max, mid, min);
    return 0;
}
