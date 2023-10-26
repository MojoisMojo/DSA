#include <bits/stdc++.h>

using namespace std;

//   Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Node *constructMaximumBinaryTree(vector<int> &nums) {
        stack<Node *> st;
        for (const auto &n : nums) {
            Node* this_node = new Node(n);
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