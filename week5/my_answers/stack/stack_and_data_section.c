#include <stdio.h>

typedef void (*t_fptr)(void);
int blabla; // data section

void func() {
    static int c = 0;
    printf("%d\n", c);
    c++;
    printf("%d\n", c);
}

int main() {
    int a = 1, b; // stack
    static int c = 1; // data section
    t_fptr fun_ptr = &func;
    fun_ptr();
    fun_ptr();
}
