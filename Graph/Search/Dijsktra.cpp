#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Node {
    int name, distance;
    Node(int name, int distance) :name(name), distance(distance) { ; }
    bool operator<(const Node &a) const {
        return distance < a.distance;
    }
    bool equal(const Node &a) const {
        return distance == a.distance;
    }
    bool operator>(const Node &a) const {
        return distance > a.distance;
    }
};

struct cmp //重写仿函数
{
    bool operator() (Node a, Node b) {
        return a > b; //小顶堆
    }
};
class Solution {
public:
    /**
     * @param edges: 图中的边[name1,name2,dis]
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

        vector<vector<Node>> g;
        for (const auto &edge : edges) {
            g[edge[0]].push_back(Node(edge[1], edge[2]));
            g[edge[1]].push_back(Node(edge[0], edge[2]));
        }

        priority_queue<Node, vector<Node>, cmp> pq;
        pq.push(Node{ start,0 });
        res[start] = 0;
        search[start] = false;
        while (!pq.empty()) {
            Node n = pq.top();
            if(search[n.name]) continue;
            search[n.name] = true;
            for (const auto &son : g[n.name]) {
                int this_dis = n.distance + son.distance;
                if (res[son.name] > this_dis) {
                    res[son.name] = this_dis;
                    pq.push(Node(son.name, res[son.name]));
                }
            }
            pq.pop();
        }
        return res;
    }
};


int main() {
    
    //system("pause");
    return 0;
}
