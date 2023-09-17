#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int longestWPI(vector<int> &hours) {
        // 前缀和(1,-1)-> sum => 最大片段
        int h_size = hours.size();
        vector<int> sum;
        sum.resize(h_size + 1);
        for (int i = 0; i < h_size;i++) {
            sum[i + 1] = sum[i] + (hours[i] > 8 ? 1 : -1);
        }
        stack<int> s;
        s.push(0);
        for (int i = 1; i <= h_size; i++) {
            if (sum[s.top()] > sum[i]) // 单调递减
                s.push(i);
        }
        int res = 0;
        for (int i = h_size; i > 0; i--) {
            while (!s.empty() && sum[s.top()] < sum[i]) {
                res = max(res,i-s.top()+1);
                s.pop();
            }
        }
        return res;
    }
};
int main() {

    //system("pause");
    return 0;
}
