#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // priority_queue<int> pq(int,vector<int>);
        if (k <= 0) return 0LL;
        long long ans = 0LL;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            int m = pq.top();
            ans += m;
            pq.pop();
            pq.push((m + 2) / 3);
        }
        return ans;

    }
};
int main() {
    
    //system("pause");
    return 0;
}
