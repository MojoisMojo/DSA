#include <bits/stdc++.h>

using namespace std;

typedef struct TreeNode {
public:
    int val;
    TreeNode *l, *r;
    TreeNode(int val_ = 0, TreeNode *l_ = nullptr, TreeNode *r_ = nullptr)
        : val(val_), l(l_), r(r_) {
        ;
    }
} *PNode;


class Tree {
protected:
    PNode root;
    void helpPrePrint(PNode);
    void helpdestroy(PNode &);
public:
    Tree() : root(nullptr) { ; }
    Tree(vector<int> nums) : Tree() {
        for (auto &num : nums)
            this->insert(num);
    }
    virtual ~Tree();
    virtual PNode insert(int);
    void PrePrint();
};

void Tree::helpPrePrint(PNode node) {
    if (!node)
        return;
    cout << node->val << " ";
    helpPrePrint(node->l);
    helpPrePrint(node->r);
}

void Tree::helpdestroy(PNode &node) {
    if (!node)
        return;
    helpdestroy(node->l);
    helpdestroy(node->r);
    delete node;
    node = nullptr;
}

void Tree::PrePrint() {
    this->helpPrePrint(this->root);
    cout << endl;
}

PNode Tree::insert(int val) {
    PNode *thisnode = &(this->root);
    while (*thisnode) {
        thisnode = rand() % 2 ? &((*thisnode)->r) : &((*thisnode)->l);
    }
    *thisnode = new TreeNode(val);
    return *thisnode;
}

Tree::~Tree() {
    helpdestroy(this->root);
}

class BST :public Tree {
public:
    BST() { ; }
    BST(vector<int> nums) : BST() {
        for (auto &num : nums)
            this->insert(num);
    }
    PNode insert(int);
    ~BST();
};

int main() {
    vector<int> nums = { 4,6,1,9,10 };
    Tree *tree = new Tree(nums);
    Tree *bst = new BST(nums);
    delete tree;
    delete bst;
    // system("pause");
    return 0;
}


PNode BST::insert(int val) {
    PNode *thisnode = &(this->root);
    while (*thisnode) {
        thisnode =
            (*thisnode)->val < val ? &((*thisnode)->r) : &((*thisnode)->l);
    }
    *thisnode = new TreeNode(val);
    return *thisnode;
}

BST::~BST() { ; }
