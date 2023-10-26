#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution {
public:
    // 选择 与 不选择 该节点得思路
    SubtreeStatus dfs(Node *node) {
        if (!node) {
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(Node* root) {
        auto rootStatus = dfs(root);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};

int main() {

    //system("pause");
    return 0;
}
