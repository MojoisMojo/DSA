#include <bits/stdc++.h>

using namespace std;

class Solution {
        static const int mapsize = 8;
        inline static int calPlace(const auto &place){return place[0] * mapsize + place[1];};
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        vector<vector<int>> ans;
        vector<bool>queensplace;
        queensplace.resize(mapsize * mapsize, false);
        for (const auto &queen : queens)
            queensplace[calPlace(queen)] = true;
        vector<vector<int>> directions{
            {1,0},{-1,0},{0,1},{0,-1},
            {1,1},{-1,1},{1,-1},{-1,-1}
        };
        for (const auto &d : directions) {
            vector<int> kp{ king[0],king[1] };
            while (0 <= kp[0] && kp[0] < mapsize && 0 <= kp[1] && kp[1] < mapsize) {
                if (queensplace[calPlace(kp)]) { ans.push_back(kp); break;}
                    kp[0] += d[0];
                    kp[1] += d[1];
            }
        }
        return ans;
    }
};

int main() {

    //system("pause");
    return 0;
}
