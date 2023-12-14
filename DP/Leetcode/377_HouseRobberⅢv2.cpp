#include <iostream>
using namespace std;

//  Definition for a binary tree node.
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
    pair<int, int> dfs_rob(TreeNode *node) {
        if (!node) return { 0,0 };
        auto [l, l_c] = dfs_rob(node->left);
        auto [r, r_c] = dfs_rob(node->right);
        return { max(l + r,l_c + r_c + node->val),l + r };
    }
    int rob(TreeNode *root) {
        return dfs_rob(root).first;
    }

    pair<int, int> dfs_MAXIS(TreeNode *node) {
        if (!node) return { 0,0 };
        auto [l, l_c] = dfs_MAXIS(node->left);
        auto [r, r_c] = dfs_MAXIS(node->right);
        return { max(l + r,l_c + r_c + 1),l + r };
    }

    int MaxIS(TreeNode *node) {
        return dfs_MAXIS(node).first;
    }
};