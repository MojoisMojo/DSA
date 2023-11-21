#include <bits/stdc++.h>

using namespace std;

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

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        --number_of_connectedComponent;
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
    }

    int numberOfConnectedComponent() {
        return number_of_connectedComponent;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        DisjointSetUnion dsu;
        for (int i = 0; i < n; i++) {
            dsu.unionSet(stones[i][0], stones[i][1] + 10001);
        }

        return n - dsu.numberOfConnectedComponent();
    }
};


int main() {
    
    //system("pause");
    return 0;
}
