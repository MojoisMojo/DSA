#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        vector<int> ans(heights.size());
        for (int i = heights.size() - 1; i >= 0; --i) {
            int height = heights[i];
            while (!st.empty() && height > st.top()) {
                st.pop();
                ans[i]++;
            }
            if (!st.empty()) { ans[i]++; }
            st.push(height);
        }
        return ans;
    }
};

int main() {
    
    //system("pause");
    return 0;
}
