#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int NULLVAL = -1;
    vector<int> Dijsktra(int n, vector<vector<pair<int,int>>> &graph, int start) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
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
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({ v,w });
        }
        auto dis = Dijsktra(n + 1, graph, k);
        if (*min_element(dis.begin() + 1, dis.end()) == -1) return -1;
        return *max_element(dis.begin() + 1, dis.end());
    }
};

int main() {

    //system("pause");
    return 0;
}
