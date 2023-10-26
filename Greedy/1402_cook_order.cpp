#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), [](int a, int b)->bool {return a > b;});
        int i = 0;
        for (;i < satisfaction.size() - 1 && satisfaction[i] > 0;i++) {
            satisfaction[i + 1] += satisfaction[i];
        }
        if (satisfaction[i] < 0) i--;
        int ans = 0;
        while (i > 0) {
            ans += satisfaction[i--];
        }
        return ans;
    }
};

int main() {
    
    //system("pause");
    return 0;
}
