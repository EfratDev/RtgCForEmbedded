#include <stdio.h>

int main() {
    int num1, num2, sum, multiplication;
    float division, average;
    printf("please enter 2 numbers seperated with ',':\n");
    scanf("%d,%d", &num1, &num2);
    sum = num1 + num2;
    multiplication = num1 * num2;
    float fnum1 = num1;
    division = fnum1 / num2;
    average = sum / 2.0;
    printf(
        "recieved the numbers: %d, %d.\n"
        "Sum: %d\n"
        "Multiplication: %d\n"
        "Multiplication without saving: %d\n"
        "Division: %.2f\n"
        "Average: %.2f\n",
        num1, num2, sum, multiplication, num1 * num2, division, average);
    return 0;
}