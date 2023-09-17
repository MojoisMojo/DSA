#include<stdio.h>
long f[1000100];
long v[1000100],w[1000100];
long cnt;

int main()
{
    long n, V;
    cnt = 0;
    scanf("%ld%ld", &n, &V);
    for(long i=1; i<=n; i++)
    {
        long worth,volume,num;
        scanf("%ld%ld%ld", &worth, &volume, &num);
        //一个很牛逼的处理方法 转化为二进制,得出可以拿若干个2^k(k in range(1,n))和一个补足表示
        for (int j = 1;j <= num;j *= 2) 
        {
            cnt++;
            v[cnt] = j*volume;
            w[cnt] = j*worth;
            num -= j;
        }
        if (num)
        {
            cnt++;
            v[cnt] = num*volume;
            w[cnt] = num*worth;
        }
    }
    //核心的算法,能理解,但是自己写出来有点问题
    for (long i = 1;i <= cnt;i++)
        for (long j = V;j >= v[i];j--)
            if(f[j]<f[j - v[i]] + w[i]) f[j] = f[j - v[i]] + w[i];
    printf("%ld", f[V]);
    return 0;
}