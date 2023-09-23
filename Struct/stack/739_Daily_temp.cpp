#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> st;
        vector<int> ans;
        int size_ = temperatures.size();
        ans.resize(size_,0);
        for (int i = 0; i < size_;i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    
    //system("pause");
    return 0;
}
