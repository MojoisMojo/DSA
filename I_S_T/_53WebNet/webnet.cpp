#include <bits/stdc++.h>

using namespace std;

// 并查集模板
class DisjointSetUnion {
private:
    unordered_map<int, int> f, rank;
    int number_of_connectedComponent;
public:
    DisjointSetUnion() { number_of_connectedComponent = 0; }
    int find(int x) {
        if (!f.count(x)) {
            f[x] = x;
            rank[x] = 1;
            ++number_of_connectedComponent;
        }
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return true;
        }
        --number_of_connectedComponent;
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return false;
    }

    int numberOfConnectedComponent() {
        return number_of_connectedComponent;
    }
};
class Solution {
public:
    int minCostToBuild(vector<vector<int>> &edges) {
        priority_queue<pair<int,pair<int,int>>> pq;
        // weight, <dot1, dot2>
        DisjointSetUnion dsu;
        for (auto &edge : edges) {
            pq.push({-edge[2],{edge[0],edge[1]} });
            dsu.find(edge[0]);
            dsu.find(edge[1]);
        }
        int cost = 0;
        while (!pq.empty()) {
            auto edge = pq.top();pq.pop();
            int w = edge.first;
            int x = edge.second.first, y = edge.second.second;
            if (dsu.unionSet(x, y)) {
                continue;
            }
            cost -= w;
        }
        return cost;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back(vector<int>{x, y, w});
    }
    cout << Solution().minCostToBuild(edges) << endl;
    //system("pause");
    return 0;
}
