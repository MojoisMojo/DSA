#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#include<windows.h>
#define F(i,m,n) for(int i = m;i<=n;i++)

int cnt = 0;

void pswp(int *x, int *y);
bool Judge(int a[], int l, int r);


void monkey(int *a, int l, int r)
{
    //int hh[r - l + 1];
    //F(i, l, r) hh[i] = a[i];
    while (!Judge(a, l, r))
    {
        cnt++;
        //F(i, l, r) a[i] = hh[i];
        for (int i = r;i >= l;i--)
        {
            int t = rand() % (r - l + 1) + l;
            pswp(&a[i], &a[t]);
        }
    }
}

int main()
{
    srand(time(0));
    int n;
    scanf("%d", &n);
    int O[n + 2];
    char *x;
    // while (x != "#")
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        F(i, 1, n) O[i] = rand() % 100;
        monkey(O, 1, n);
        F(i, 1, n) printf("%3d ", O[i]);
        printf("cnt is %d\n", cnt);
    }
    return 0;
}

void pswp(int *x, int *y)
{
    int hh = *x;
    *x = *y;
    *y = hh;
}


bool Judge(int a[], int l, int r)
{
    F(i, l, r-1)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}