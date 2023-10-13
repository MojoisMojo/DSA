#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        set<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                st.insert(i);
            } else {
                ans[i] = -1;
                if (mp.count(rains[i])) {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if (it == st.end()) {
                        return {};
                    }
                    ans[*it] = rains[i];
                    st.erase(it);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> avoidFlood(vector<int>& rains) {
//         unordered_map<int,int> lakes_state;
//         int length = rains.size();
//         vector<int> pos;
//         vector<int> ans(length,1);
//         for(int i = 0; i < length; i++){
//             if (rains[i] == 0) {
//                 // not rainy
//                 pos.push_back(i);
//             }
//             else {
//                 auto it_idx = lakes_state.find(rains[i]);
//                 if (it_idx != lakes_state.end()) {
//                     // 找到
//                     int target = (*it_idx).second;
//                     //二分查找大于target的最小整数
//                     int l = 0, r = pos.size() - 1;
//                     if (pos.size() <= 0 || pos[r] < target) {
//                         // 别找了
//                         ans.resize(0); return ans;
//                     }
//                     while (l < r) {
//                         int mid = l + ((r - l) >> 1);
//                         if (pos[mid] >= target) {
//                             r = mid;
//                         }
//                         else {
//                             l = mid + 1;
//                         }
//                     }
//                     ans[pos[r]] = rains[i];
//                     pos.erase(pos.begin() + r);
//                 }
//                 lakes_state[rains[i]] = i;
//                 ans[i] = -1;
//             }
//         }
//         return ans;
//     }
// };
int main() {
    
    //system("pause");
    return 0;
}
