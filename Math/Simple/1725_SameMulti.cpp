#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size();j++) {
                umap[nums[i] * nums[j]] += 1;// in cpp we map => python.count
            }
        }
        int ans = 0;
        for (auto &p : umap) {
            if(p.second == 1) continue;
            ans += 4 * p.second * (p.second - 1);
        }
        return ans;
    }
};
int main() {
    unordered_map<int, int> umap;
    umap[1] += 1;
    cout << umap[1];
    //system("pause");
    return 0;
}
