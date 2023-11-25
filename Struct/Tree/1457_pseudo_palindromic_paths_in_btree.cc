#include <bits/stdc++.h>

using namespace std;

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

    int pseudoPalindromicPaths(TreeNode *root) {
        int path_cnt = 0;
        int path = 0;

        auto check = [&path]()->bool
            {
                if (path == 0) return true;
                if (path == 1 || (path ^ 1) & 1) return false;
                // else
                return (1 ^ path) == (path & ((~path) + 2));
            };

        function<void(TreeNode *)> dfs = [&](TreeNode *node)->void
            {
                if (!node) return;
                path ^= ((1 << node->val) | 1);
                if (!node->left && !node->right) {
                    if (check()) ++path_cnt;
                }
                else {
                    dfs(node->left);
                    dfs(node->right);
                }
                path ^= ((1 << node->val) | 1);
            };
        dfs(root);
        return path_cnt;
    }
};

int main() {

    //system("pause");
    return 0;
}
