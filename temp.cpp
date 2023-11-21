#include <bits/stdc++.h>

using namespace std;


class Solution {
    struct Node {
        int val;
        Node *l, *r;
        Node(int val_, Node *l_, Node *r_) :val(val_), l(l_), r(r_) { ; }
    };
    deque<int> topView(Node *root) {
        deque<int> ans;
        queue<pair<Node *, int>>q;
        q.emplace(root, 0);
        int idxl = 0, idxr = 0;
        ans.push_back(root->val);
        while (!q.empty()) {
            // queue<pair<Node *, int>> curr = q;
            // q = queue<pair<Node *, int>>();
            // while (!curr.empty()) {
                // auto [node, pos] = curr.front(); curr.pop();
                auto [node, pos] = q.front(); q.pop();
                if (node->r) {
                    if (pos + 1 > idxr) {
                        idxr = pos + 1;
                        ans.push_back(node->r->val);
                    }
                    q.emplace(node->r, pos + 1);
                }
                if (node->l) {
                    if (pos - 1 < idxl) {
                        idxr = pos - 1;
                        ans.push_front(node->l->val);
                    }
                    q.emplace(node->l, pos - 1);
                }
            // }
        }
        return ans;
    }
};