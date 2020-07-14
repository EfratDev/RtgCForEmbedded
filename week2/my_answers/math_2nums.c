#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2;
    printf("Please enter 2 number seperated by ',': "),
    scanf("%d,%d", &num1, &num2);
    int biggest_num = (num1 > num2)?num1:num2;
    int smallest_num = (num1 < num2)?num1:num2;
    float division = (float)biggest_num / smallest_num;
    printf(
        "The biggest number is %d\n"
        "The average is %f\n"
        "The big number can dividng by the small number %lf times\n"
        "After the division do you get fracture? %d\n", 
        biggest_num, (num1 + num2) / 2.0, floor(division), 
        (division != floor(division))
    );

    return 0;
}