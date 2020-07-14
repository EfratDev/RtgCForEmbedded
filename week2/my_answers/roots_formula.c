#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float x1, x2, delta;
    printf("Please enter your numbers for the roots formula: [a,b,c] ");
    scanf("%d,%d,%d", &a, &b, &c);
    delta = pow(b, 2) - 4 * a * c;
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2.0 * a);
        x2 = (-b - sqrt(delta)) / (2.0 * a);
        printf("The solutions:\nx1 = %f\nx2 = %f\n", x1, x2);
    } else if (delta < 0) {
        printf("No solutions.\n");
    } else if (delta == 0){
        x1 = -b / (2.0 * a);
        printf("The solution is:\nx = %f\n", x1);
    }
    return 0;
}
