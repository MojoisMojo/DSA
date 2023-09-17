#include <stdio.h>
#define N 20000
int head[N], next[N], tot, to[N], c[N];

typedef struct Node
{
    int to, c;
} Node;

Node edge[N];
void add(int x, int y)
{
    ++tot;
    edge[tot].to = y;
    next[tot] = head[x];
    head[x] = tot;
}

int To[N][N], siz[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        To[x][++siz[x]] = y;
        add(x, y);
    }
    for (int x = 1; x <= n; x++)
    {
        printf("%d: ", x);
        for (int i = head[x]; i; i = next[i])
        {
            printf("%d ", edge[i].to);
        }
        putchar('\n');
    }
}