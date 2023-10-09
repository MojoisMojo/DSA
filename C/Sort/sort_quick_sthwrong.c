#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MAXN 100
#define F(i,n,m) for(int i=n;i<=m;i++)//谢谢洛谷大佬@xiangge 

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
    printf("\n");
    Mysort(a, 1, MAXN);
    F(i, 1, MAXN) {
        printf("%d ", a[i]);
        if (!Judge(a, i)) printf(" !error! ");
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

void Mysort(int *a, int l, int r)
{
    int t = a[(l + r) / 2];//二分
    int i = l, j = r;
    while (i < j)
    {
        int isstop = 1;
        if (a[i] < t)
        {
            i++;
            isstop = 0;
        }
        if (a[j] >= t)
        {
            j--;
            isstop = 0;
        }
        if (isstop)
            pswp(&a[i], &a[j]);
    }
    if (a[i] != t)
    {
        j = r+1;
        while (a[--j] != t && j>i);
        if (a[i] > t) pswp(&a[i], &a[j]);
        else /*if (a[i] < t)*/ pswp(&a[i+1], &a[j]);
    }
    j = i + 1;
    i--;
    if (l < i) Mysort(a, l, i);
    if (j < r) Mysort(a,j, r);
    
}