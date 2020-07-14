#include <stdio.h>

int main() {
    int num, modulo;
    printf("Please enter a number bigger than 2010: ");
    scanf("%d", &num);
    if (num <= 2010) {
        printf("ERROR, the number isn't bigger than 2010.\n");
        return 0;
    }

    modulo = num % 19;
    switch(modulo) {
        case 3:
            printf("%d %% 19 = 3\n", num);
            break;

        case 6:
            printf("%d %% 19 = 6\n", num);
            break;

        case 8:
            printf("%d %% 19 = 8\n", num);
            break;

        case 11:
            printf("%d %% 19 = 11\n", num);
            break;
        
        default:
            printf("%d %% 19 != 3, 6, 8, 11\n", num);
    }

    return 0;
}
