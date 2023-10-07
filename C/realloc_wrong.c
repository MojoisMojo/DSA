#include "need.h"
//this is a wrong example to realloc an one dimension array
//what we should do is 
//One   Change "int *b" to "int **b"
//Or    Declare an "int **" function and return b, 
//          and then in mainfunction we should write like this: a = func(a, ...)
void Hhh(int *b, int size, int plus) {
    printf("In func, b points to %p, and b's address is %p\n", b, &b);
    b = (int *)realloc(b, sizeof(int) * (size + plus));
    printf("After realloc, b points to %p, and b's address is %p\n", b, &b);
    b[size] = 114514;
    printf("After realloc, b[size] is %d address is %p\n", b[size], b + size);
}

int main() {
    int size = 10;
    int *a = (int *)malloc(sizeof(int) * size);
    a[0] = 0;
    printf("In main, a points to %p, and a's address is %p\n", a, &a);
    Hhh(a, size, 1000);
    printf("After func, a points to %p, and a's address is %p\n", a, &a);
    printf("After func, a[size] is %d address is %p\n", a[size], a + size);
    a[size] = 114;
    printf("After assignment, a[size] is %d address is %p\n", a[size], a + size);

}