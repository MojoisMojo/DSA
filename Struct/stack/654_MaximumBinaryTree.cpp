#include <bits/stdc++.h>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        stack<TreeNode *> st;
        for (const auto &n : nums) {
            TreeNode* this_node = new TreeNode(n);
            while (!st.empty() && st.top()->val < this_node->val) {
                this_node->left = st.top();
                st.pop();
            }
            if (!st.empty()) st.top()->right = this_node;
            st.push(this_node);
        }
        auto ans = st.top();
        while (!st.empty()) {
            ans = st.top();
            st.pop();
        }
        return ans;
    }
};

int main() {
    
    //system("pause");
    return 0;
}