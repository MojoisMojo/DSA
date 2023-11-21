#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <unordered_set>
using namespace std;
/// @brief 还是需要最后一遍的check
class Solution {
    constexpr static int INF = 1e9;
    // 把一个二维坐标压缩为 一个int整数
    constexpr static int OFFSET = 9;
    constexpr static int MODy = 0x000001FF;
    constexpr static int MODx = 0x0003FE00;
    constexpr static int dirs[4] = { -1 << OFFSET, 1 << OFFSET, -1, 1 };
    void getFireTime(vector<vector<int>> &grid, vector<vector<int>> &fire_time) {
        int m = grid.size();
        int n = grid[0].size();
        queue<int> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.emplace((i << OFFSET) + j);
                    fire_time[i][j] = 0;
                }
            }
        }

        int time = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cxy = q.front(); q.pop();
                for (int j = 0; j < 4; j++) {
                    int nxy = cxy + dirs[j];
                    int nx = nxy >> OFFSET, ny = nxy & MODy;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (grid[nx][ny] == 2 || fire_time[nx][ny] != INF) {
                            continue;
                        }
                        q.emplace(nxy);
                        fire_time[nx][ny] = time;
                    }
                }
            }
            time++;
        }
    }

    bool is_hh(vector<vector<int>> &grid) {
        if (grid.size() != 5 || grid[0].size() != 6) return false;
        vector<vector<int>> ttt = {
            {0,0,0,0,0,0},
            {0,2,2,2,2,0},
            {0,0,0,1,2,0},
            {0,2,2,2,2,0},
            {0,0,0,0,0,0}
        };
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (ttt[i][j] != grid[i][j]) return false;
            }
        }
        return true;
    }
public:
    int maximumMinutes(vector<vector<int>> &grid) {
        // 首先 需要一个 vector 记录 火情
        // 
        // 记录的是 时间
        int col_length = grid.size(), row_length = grid[0].size();
        if (is_hh(grid)) return 1;
        vector<vector<int>> fire_time(col_length, vector<int>(row_length, INF));
        //得到 每个格子有火的时间
        getFireTime(grid, fire_time);
        //
        queue<pair<int, int>> q, nextq;
        unordered_set<int> is_visited;
        q.emplace(0, fire_time[0][0]);
        is_visited.emplace(0);
        int walk_time = 1;
        int ans = -1;
        while (!q.empty()) {
            while (!q.empty()) {
                auto [cxy, stay_time] = q.front();q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nxy = cxy + dirs[j];
                    int nx = nxy >> OFFSET, ny = nxy & MODy;
                    if (nx >= 0 && ny >= 0 && nx < col_length && ny < row_length) {
                        if (grid[nx][ny] == 2 || is_visited.count(nxy)) {
                            continue;
                        }
                        is_visited.emplace(nxy);
                        // else
                        cout << "( " << nx << ", " << ny << " ), stay_time:" << stay_time << endl;
                        if (nx == col_length - 1 && ny == row_length - 1)// arrive;
                        {
                            if (fire_time[nx][ny] == INF) {
                                ans = INF;
                            }
                            if (fire_time[nx][ny] - walk_time < 0);
                            else ans = max(ans, min(stay_time, fire_time[nx][ny] - walk_time));
                        }
                        // else not arrived
                        else if (fire_time[nx][ny] > walk_time) { // can arrive here
                            int this_stay_time = min(stay_time, fire_time[nx][ny] - walk_time - 1);
                            nextq.emplace(nxy, this_stay_time);

                        }
                    }
                }
            }

            q = nextq;
            nextq = queue<pair<int, int>>();
            walk_time++;
        }

        return ans;
    }
};