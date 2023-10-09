#include<stdio.h>
#include<stdlib.h>
#define F(i,n,m) for(int i=n;i<=m;i++)//谢谢洛谷大佬@xiangge 

void pswap(int *x, int *y);
void Mysort(int *a, int l, int r);


int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 5];
    F(i, 1, n) scanf("%d", &a[i]);
    Mysort(a, 1, n);
    F(i, 1, n - 1) printf("%d ", a[i]);
    printf("%d", a[n]);
    return 0;
}

void pswap(int *x, int *y)
{
    int hh = *x;
    *x = *y;
    *y = hh;
}

void Mysort(int *a, int l, int r)
{
    int t = a[(l + r) / 2];//二分
    int i = l, j = r;
    do
    {
        while (a[i] < t) i++;
        while (a[j] > t)j--;
        if (i <= j)
        {
            pswap(&a[i], &a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) Mysort(a,l, j);
    if (i < r) Mysort(a,i, r);
    
}