#include <stdio.h>

int main() {
    int integer;
    printf("Please enter a number: ");
    scanf("%d", &integer);

    if (integer >= 0) {
        printf("%d\n", integer);
    } else {
        printf("%d\n", integer * -1);
    }

    return 0;
}