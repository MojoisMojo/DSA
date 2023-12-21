#include <bits/stdc++.h>

using namespace std;

class DisjointSetUnion {
    unordered_map<int, int>f;
    unordered_map<int, int>rank;
    int number_of_connectedComponent;
public:
    DisjointSetUnion() { number_of_connectedComponent = 0; }
    int find(int x) {
        if (!f.count(x)) {
            number_of_connectedComponent++;
            rank[x] = 1;
            return f[x] = x;
        }
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return true;
        }
        else {
            number_of_connectedComponent--;
            if (rank[fx] < rank[fy]) { swap(fx, fy); }
            f[fy] = fx;
            rank[fx] += rank[fy];
            rank.erase(fy);
        }
        return false;
    }
    int numberOfConnectedComponent() { return number_of_connectedComponent; }
};
class Solution {
public:
    bool should_union(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        int c = 0;
        int p = -1;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            if (++c == 1) { p = i; }
            else if (c == 2) { if (s1[p] != s2[i] || s1[i] != s2[p]) return false; }
            else if (c > 2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string> &strs) {
        DisjointSetUnion dsu;
        for (int i = 0; i < strs.size(); ++i) {
            dsu.find(i);
            for (int j = i + 1; j < strs.size(); ++j) {
                if (should_union(strs[i], strs[j])) {
                    dsu.unionSet(i, j);
                }
            }
        }
        return dsu.numberOfConnectedComponent();
    }
};

int main() {
    vector<string> inp;
    string s;
    while (cin >> s) {
        inp.push_back(s);
    }
    cout << Solution().numSimilarGroups(inp) << endl;
    system("pause");
    return 0;
}
