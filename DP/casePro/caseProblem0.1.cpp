#include<bits/stdc++.h>
using namespace std;
const int maxn = 13010;
int n, W, volume[maxn], worth[maxn], f[maxn];
// 种类 最大容量 单个容量 单个价值 状态
int main() {
  cin >> n >> W;
  for (int i = 1; i <= n; i++)
    cin >> volume[i] >> worth[i];  // 读入数据
  for (int i = 1; i <= n; i++)
    for (int l = W; l >= volume[i]; l--) //当我们有l容量的背包时候,选择装还是不装
      if (f[l - volume[i]] + worth[i] > f[l])
        f[l] = f[l - volume[i]] + worth[i];  // 状态方程
  cout << f[W];
  return 0;
}