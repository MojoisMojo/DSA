#include "need.h"

int main() {
    int a[3][4] = { -1,0,0,1, -2,0,0,2, -3,0,0,3 };
    int *arr1[3];//指针数组
    int arr1plus[3][1];//???
    arr1[0] = a[0];
    //arr1plus[0] = a[0];//wrong 不可修改的左值
    for (int i = 0; i < 4; i++)
        //right
        printf("%d ", arr1[0][i]);
    puts("");

    for (int i = 0; i < 4; i++)
        //wrong
        printf("%d ", arr1[1][i]);
    puts("");

    int(*arr2)[4];
    int(*arr3)[4];
    int (**parr2)[4] = &arr2;//right 数组指针的指针
    arr3 = (int(*)[4])malloc(sizeof(int) * 4);
    int (**parr3)[4] = (int (**)[4])malloc(sizeof(int(*)[4]));
    parr3 = &arr3;
    arr2 = a;
   // arr2[0] = a[0];//wrong 不可修改的左值
    for (int i = 0; i < 4; i++)
        printf("%d ", arr2[0][i]);
}