#include <stdio.h>
#include <string.h>

void dump5(char *str) {
    for(int i = 0; i < 5; i++) {
        printf("%2.2x:%c ", *str, *str ? *str : '!');
        str++;
    }
    printf("\n");
}

int main (){
    int len = 5;
    char str[5] = {'s','a','\0','c','h'};
    char membuff[5];
    char strbuff[5];
    
    memcpy(membuff, str, 5);
    strcpy(strbuff, str);
    printf("membuff:\n");
    dump5(membuff);
    printf("strbuff:\n");
    dump5(strbuff);
    return 0;
}
