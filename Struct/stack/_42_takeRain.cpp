#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int idx = st.top(); st.pop();
                if (st.empty()) { break; }
                int t = st.top();
                sum += min(height[t], height[i]);
            }
            st.push(i);
        }
        return sum;
    }
};

int main() {

    //system("pause");
    return 0;
}
