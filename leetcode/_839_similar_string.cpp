#include <bits/stdc++.h>

using namespace std;

class My_UnionSet {
    unordered_map<int, int>f;
    unordered_map<int, int>rank;
    int cnt;
public:
    My_UnionSet() { cnt = 0; }
    int find(int x) {
        if (!f.count(x)) {
            cnt++;
            rank[x] = 1;
            return f[x] = x;
        }
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool UnionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return true;
        }
        else {
            cnt--;
            if (rank[fx] < rank[fy]) { swap(fx, fy); }
            f[fy] = fx;
            rank[fx] += rank[fy];
            rank.erase(fy);
        }
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string> &strs) {
        for(int i )
    }
};

int main() {
    
    //system("pause");
    return 0;
}
