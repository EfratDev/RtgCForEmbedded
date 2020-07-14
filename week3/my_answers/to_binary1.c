#include <stdio.h>


void print_bin(unsigned num) {
    for (int i=31; i>=0; i--) {
        if ((1 << i) & num) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}


int main() {
    unsigned num;
    printf("Please enter an unsigned int: ");
    scanf("%d", &num);
    print_bin(num);
    
    return 0;
}
