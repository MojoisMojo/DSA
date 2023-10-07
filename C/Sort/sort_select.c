#include<stdio.h>
#include<string.h>

#define F(i,h,hh) for(int i = h;i<=hh;i++)

int cnt = 0;

void pswap(int *x, int *y)
{
    cnt++;
    int hh = *x;
    *x = *y;
    *y = hh;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 5];
    memset(a, 0, sizeof(a));
    F(i, 1, n) {
        scanf("%d", &a[i]);
    }
    for (int i = 1;i<=n;i++)
    {
        for (int j = i+1;j<=n;j++){
            if (a[i] > a[j])
                pswap(&a[i], &a[j]);
        }
    }
    F(i, 1, n-1)
        printf("%d ", a[i]);
    printf("%d\n", a[n]);
    printf("cnt is %d", cnt);
}