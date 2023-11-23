#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
    /// @brief 组合,在类内部析构
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
    vector<int> arr{ 0 };
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

const int BinaryTree::nullNodeVal = -1;

/// @param arr 层序遍历的数组
BinaryTree::BinaryTree(vector<int> &arr) :BinaryTree() {
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
}

/// @brief 将二叉树 转换 为 层序化输出
/// @todo 未完成
vector<int> BinaryTree::toVectorInt() {
    /// @todo
    return vector<int>();
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


int Solution::helpminLength(TreeNode *node) {
    if (node == nullptr) return 0;
    int ls = helpminLength(node->left), rs = helpminLength(node->right);
    ans = max(ans, ls + rs);
    return max(ls, rs) + 1;
}

int Solution::minLength() {
    helpminLength(bt->getRoot());
    return (bt->getEdgesNumber() << 1) - ans;
}