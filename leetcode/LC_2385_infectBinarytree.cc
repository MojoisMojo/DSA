#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>


using namespace std;

#define nullNodeVal -1

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val = -1, TreeNode *l = nullptr, TreeNode *r = nullptr) : val(val), left(l), right(r) {}
    ~TreeNode() { left = nullptr; right = nullptr; }
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


class UndirectedGraph {
    int nodes_number;
    vector<unordered_set<int>> edges;
    UndirectedGraph(int size, BinaryTree *bt) {
        
    }
};

class Solution {
public:
    int amountOfTime(TreeNode *root, int start) {

    }
};

class MySolution {
    BinaryTree *bt;
    unordered_map<int, unordered_set<int>> edges;
    void buildEdges() {
        
    }
public:
    MySolution() {
        
    }
    MySolution(vector<int> &arr) {
        bt = new BinaryTree(arr);
    }
    int amountOfTime(TreeNode *root, vector<int> &starts) {

    }
};

int main() {
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
