#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> mnode;
const int inf = 0x3f3f3f3f;
class Solution {
public:
    vector<int> Bellman_FordWithinKth(int n, vector<vector<int>> &edges, int from, int k) {
        vector<vector<int>> dis(n, vector<int>(k+2,inf));
        dis[from][0] = 0;
        for (int t = 1; t <= k + 1; ++t) {
            for (auto edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dis[u][t - 1] < inf) {
                    dis[v][t] = min(dis[v][t], dis[u][t - 1] + w);
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = *min_element(dis[i].begin() + 1, dis[i].end());
        }
        return ans;
    };
};

int main() {
    int from, to, k;
    cin >> from >> to >> k;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(vector<int>{u, v, w});
    }
    int disToto = Solution().Bellman_FordWithinKth(n, edges, from, k)[to];
    cout << (disToto < inf ? disToto : -1) << endl;
    //system("pause");
    return 0;
}
