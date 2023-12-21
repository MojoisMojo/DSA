#include <bits/stdc++.h>

using namespace std;
#define N 1000
int sum_array(int a[N][N][N]) {
    int i, j, k, sum = 0;
    for (k = 0; k < N; ++k)
        for (i = 0; i < N; ++i)
            for (j = 0; j < N; ++j)
                sum += a[k][i][j];
    return sum;
}
// 修改后程序的数组元素访问和排列顺序一致，
// 使得空间局部性比原先要好，
// 故而执行时间更短。


int main() {
    
    //system("pause");
    return 0;
}
