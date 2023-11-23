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
    TreeNode *root;
    int edges_number;
    vector<int> sequencing_vector;
    void helperDelete(TreeNode *&);
public:
    static const int nullNodeVal;
    BinaryTree() :root(nullptr), edges_number(0) {}
    BinaryTree(const BinaryTree &);
    explicit BinaryTree(const vector<int> &);
    BinaryTree &operator=(const BinaryTree &);
    BinaryTree &operator=(const vector<int> &);
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
BinaryTree::BinaryTree(const vector<int> &arr) :BinaryTree() {
    (*this) = arr;
}

BinaryTree::BinaryTree(const BinaryTree &bt) :BinaryTree(bt.sequencing_vector) {}

/// @brief 赋值操作
/// @param arr 层序遍历的数组
/// @return 二叉树
BinaryTree &BinaryTree::operator=(const vector<int> &arr) {
    this->~BinaryTree();

    this->sequencing_vector = arr;

    if (arr.size() == 0) return *this;

    queue<TreeNode *> q;
    auto num = arr.begin();
    int cnt = 1;

    /// @details c++17前的写法 之后可以并为一句，因为emplace有了返回值
    if (*num != nullNodeVal) { root = new TreeNode(*num); q.emplace(root); }

    auto addNode = [&cnt, &num, &q](TreeNode *&node)->void {
        if (*(++num) != nullNodeVal) {
            ++cnt;
            node = new TreeNode(*num);
            q.emplace(node);
        }
        };

    while (!q.empty() && cnt > 0) {
        int i = cnt;
        cnt = 0;
        for (; i > 0; --i) {
            TreeNode *curr = q.front(); q.pop();
            addNode(curr->left);
            addNode(curr->right);
        }
        this->edges_number += cnt;
    }
    return *this;
}

/// @brief 赋值操作
/// @param bt 二叉树
/// @return 一个新的二叉树
BinaryTree &BinaryTree::operator=(const BinaryTree &bt) {
    if (this == &bt) return *this;
    return (*this) = bt.sequencing_vector;
}

/// @brief 将二叉树 转换 为 层序化输出
/// @details 理论上来讲，这里会直接执行第一个if，
vector<int> BinaryTree::toVectorInt() {
    if (this->sequencing_vector.size()) return this->sequencing_vector;// 存在
    if (!this->root) return vector<int>();// root为空

    vector<int> result;
    queue<TreeNode *> q;
    q.push(this->root);
    result.push_back(root->val);

    auto addVal = [&q, &result](TreeNode *node)->void {
        if (node) q.push(node);
        result.push_back(node == nullptr ? BinaryTree::nullNodeVal : node->val);
        };

    while (!q.empty()) {
        TreeNode *curr = q.front(); q.pop();
        addVal(curr->left);
        addVal(curr->right);
    }

    return this->sequencing_vector = result;
}

void BinaryTree::helperDelete(TreeNode *&node) {
    if (!node) return;
    helperDelete(node->left);
    helperDelete(node->right);
    delete node;
    node = nullptr;
}

BinaryTree::~BinaryTree() {
    helperDelete(this->root); // include root = nullptr
    this->edges_number = 0;
    this->sequencing_vector.clear();
}
