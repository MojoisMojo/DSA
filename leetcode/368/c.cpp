#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(int X, int m) {
        return (X / m) * (m + 1) >= X;
    }
    int calNum(int X, int m) {
        return (X + m) / (m + 1);
    }
    int minGroupsForValidAssignment(vector<int> &nums) {
        unordered_map<int, int> numbersOfNum; //数的个数
        unordered_map<int, int> numbersOfNumbersOfNum;// 数的个数 的 个数

        for (auto &num : nums) {
            numbersOfNum[num]++;
        }

        int mini = 0x3f3f3f3f;

        for (auto &p : numbersOfNum) {
            numbersOfNumbersOfNum[p.second]++;
            mini = min(mini, p.second);
        }

        // m(t + 1) <= (m + 1)t;
        // m <= t;
        // mt >= m ^ 2;
        // n >= m ^ 2;
        // check(n, m) = > true;
        


        int res_m = floor(sqrt(mini));
        for (int m = res_m + 1; m <= mini; m++) {
            bool valid = true;
            for (auto &p : numbersOfNumbersOfNum) {
                valid = check(p.first, m);
                if(!valid) break;
            }
            if (valid) res_m = m;
        }
        int ans = 0;
        for (auto &p : numbersOfNumbersOfNum) {
            ans += calNum(p.first, res_m) * p.second;
        }
        return ans;
    }
};

int main() {
    //system("pause");
    return 0;
}
