#include <bits/stdc++.h>

using namespace std;
// ofstream _output("out");

// void print(vector<int> &v) {
//     for (auto &va : v) _output << va << " ";
//     _output << endl;

// }

class Solution {
    typedef struct TreeNode {
        int val, idx, depth;
        TreeNode *left, *right, *f;
        TreeNode(int _val = 0, int _idx = -1, int _depth = -1,
            TreeNode *_l = nullptr, TreeNode *_r = nullptr, TreeNode *_f = nullptr) :
            val(_val), idx(_idx), depth(_depth), left(_l), right(_r), f(_f) {
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
                next_level.push(curr_node->left =
                    new TreeNode(nodes[i], idx_cnt++, idx_depth, nullptr, nullptr, curr_node)
                );
            }
            if (++i >= nodes.size()) break;
            if (nodes[i]) {
                next_level.push(curr_node->right =
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
        // find the path
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
        // 题目 说最大的只有一个 所以当tSum = mSum tLength = ansLength 时，\
        我们选择改变最大值，因为先出现的已经固定死了，后出现要么不是最大值，要么在后面会有更大的值加进来
    }

    TreeNode *helper(TreeNode *node) {
        // 返回一个叶节点
        if (node == nullptr) return nullptr; // 空节点
        auto sl = node->left, sr = node->right;
        auto leafl = helper(sl);
        auto leafr = helper(sr);
        auto res = node;
        int tempSum = node->val;
        int tempLength = 1;
        pair<Ptn, Ptn> tempPair(node, node);

        if (sl == nullptr && sr == nullptr); //没有儿子了
        // sl != -1 || sr != -1
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
        // sl != -1 && nodes[sl] > 0
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
        // sl != -1 && nodes[sl] > 0 && sr != -1 && nodes[sr] > 0
        else if (sl && sl->val > 0 && sr && sr->val > 0) {
            tempSum = node->val + sl->val + sr->val;
            tempPair.first = leafl;
            tempPair.second = leafr;
            tempLength = leafl->depth + leafr->depth - 2 * node->depth + 1;
            bool choseL = true;
            if (sl->val < sr->val) choseL = false;
            else if (sl->val == sr->val) {
                if (leafl->depth > leafr->depth) choseL = false;
                // == 无意义
            }
            res = choseL ? leafl : leafr;
            node->val += choseL ? sl->val : sr->val;
        }
        // _output << tempSum << " ";
        if (should_changeMaxi(tempLength, tempSum)) {
            // _output << "changed ";
            this->maxSum = tempSum;
            this->ansLength = tempLength;
            this->anspairs = tempPair;
        }
        // _output << endl;
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
    Solution solution(array);
    vector<int> path = solution.findMinLenthMaxSumPath();
    for (auto &n : path) {
        cout << n << " ";
    }
    cout << endl;
    //system("pause");
    return 0;
}
