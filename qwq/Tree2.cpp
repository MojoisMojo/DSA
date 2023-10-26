#include <bits/stdc++.h>

using namespace std;
// ofstream _output("out");

// void print(vector<int> &v) {
//     for (auto &va : v) _output << va << " ";
//     _output << endl;

// }

class Solution {
    vector<int> idx_map;//idx:nodes中的下标, value:真实序号
    vector<int> depth_map;//idx:nodes中的下标, value:深度
    vector<int> nodes;
    int ansLength;
    pair<int, int> anspairs;
    int maxSum;
    int _size;
    // idx为在nodes中的下标
    int father(int idx) {
        if (idx == 0) return -1;
        return (idx - 1) >> 1;
    }
    int sonl(int idx) {
        int s = (idx << 1) + 1;
        if (s < _size) return s;
        return -1;
    }
    int sonr(int idx) {
        int s = (idx + 1) << 1;
        if (s < _size) return s;
        return -1;
    }
public:
    Solution(vector<int> &nodes) {
        this->nodes = nodes;
        maxSum = -0x3f3f3f3f;
        ansLength = 0x3f3f3f3f;
        anspairs.first = -1;
        anspairs.second = -1;
        _size = nodes.size();
        idx_map.resize(_size, -1);
        depth_map.resize(_size, -1);
        int cnt = 0, depth = 0;

        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i] != 0) idx_map[i] = cnt++;
            depth_map[i] = depth;
            if (i == (1 << (depth + 1)) - 2) ++depth;
        }
    }

    vector<int> findMiniMaxSumPath() {
        helper(0);
        vector<int> path;
        stack<int> edpath;
        // find the path
        int st = anspairs.first, ed = anspairs.second;
        if (idx_map[st] > idx_map[ed]) { swap(st, ed); }
        while (depth_map[st] < depth_map[ed]) { edpath.push(idx_map[ed]); ed = father(ed); }
        while (depth_map[st] > depth_map[ed]) { path.push_back(idx_map[st]); st = father(st); }
        while (st != ed) {
            path.push_back(idx_map[st]);
            edpath.push(idx_map[ed]);
            st = father(st);
            ed = father(ed);
        }
        path.push_back(idx_map[st]);
        while (!edpath.empty()) {
            path.push_back(edpath.top()); edpath.pop();
        }
        return path;

    }

private:

    bool should_changeMaxi(int tempLength, int tempSum) {
        if (tempSum > this->maxSum) return true;
        else if (tempSum < this->maxSum) return false;
        // else ==
        if (tempLength <= this->ansLength) return true;
        else if (tempLength > this->ansLength) return false;
        // 题目 说最大的只有一个 所以当tSum = mSum tLength = ansLength 时，\
        我们选择改变最大值，因为先出现的已经固定死了，后出现要么不是最大值，要么在后面会有更大的值加进来
        assert(false);
    }

    int helper(int posidx) {
        // 返回一个叶节点
        if (posidx < 0 || nodes[posidx] == 0) return -1; // 空节点
        int sl = sonl(posidx), sr = sonr(posidx);
        auto leafl = helper(sl);
        auto leafr = helper(sr);
        int res = posidx;
        int tempSum = nodes[posidx];
        int tempLength = 1;
        pair<int, int> tempPair(posidx, posidx);

        if (sl == -1 && sr == -1); //没有儿子了
        // sl != -1 || sr != -1
        else if (sl == -1 || nodes[sl] <= 0) // 左儿子没有或者没用
        {
            if (nodes[sr] <= 0); // 右儿子没用
            else {
                nodes[posidx] += nodes[sr];
                tempSum = nodes[posidx];
                tempPair.first = leafr;
                tempPair.second = posidx;
                tempLength = depth_map[leafr] - depth_map[posidx] + 1;
                res = leafr;
            }
        }
        // sl != -1 && nodes[sl] > 0
        else if (sr == -1 || nodes[sr] <= 0)// 右儿子没有或者没用
        {
            if (nodes[sl] <= 0); // 左儿子没用 不会发生
            else {
                nodes[posidx] += nodes[sl];
                tempSum = nodes[posidx];
                tempPair.first = leafl;
                tempPair.second = posidx;
                tempLength = depth_map[leafl] - depth_map[posidx] + 1;
                res = leafl;
            }
        }
        // sl != -1 && nodes[sl] > 0 && sr != -1 && nodes[sr] > 0
        else {
            tempSum = nodes[posidx] + nodes[sl] + nodes[sr];
            tempPair.first = leafl;
            tempPair.second = leafr;
            tempLength = depth_map[leafl] + depth_map[leafr] - 2 * depth_map[posidx] + 1;
            res = nodes[sl] > nodes[sr] ? leafl : (nodes[sl] < nodes[sr] ? leafr : (depth_map[leafl] < depth_map[leafr] ? leafl : leafr));// 不会出现 ==
            nodes[posidx] += (res == leafl ? nodes[sl] : nodes[sr]);
        }
        // _output << tempSum << " ";
        if (should_changeMaxi(tempLength,tempSum)) {
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
    vector<int> path = solution.findMiniMaxSumPath();
    for (auto &n : path) {
        cout << n << " ";
    }
    cout << endl;
    //system("pause");
    return 0;
}
