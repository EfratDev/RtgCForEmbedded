#include <stdio.h>


int get_factorial(unsigned int);


int get_factorial(unsigned int num){
    int factorial = 1;
    for (; num != 1; num--) {
        factorial *= num;
    }
    return factorial;
}


int main(){
    unsigned int num;
    printf("Please enter a positive number: ");
    scanf("%u", &num);
    printf("%u! = %u\n", num, get_factorial(num));
    return 0;
}