#include <stdio.h>
#include <string.h>


void switch_variables(int * a, int * b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b; 
}


int main() {
    int a, b;
    printf("Please enter 2 numbers 'x,y' : ");
    scanf("%d,%d", &a, &b);
    printf("The content of variable a is: %d\n"
        "The content of variable b is: %d.\n"
        , a, b);
    switch_variables(&a, &b);
    printf("We switched the variables.\n"
        "The content of variable a is: %d\n"
        "The content of variable b is: %d.\n", a, b);
    
    return 0;
}
