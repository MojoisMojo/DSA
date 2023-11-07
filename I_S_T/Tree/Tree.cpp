#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<int, int> idx_map;//key:nodes中的下标, value:真实序号
    vector<int> nodes;
    deque<int> ansPath;
    int ansLength;
    int maxSum;
    int _size;
    // idx为在nodes中的下标
    int father(int idx) {
        if (idx == 0) return -1;
        return (idx - 1) >> 1;
    }
    int sonl(int idx) {
        int s = idx << 1 + 1;
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
        _size = nodes.size();
        int cnt = 0;
        for (int i = 0; i < nodes.size();++i)
        {
            if (nodes[i] == 0) idx_map[i] = -1;
            idx_map[i] = cnt++;
        }
    }
    bool should_doSwap(deque<int> temp, int tempSum) {
        if (tempSum > maxSum) return true;
        else if (tempSum < maxSum) return false;
        // else ==
        if (temp.size() < ansLength) return true;
        else if (temp.size() > ansLength) return false;
        // else == 寄 一一比较
        deque<int> tempAns(ansPath);
        while (!temp.empty())
        {
            int tf = temp.front(), taf = tempAns.front();
            if (tf < taf) return true;
            else if (tf > taf) return false;
            temp.pop_front();
            tempAns.pop_front();
        }
        assert(false);
    }
    deque<int> find_miniSumMaxPath(int posidx) {
        if (posidx == -1 || nodes[posidx] == 0) return deque<int>(); // 空节点
        int sl = sonl(posidx), sr = sonr(posidx);
        auto dequel = find_miniSumMaxPath(sl);
        auto dequer = find_miniSumMaxPath(sr);
        bool singleMe = false;
        if (sl == -1 && sr == -1) //没有儿子了
        {
            singleMe = true;
        }
        // sl != -1 || sr != -1
        else if (sl == -1 || nodes[sl] <= 0) // 左儿子没有或者没用
        {
            if (nodes[sr] <= 0)
                singleMe = true; // 右儿子没用
            else
            {
                nodes[posidx] += nodes[sr];
                deque<int> res(dequer);
                res.push_front(idx_map[posidx]);
                return res;
            }
        }
        // sl != -1 && nodes[sl] > 0
        else if (sr == -1 || nodes[sr] <= 0)// 右儿子没有或者没用
        {
            // if (nodes[sl] <= 0)
            //     singleMe = true; // 左儿子没用 不会发生
            nodes[posidx] += nodes[sl];
            deque<int> res(dequer);
            res.push_back(idx_map[posidx]);
            return res;
        }
        // sl != -1 && nodes[sl] > 0 && sr != -1 && nodes[sr] > 0
        else
        {
            int tempRes = nodes[sl] + nodes[sr] + nodes[posidx];
            deque<int> tempres(dequel);
            tempres.push_back(idx_map[posidx]);
            tempres.emplace_back(dequer);
        }
        if (singleMe)
        {
            deque<int> res(1, idx_map[posidx]);
            if (should_doSwap(res, nodes[posidx]))
            {
                maxSum = nodes[posidx];
                ansLength = 1;
                ansPath = res;
            }
            return res;
        }
        //都有用
    }
};

int main() {

    //system("pause");
    return 0;
}
