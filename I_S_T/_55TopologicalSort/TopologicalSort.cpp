#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortedStudents(vector<pair<int, int>> &edges, int n) {
        vector<int> ans;
        vector<vector<int>> graph(n);
        vector<int> degrees(n, 0);
        for (auto edge : edges) {
            int u = edge.first, v = edge.second;
            graph[u].push_back(v);
            degrees[v]++;
        }
        priority_queue<int>pq;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 0) {
                pq.push(-i);
            }
        }
        while (!pq.empty()) {
            int u = -pq.top();pq.pop();
            ans.push_back(u);
            for (auto v : graph[u]) {
                if (--degrees[v] == 0) {
                    pq.push(-v);
                }
            }
        }
        return ans;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>>edges;
    while (M--) {
        int u, v;
        cin >> u >> v;
        edges.push_back({ u,v });
    }
    for (auto &num : Solution().sortedStudents(edges, N)) {
        cout << num << " ";
    }
    cout << endl;
    //system("pause");
    return 0;
}
