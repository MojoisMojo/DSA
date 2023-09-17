#include <bits/stdc++.h>

using namespace std;

// typedef pair<int, int> pii;

struct node {
    int name, distance;
    node(int name, int distance) :name(name), distance(distance) { ; }
    bool operator<(const node& a) const
    {
        return distance < a.distance;
    }
    bool equal(const node& a) const
    {
        return distance == a.distance;
    }
    bool operator>(const node& a) const
    {
        return distance > a.distance;
    }
};

struct cmp //重写仿函数
{
    bool operator() (node a, node b) {
        return a > b; //小顶堆
    }
};
class Solution {
public:
    /**
     * @param edges: 图中的边
     * @param num: 图中的点的数量
     * @param start: 出发点
     * @returns 从出发点到所有其他点的最短路
    */
    vector<int> Dijsktra(vector<vector<int>> edges, int num, int start) {
        vector<int> res;
        res.resize(num, INT_MAX);
        if (start >= num) return res;
        
        vector<bool> search;
        search.resize(num, false);

        vector<vector<int>> g;
        for (const auto &edge : edges)
            g[edge[0]].push_back(edge[1]);

        priority_queue<node, vector<node>, cmp> pq;
        pq.push(node{ start,0 });
        while (!pq.empty()) { ; }
        return res;
    }
};


int main() {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push(node{ 0,103 });
    pq.push(node{ 3,211 });
    pq.push(node{ 2,96 });
    while (!pq.empty()) {
        cout << pq.top().name << " " << pq.top().distance << "\n";
        pq.pop();
    }
    //system("pause");
    return 0;
}
