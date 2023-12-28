#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int dis[m][n];
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        for (;;) { // 可以等待，就一定可以到达终点
            auto [d, i, j] = pq.top();
            pq.pop();
            if (d > dis[i][j]) continue;
            if (i == m - 1 && j == n - 1) // 找到终点，此时 d 一定是最短路
                return d;
            for (auto &q : dirs) { // 枚举周围四个格子
                int x = i + q[0], y = j + q[1];
                if (0 <= x && x < m && 0 <= y && y < n) {
                    int nd = max(d, grid[x][y]);
                    if (nd < dis[x][y]) {
                        dis[x][y] = nd; // 更新最短路
                        pq.emplace(nd, x, y);
                    }
                }
            }
        }
    }
};

int main() {

    //system("pause");
    return 0;
}
