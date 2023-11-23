#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val = -1, TreeNode *l = nullptr, TreeNode *r = nullptr) :
        val(val), left(l), right(r) {
    }
    ~TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    static const int nullNodeVal;
    TreeNode *root;
    int edges_number;
    void helperDelete(TreeNode *&);
public:
    BinaryTree() :root(nullptr), edges_number(0) {}
    explicit BinaryTree(vector<int> &);
    vector<int> toVectorInt();
    TreeNode *getRoot() { return root; }
    int getEdgesNumber() { return edges_number; }
    ~BinaryTree();
};


int main() {
    //system("pause");
    return 0;
}


const int BinaryTree::nullNodeVal = -1;

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
                curr->left = new TreeNode(*num);
                q.emplace(curr->left);
            }
            if (*(++num) != nullNodeVal) {
                ++cnt;
                curr->right = new TreeNode(*num);
                q.emplace(curr->right);
            }
        }
        this->edges_number += cnt;
    }
}

/// @brief 将二叉树 转换 为 层序化输出
vector<int> BinaryTree::toVectorInt() {

}

void BinaryTree::helperDelete(TreeNode *&node) {
    if (!node) return;
    helperDelete(node->left);
    helperDelete(node->right);
    delete node;
    node = nullptr;
}

BinaryTree::~BinaryTree() {
    helperDelete(this->root);
}
