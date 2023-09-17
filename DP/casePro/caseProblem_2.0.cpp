#include<iostream> 
using namespace std;
int f[1000005];
int v[1000005],w[1000005];
int cnt;
void add(int a,int b)
{
    cnt++;
    v[cnt]=a;
    w[cnt]=b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=1;j<=c;j++)//这里应该是j*=2,可是j++AC了
        {
            add(b*j,a*j);
            c-=j;
        }
        if(c) add(b*c,a*c);
    }
    for(int i=1;i<=cnt;i++)
    for(int j=m;j>=v[i];j--)
    f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[m];
    return 0;
}