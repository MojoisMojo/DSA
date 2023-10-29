#include <bits/stdc++.h>

using namespace std;

int main() {

    //system("pause");
    return 0;
}

const int max_div_time = 14;
class Solution {
public:

    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k) {
        vector<vector<int>> graph(coins.size());
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        function<array<int, max_div_time>(int, int)> dfs = \
            [&](int node, int father)->array<int, max_div_time>{
            array<int, max_div_time> res1{}, res2{};
            for (int son : graph[node]) {
                if (son == father) continue;
                //else
                auto r = dfs(son, node);
                for (int i = 0; i < max_div_time; ++i) {
                    res1[i] += r[i];
                    if (i < max_div_time - 1) {
                        res2[i] += r[i + 1];
                    }
                }
            }
            for (int i = 0; i < max_div_time; ++i) {
                res1[i] = max(res1[i] + (coins[node] >> i) - k, res2[i] + (coins[node] >> (i + 1)));
            }
            return res1;
        };

        return dfs(0, -1)[0];
    }
};

