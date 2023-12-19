#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> E;
const static int NULLVAL = -1;
class Solution {
    vector<int> Dijsktra(int n, vector<vector<E>> &graph, int start) {
        priority_queue<E, vector<E>, greater<E>> pq;
        vector<int> dis(n, NULLVAL);
        pq.emplace(dis[start] = 0, start);
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop(); // c++17
            for (auto [v, w] : graph[u]) { // c++17
                if (dis[v] != NULLVAL && d + w >= dis[v]) { continue; }
                dis[v] = d + w;
                pq.emplace(dis[v], v);
            }
        }
        return dis;
    }
public:
    int minDistanceToD(int n, vector<vector<int>> &edges, int s1, int s2, int d) {
        vector<vector<E>> graph1(n), graph2(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph1[u].push_back({ v,w });
            graph2[v].push_back({ u,w });
        }
        auto disfroms1 = Dijsktra(n, graph1, s1);
        auto disfroms2 = Dijsktra(n, graph1, s2);
        auto distod = Dijsktra(n, graph2, d);
        int ans = 0x7f7f7f7f;
        for (int i = 0; i < n; ++i) {
            if (disfroms1[i] != NULLVAL && disfroms2[i] != NULLVAL && distod[i] != NULLVAL)
                ans = min(ans, disfroms1[i] + disfroms2[i] + distod[i]);
        }
        return ans == 0x7f7f7f7f ? -1 : ans;
    }
};

int main() {
    int M, N, S1, S2, D;
    cin >> M >> N >> S1 >> S2 >> D;
    vector<vector<int>>edges;
    while (N--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(vector<int>{u, v, w});
    }
    cout << Solution().minDistanceToD(M, edges, S1, S2, D);
    //system("pause");
    return 0;
}
