#include <stdio.h>
#include <math.h>


int bin(unsigned int num) {
    unsigned int bin = 0;
    for (int i = 0; i < 32; i++) {
        if ((1 << i) & num) {
            bin += pow(10, i);
        }
    }
    return bin;
}


int main() {
    unsigned int num;
    printf("Please enter a positive num: ");
    scanf("%d", &num);
    printf("%d\n", bin(num));
    return 0;
}
