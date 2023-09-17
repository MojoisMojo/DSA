#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        auto check = [&](long long X) {
            for(auto &cmp : composition)
            {
                long long money = 0;
                for(int i=0;i<n;++i)
                {
                    if(stock[i] < X*cmp[i])
                        money += (X*cmp[i]-stock[i])*cost[i];
                }
                if(money <= budget) return true;
            }
            return false;
        };

        long long l= 0, r = 2e8;
        while(l < r)
        {
            long long mid = l +  ((r - l + 1) >> 1);
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
