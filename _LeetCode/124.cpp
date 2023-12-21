#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int _val = 0, int _idx = -1, int _depth = -1,
        TreeNode *_l = nullptr, TreeNode *_r = nullptr) :
        val(_val),left(_l), right(_r) {
        ;
    }
};
class Solution {
    int maxSum;
public:
    int maxPathSum(TreeNode *root) {
        maxSum = -0x3f3f3f3f;
        helper(root);
        return maxSum;
    }
private:

    bool should_changeMaxi(int tempSum) {
        return tempSum > this->maxSum;
    }

    TreeNode *helper(TreeNode *node) {
        // 返回一个叶节点
        if (node == nullptr) return nullptr; // 空节点
        auto sl = node->left, sr = node->right;
        auto leafl = helper(sl);
        auto leafr = helper(sr);
        auto res = node;
        int tempSum = node->val;

        if (sl == nullptr && sr == nullptr); //没有儿子了
        // sl != -1 || sr != -1
        else if (sl == nullptr || sl->val <= 0) // 左儿子没有或者没用
        {
            if (sr == nullptr || sr->val <= 0); // 右儿子没有或者没用
            else { // 右儿子有且有用
                node->val += sr->val;
                tempSum = node->val;
                res = leafr;
            }
        }
        // sl != -1 && nodes[sl] > 0
        else if (sr == nullptr || sr->val <= 0)// 右儿子没有或者没用
        {
            if (sl == nullptr || sl->val <= 0); // 左儿子没有或者没用
            else { // 左儿子有且有用
                node->val += sl->val;
                tempSum = node->val;
                res = leafl;
            }
        }
        // sl != -1 && nodes[sl] > 0 && sr != -1 && nodes[sr] > 0
        else if (sl && sl->val > 0 && sr && sr->val > 0) {
            tempSum = node->val + sl->val + sr->val;
            bool choseL = true;
            if (sl->val < sr->val) choseL = false;
            res = choseL ? leafl : leafr;
            node->val += choseL ? sl->val : sr->val;
        }
        if (should_changeMaxi(tempSum)) {
            this->maxSum = tempSum;
        }
        // _output << endl;
        return res;
    }
};

