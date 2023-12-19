#include <iostream>
#include<string.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> defeatMosters(vector<int> &monsters, int M) {
        priority_queue<int, vector<int>, greater<int>> minpq; // the biggest x/M numbers
        priority_queue<int> maxpq; // left numbers
        vector<int> ans;
        /**
         *
         * some nums > minpq.top() > maxpq.top() > some nums
         * when a number in, we have 2 situations,
         *      num > minpq.top();
         *      num <= minpq.top();
        */
        for (int i = 0; i < monsters.size(); ++i) {
            int monster = monsters[i];
            if (!minpq.empty() && monster > minpq.top()) {
                maxpq.push(minpq.top());
                minpq.pop();
                minpq.push(monster);
            }
            else {
                maxpq.push(monster);
            }
            if (i % M == 0) {
                minpq.push(maxpq.top());maxpq.pop();
            }
            ans.push_back(minpq.top());
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
