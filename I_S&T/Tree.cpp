#include <bits/stdc++.h>

using namespace std;

class Solution {
    typedef struct TreeNode {
        int val, idx, depth;
        TreeNode *l, *r, *f;
        TreeNode(int _val = 0, int _idx = -1, int _depth = -1,
            TreeNode *_l = nullptr, TreeNode *_r = nullptr, TreeNode *_f = nullptr) :
            val(_val), idx(_idx), depth(_depth), l(_l), r(_r), f(_f) {
            ;
        }
    }*Ptn;

    Ptn root;

    int ansLength;
    pair<Ptn, Ptn> anspairs;
    int maxSum;
    int _size;

    void buildTree(vector<int> &nodes) {
        queue<TreeNode *> curr_level, next_level;
        int idx_depth = 1, idx_cnt = 0;
        root = new TreeNode(nodes[0], idx_cnt++, 0);
        curr_level.push(root);
        for (int i = 1; ; ) {
            TreeNode *curr_node = curr_level.front();  curr_level.pop();
            if (nodes[i]) {
                next_level.push(curr_node->l =
                    new TreeNode(nodes[i], idx_cnt++, idx_depth, nullptr, nullptr, curr_node)
                );
            }
            if (++i >= nodes.size()) break;
            if (nodes[i]) {
                next_level.push(curr_node->r =
                    new TreeNode(nodes[i], idx_cnt++, idx_depth, nullptr, nullptr, curr_node)
                );
            }
            if (++i >= nodes.size()) break;
            if (curr_level.empty()) {
                curr_level = next_level;
                next_level = queue<TreeNode *>();
                idx_depth++;
            }
        }
    }
public:
    Solution(vector<int> &nodes) {
        buildTree(nodes);
        maxSum = -0x3f3f3f3f;
        ansLength = 0x3f3f3f3f;
        anspairs.first = root;
        anspairs.second = root;
    }

    vector<int> findMinLenthMaxSumPath() {
        helper(root);
        vector<int> path;
        stack<int> edpath;
        auto st = anspairs.first, ed = anspairs.second;
        if (st->idx > ed->idx) { swap(st, ed); }
        while (st->depth < ed->depth) { edpath.push(ed->idx); ed = ed->f; }
        while (st->depth > ed->depth) { path.push_back(st->idx); st = st->f; }
        while (st != ed) {
            path.push_back(st->idx);
            edpath.push(ed->idx);
            st = st->f;
            ed = ed->f;
        }
        path.push_back(st->idx);
        while (!edpath.empty()) {
            path.push_back(edpath.top()); edpath.pop();
        }
        return path;

    }

private:

    bool should_changeMaxi(int tempLength, int tempSum) {
        return (tempSum > this->maxSum) || (tempSum == this->maxSum && tempLength <= ansLength);
    }

    TreeNode *helper(TreeNode *node) {
        // 返回一个叶节点
        if (node == nullptr) return nullptr; // 空节点
        auto sl = node->l, sr = node->r;
        auto leafl = helper(sl);
        auto leafr = helper(sr);
        auto res = node;
        int tempSum = node->val;
        int tempLength = 1;
        pair<Ptn, Ptn> tempPair(node, node);

        if (sl == nullptr && sr == nullptr); //没有儿子了
        else if (sl == nullptr || sl->val <= 0) // 左儿子没有或者没用
        {
            if (sr == nullptr || sr->val <= 0); // 右儿子没有或者没用
            else { // 右儿子有且有用
                node->val += sr->val;
                tempSum = node->val;
                tempPair.first = leafr;
                tempPair.second = node;
                tempLength = leafr->depth - node->depth + 1;
                res = leafr;
            }
        }
        else if (sr == nullptr || sr->val <= 0)// 右儿子没有或者没用
        {
            if (sl == nullptr || sl->val <= 0); // 左儿子没有或者没用
            else { // 左儿子有且有用
                node->val += sl->val;
                tempSum = node->val;
                tempPair.first = leafl;
                tempPair.second = node;
                tempLength = leafl->depth - node->depth + 1;
                res = leafl;
            }
        }
        else if (sl && sl->val > 0 && sr && sr->val > 0) {
            tempSum = node->val + sl->val + sr->val;
            tempPair.first = leafl;
            tempPair.second = leafr;
            tempLength = leafl->depth + leafr->depth - 2 * node->depth + 1;
            bool choseL = (sl->val > sr->val) || (sl->val == sr->val && leafl->depth < leafr->depth);
            res = choseL ? leafl : leafr;
            node->val += choseL ? sl->val : sr->val;
        }
        if (should_changeMaxi(tempLength, tempSum)) {
            this->maxSum = tempSum;
            this->ansLength = tempLength;
            this->anspairs = tempPair;
        }
        return res;
    }

};

int main() {
    int k;
    cin >> k;
    vector<int> array;
    int num;
    while (k-- > 0) {
        cin >> num;
        array.push_back(num);
    }
    for (auto &n : Solution(array).findMinLenthMaxSumPath()) cout << n << " ";
    cout << endl;
    return 0;
}
