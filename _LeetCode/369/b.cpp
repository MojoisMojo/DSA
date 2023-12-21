#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long min1 = 0, min2 = 0;
        bool max1 = false, max2 = false;
        for (auto num : nums1) {
            if (num == 0) {
                min1 += 1;
                max1 = true;
            }
            else {
                min1 += num;
            }
        }
        for (auto num : nums2) {
            if (num == 0) {
                min2 += 1;
                max2 = true;
            }
            else {
                min2 += num;
            }
        }
        if ((!max2 && min1 > min2) || (!max1 && min1 < min2)) {
            return -1;
        }
        return max(min1, min2);
    }
};

int main() {
    
    //system("pause");
    return 0;
}
