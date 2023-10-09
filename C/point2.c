#include "need.h"

int main() {
    int b[2];
    printf("%p %p\n", b + 1, *(b + 1));
    int a[2][3];
    for (int i = 0;i < 6; i++)
        (*a)[i] = 1 + i;
    // for (int i = 0; i < 2; i++)
    // {
    //     printf("a[%d] points to %p, address is %p\n", i, a[i], a + i);
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("a[%d][%d] value is %d, address is %p\n", i, j, a[i][j], a[i] + j);
    //     }
    // }
    // printf("    a's address is %p, points to %p\n", &a, a);
    // printf("   *a's address is %p, points to %p\n", a, *a);
    // printf("  **a's address is %p, value is %d\n", *a, **a);
    // printf(" a[1]'s address is %p, points to  %p\n", a + 1, *(a + 1));
    // printf(" a[1][0]'s address is %p, value is %d\n", a[1], a[1][0]);
    printf("%u", sizeof(*a));
    return 0;
}