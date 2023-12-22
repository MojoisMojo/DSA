#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

const int MOD = 0x7FFFFFFF;
// int* inv = nullptr;

// void init() {
//     if (inv) delete[]inv;
//     inv = new int[MOD];
//     inv[0] = 0;
//     inv[1] = 1;
//     for (int i = 2; i < MOD; i++)
//         inv[i] = ((MOD - MOD / i) * 1LL * inv[MOD % i]) % MOD;
//     return;
// }

int inv(int t, int p = MOD) {//求t关于p的逆元，注意:t要小于p，最好传参前先把t%p一下 
    return t == 1 ? 1 : (ll)(p - p / t) * (ll)inv(p % t, p) % p;
}

int FactorMOD(int n) {
    ll res = 1;
    for (int i = n; i > 1; --i) {
        res = (res * (ll)i) % MOD;
    }
    return (int)res;
}

class Solution {

    struct Result {
        int n, m;// n is num of node, m is total kinds of permutations
        Result(int n = 0, int m = 1) :n(n), m(m) {}
    };

    Result dfs(PNode node) {
        if (!node) return Result();
        Result l = dfs(node->l), r = dfs(node->r);
        int n1 = l.n, m1 = l.m, n2 = r.n, m2 = r.m;
        int m = (
            ((FactorMOD(n1 + n2) * inv((FactorMOD(n1) * FactorMOD(n2)) % MOD)) % MOD)
            *
            ((m1 * m2) % MOD)
            ) % MOD;
        int n = n1 + n2 + 1;
        return Result(n, m);
    }
public:
    unsigned int findSameBTS(BST *bst) {
        return dfs(bst->root).m;
    }
};

int main() {
    // int n;
    // while (cin >> n) {
    //     cout << inv(n) << endl;
    // }
    int n;
    cin >> n;
    BST *bst = new BST();
    while (n--) {
        int v;
        cin >> v;
        bst->insert(v);
    }
    cout << Solution().findSameBTS(bst) << endl;
    //system("pause");
    return 0;
}

/**********************************************************************************/

PNode BST::insert(int val) {
    PNode *thisnode = &(this->root);
    while (*thisnode) {
        thisnode =
            (*thisnode)->val < val ? &((*thisnode)->r) : &((*thisnode)->l);
    }
    *thisnode = new TreeNode(val);
    return *thisnode;
}
