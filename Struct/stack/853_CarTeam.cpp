#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        // 2 4 12 7 9
        // 1 1 12 7 3
        // position唯一降序
        int length = position.size();
        vector<int> id(length);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j)->bool { return position[i] > position[j]; });
        int spd = speed[id[0]], pos = position[id[0]], ans = 1;
        double ddl = (target - pos) / (1.0 * spd);
        for (int i = 1; i < length; i++) {
            int this_spd = speed[id[i]], this_pos = position[id[i]];
            if (
                this_spd <= spd ||
                ddl < (pos - this_pos) / (1.0 * (this_spd - spd))
                ) {
                ans++;
                spd = this_spd;
                pos = this_pos;
                ddl = (target - pos) / (1.0 * spd);
            }
        }
        return ans;
    }
};
int main() {
    //target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    int target = 12;
    vector<int> position{10,8,0,5,3};
    vector<int> speed{2,4,1,1,3};
    cout << Solution().carFleet(target,position,speed);
    //system("pause");
    return 0;
}
