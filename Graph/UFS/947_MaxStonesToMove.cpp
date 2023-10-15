#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        map<int, int> son_father;
        map<int, set<int>> root_sons;

        for (auto &stone : stones) {
            int x = stone[0], y = stone[1] + (1 << 14);
            if (son_father.find(x) == son_father.end()) {
                son_father[x] = x;
                set<int> hh;
                hh.emplace(x);
                hh.emplace(y);
                root_sons[x] = hh;

            }
            if (son_father.find(y) == son_father.end()) {
                son_father[y] = y;
                set<int> hh;
                hh.emplace(x);
                hh.emplace(y);
                root_sons[y] = hh;
            }
            int rt1 = x, nrt1 = son_father[x],
                rt2 = y, nrt2 = son_father[y];
            while (rt1 != nrt1) {
                rt1 = nrt1;
                nrt1 = son_father[nrt1];
            }
            while (rt2 != nrt2) {
                rt2 = nrt2;
                nrt2 = son_father[nrt2];
            }

            if (rt1 == rt2) continue;

            //else
            son_father[rt2] = rt1;
            for (auto &rt2_son : root_sons[rt2]) {
                root_sons[rt1].emplace(rt2_son);
                son_father[rt2_son] = rt1;
            }
            root_sons.erase(rt2);
        }
        return stones.size() - root_sons.size();
    }
};
int main() {

    //system("pause");
    return 0;
}
