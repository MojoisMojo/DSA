#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        for (auto &flower : flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        int m = persons.size();
        vector<int> indices(m);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return persons[a] < persons[b];
        });

        vector<int> ans(m);
        int curr = 0;
        auto it = cnt.begin();
        for (int x : indices) {
            while (it != cnt.end() && it->first <= persons[x]) {
                curr += it->second;
                it++;
            }
            ans[x] = curr;
        }
        return ans;
    }
};

int main() {
    //system("pause");
    return 0;
}
