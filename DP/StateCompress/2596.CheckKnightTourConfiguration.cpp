#include <bits/stdc++.h>

using namespace std;

class Solution {
    int base;
    bool check_RI(int a, int b) {
        int ax = a % base, ay = a / base;
        int bx = b % base, by = b / base;
        int disx = abs(ax - bx), disy = abs(ay - by);
        return (disx == 2) ? (disy == 1) : (disx == 1 ? disy == 2 : false);
    }
public:
    bool checkValidGrid(vector<vector<int>> &grid) {
        if (grid[0][0] != 0) return false;
        base = grid.size();
        int len = base * base;
        int g[len];
        for (int i = 0; i < base; i++) for (int j = 0; j < base;j++) g[grid[i][j]] = i * base + j;
        for (int i = 1; i < len; i++) if (!check_RI(g[i - 1], g[i])) return false;
        return true;
    }
};

int main() {
    vector<vector<int>> grid{   {24,11,22,17, 4},
                                {21,16, 5,12, 9},
                                { 6,23,10, 3,18},
                                {15,20, 1, 8,13},
                                { 0, 7,14,19, 2} };
    cout << Solution().checkValidGrid(grid);
    //system("pause");
    return 0;
}
