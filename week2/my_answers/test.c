#include <stdio.h>
int main() {  
    int a = 2, b = 4, c = 6;
    {int d = 5;}
    printf("%d\n", d);
    return 0;
}