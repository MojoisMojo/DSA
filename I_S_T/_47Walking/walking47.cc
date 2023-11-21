#include <bits/stdc++.h>

using namespace std;

#define nullNodeVal -1

struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int val = -1, TreeNode *l = nullptr, TreeNode *r = nullptr) :
        val(val), l(l), r(r) {
    }
    ~TreeNode() {
        l = nullptr;
        r = nullptr;
    }
};

class BinaryTree {
    TreeNode *root;
    int edges_number;
    void helperDelete(TreeNode *&);
public:
    BinaryTree() :root(nullptr), edges_number(0) {}
    BinaryTree(vector<int> &);
    TreeNode *getRoot() { return root; }
    int getEdgesNumber() { return edges_number; }
    ~BinaryTree();
};

class Solution {
    BinaryTree *bt;
    int ans;
    int helpminLength(TreeNode *);
public:
    /// @param arr 层序遍历的数组
    Solution(vector<int> &arr) { bt = new BinaryTree(arr); ans = 0; }
    int minLength();
    ~Solution() { delete bt; }
};

int main() {
    int k;
    vector<int> arr;
    cin >> k;
    while (k--) {
        int num;
        cin >> num;
        arr.push_back(num);
        cin >> num;
        arr.push_back(num);
    }
    cout << Solution(arr).minLength() << endl;
    //system("pause");
    return 0;
}

/// @param arr 层序遍历的数组
BinaryTree::BinaryTree(vector<int> &arr) :BinaryTree() {
    queue<TreeNode *> q;
    auto num = arr.begin();
    int cnt = 1;

    // c++17前的写法 之后可以并为一句，因为emplace有了返回值
    if (*num != nullNodeVal) { root = new TreeNode(*num); q.emplace(root); }

    while (!q.empty() && cnt > 0) {
        int i = cnt;
        cnt = 0;
        for (; i > 0; --i) {
            TreeNode *curr = q.front(); q.pop();
            if (*(++num) != nullNodeVal) {
                ++cnt;
                curr->l = new TreeNode(*num);
                q.emplace(curr->l);
            }
            if (*(++num) != nullNodeVal) {
                ++cnt;
                curr->r = new TreeNode(*num);
                q.emplace(curr->r);
            }
        }
        cout << cnt << endl;
        edges_number += cnt;
    }
}

void BinaryTree::helperDelete(TreeNode *&node) {
    if (!node) return;
    helperDelete(node->l);
    helperDelete(node->r);
    delete node;
    node = nullptr;
}

BinaryTree::~BinaryTree() {
    helperDelete(this->root);
}

int Solution::helpminLength(TreeNode *node) {
    if (node == nullptr) return 0;
    int ls = helpminLength(node->l), rs = helpminLength(node->r);
    ans = max(ans, ls + rs);
    return max(ls, rs) + 1;
}

int Solution::minLength() {
    helpminLength(bt->getRoot());
    return (bt->getEdgesNumber() << 1) - ans;
}