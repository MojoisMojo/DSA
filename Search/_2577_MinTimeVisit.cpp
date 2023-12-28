#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    int minimumTime(vector<vector<int>> &grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((grid[i][j] ^ (i + j)) & 1) {
                    grid[i][j]++;
                }
            }
        }

        int dir[4][2] = {
            {0,1},{0,-1},{1,0},{-1,0}
        };
        priority_queue<pair<long long, int>> pq;// first is <= 0
        unordered_map<int, long long> time_dis;
        time_dis[0] = 0;
        pq.push({ 0, 0ll });

        auto neighbor = [&](int u)->vector<int> {
            int x = u / n, y = u & n;
            vector<int> v;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    v.push_back(nx * n + ny);
                }
            }
            return v;
            };
        while (!pq.empty()) {
            auto [d, u] = pq.top();pq.pop();
            if (u + 1 == m * n) return -d;
            for (auto v : neighbor(u)) {
                int x = v / m, y = v % m;
                long long n_time = 1 - d;
                if (!time_dis.count(v) || time_dis[v] > n_time) {
                    time_dis[v] = max((long long)grid[x][y], n_time);
                    pq.push({ -time_dis[v],v });
                }
            }
        }
        return time_dis[m * n - 1];
    }
};

class Solution2 {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minimumTime(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) // 无法「等待」
            return -1;

        int dis[m][n];
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        for (;;) { // 可以等待，就一定可以到达终点
            auto[d, i, j] = pq.top();
            pq.pop();
            if (d > dis[i][j]) continue;
            if (i == m - 1 && j == n - 1) // 找到终点，此时 d 一定是最短路
                return d;
            for (auto &q : dirs) { // 枚举周围四个格子
                int x = i + q[0], y = j + q[1];
                if (0 <= x && x < m && 0 <= y && y < n) {
                    int nd = max(d + 1, grid[x][y]);
                    nd += (nd - x - y) % 2; // nd 必须和 x+y 同奇偶
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
