#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MAXN 1000
#define F(i,n,m) for(int i=n;i<=m;i++)//谢谢洛谷大佬@xiangge 
//存在快排退化
void pswp(int *x, int *y);
void Mysort(int *a, int l, int r);
bool Judge(int *a, int i);

int main()
{
    srand(time(0));
    int a[MAXN+5];
    F(i, 1, MAXN) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n\n");
    Mysort(a, 1, MAXN);
    F(i, 1, MAXN) {
        printf("%d ", a[i]);
        if (!Judge(a, i)&&i!=MAXN) printf(" !error! ");
    }
    
    return 0;
}

void pswp(int *x, int *y)
{
    int hh = *x;
    *x = *y;
    *y = hh;
}

bool Judge(int *a,int i)
{
    return a[i] <= a[i + 1];
}

void Mysort(int *arr, int l, int r)
{
    int mid = arr[(l + r) / 2];//二分
    int i = l, j = r, mid_index = l;
    while (i < j) {
        for (; i < j && arr[i] < mid; i++);
        for (; i < j && arr[j] >= mid; j--);
        if(i < j) pswp(&arr[i], &arr[j]);
    }
    for (; arr[mid_index] != mid; mid_index++);
    if (i < mid_index) pswp(&arr[i], &arr[mid_index]);
    i--;j++;
    if (l < i) Mysort(arr, l, i);
    if (j < r) Mysort(arr,j, r);
    
}