#include <bits/stdc++.h>

using namespace std;

int main() {

    //system("pause");
    return 0;
}

class Solution {
public:
    int specialChopsticks(vector<int> &chopsticks) {
        sort(chopsticks.begin(), chopsticks.end());
        int length = chopsticks.size();
        // 1 2 3 5 6
        if (chopsticks[0] >= length) return length;
        for (int x = length - 1; x > 0;--x) {
            if (chopsticks[length - x] >= x && chopsticks[length - x - 1] < x)
                return x;
        }
        return -1;
    }
};