#include <iostream>
using namespace std;

typedef long long ll;

const static ll MOD = 0x7FFFFFFF;

typedef struct TreeNode {
public:
    int val;
    TreeNode *l, *r;
    TreeNode(int val_ = 0, TreeNode *l_ = nullptr, TreeNode *r_ = nullptr)
        : val(val_), l(l_), r(r_) {
    }
} *PNode;
class BST {
public:
    PNode root;
    BST() :root(nullptr) { ; }
    PNode insert(int);
};


ll f(int i) {
    if (i <= 1) return 1;
    return f(i - 1) * i;
}


ll inv(ll t, ll p) {
    return t == 1 ? 1 : (p - p / t) * inv(p % t, p) % p;
}

class Solution {

    struct Result {
        ll n, m;// n is num of node, m is total kinds of permutations
        Result(ll n = 0, ll m = 1) :n(n), m(m) {}
    };
    Result dfs(TreeNode *root) {
        if (!root) return Result();
        Result l = dfs(root->l), r = dfs(root->r);
        return Result(l.n + r.n + 1, (l.m * r.m) * inv(f(l.n + r.n) / f(l.n) / f(r.n), MOD));
    }
public:
    ll findSameBTSNum(BST *bst) {
        return dfs(bst->root).m;
    }
};

int main() {
    int n;
    cin >> n;
    BST *bst = new BST();
    while (n--) {
        int v;
        cin >> v;
        bst->insert(v);
    }
    cout << Solution().findSameBTSNum(bst) << endl;
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
