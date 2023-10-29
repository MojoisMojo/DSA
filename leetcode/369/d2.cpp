#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k) {
        vector<vector<int>> g(coins.size());
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        function<array<int, 14>(int, int)> dfs = [&](int x, int fa)->array<int, 14> {
            array<int, 14> res1{}, res2{};
            for (int y : g[x]) {
                if (y == fa) continue;
                auto r = dfs(y, x);
                for (int j = 0; j < 14; j++) {
                    res1[j] += r[j];
                    if (j < 13) {
                        res2[j] += r[j + 1];
                    }
                }
            }
            for (int j = 0; j < 14; j++) {
                res1[j] = max(res1[j] + (coins[x] >> j) - k, res2[j] + (coins[x] >> (j + 1)));
            }
            return res1;
        };
        return dfs(0, -1)[0];
    }
};

int main() {

    //system("pause");
    return 0;
}
