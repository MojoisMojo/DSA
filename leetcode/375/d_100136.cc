#include <bits/stdc++.h>

using namespace std;

class Solution {
    const static int MOD = 1e9 + 7;
    long long pow(long long base, int exp, int mod = MOD) {
        long long res = 1;
        for (; exp; exp /= 2) {
            if (exp % 2) res = res * base % mod;
            base = base * base % mod;
        }
        return res;
    }
public:
    int numberOfGoodPartitions(vector<int> &nums) {
        unordered_map<int, int> idxMap;
        stack<int> idx_st;
        for (int i = 0; i < nums.size(); ++i) {
            auto n = nums[i];
            if (!idxMap.count(n)) { idxMap[n] = i; }
            while (!idx_st.empty() && idx_st.top() >= idxMap[n]) {
                idx_st.pop();
            }
            idx_st.push(i);
        }
        int cnt = 0;
        while (!idx_st.empty()) { idx_st.pop(); cnt++; }
        return pow(2, cnt - 1);
    }
};


int main() {

    //system("pause");
    return 0;
}
