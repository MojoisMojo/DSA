#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &sons, vector<set<int>> &fathers, vector<bool> &vi, int cur) {
        if (vi[cur]) {
            return;
        }
        vi[cur] = true;
        for (auto &ne : sons[cur]) {
            auto &a = fathers[ne];
            auto &b = fathers[cur];
            merge(a.begin(), a.end(), b.begin(), b.end(), inserter(a, a.begin()));
            dfs(sons, fathers, vi, ne);
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<set<int>> fathers{};
        vector<vector<int>> sons{};
        vector<bool> visited{};
        for (const auto &p : prerequisites) {
            sons[p[0]].push_back(p[1]);
            fathers[p[1]].emplace(p[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            dfs(sons, fathers, visited, i);
        }
        vector<bool> res;
        for (const auto &q : queries) {
            res.push_back(fathers[q[1]].find(q[0]) != fathers[q[1]].end());
        }
        return res;
    }
};

int main() {
    set<int> a{ 1,2,3 }, b{ 4,3,1 };
    merge(a.begin(), a.end(), b.begin(), b.end(), inserter(a, a.begin()));
    //system("pause");
    return 0;
}
