#include <iostream>
#include<string.h>
#include <queue>
#include <set>
#include <vector>
using namespace std;
/**
 * not right!!!
 *
*/
class Solution {
public:
    vector<int> defeatMosters(vector<int> &monsters, int M) {
        vector<int> ans(monsters.size());
        multiset<int> muset;
        muset.insert(monsters[0]);
        auto ansit = muset.begin();
        for (int i = 1; i < monsters.size(); ++i) {
            int monster = monsters[i];
            muset.insert(monster);
            if (monster > *ansit) {
                ansit++;
            }
            if (i % M == 0) {
                ansit--;
            }
        }
        return ans;
    }
};

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> monsters;
    while (N--) {
        int x;
        cin >> x;
        monsters.push_back(x);
    }
    for (auto ans : Solution().defeatMosters(monsters, M)) {
        cout << ans << " ";
    }
    //system("pause");
    return 0;
}
