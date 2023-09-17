#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int cal_Single(int budget, int n, const vector<int> &single_composition, vector<int> stock, const vector<int> &cost) {
        if (budget <= 0) return 0;
        int ans = 0;
        while (true) {
            int thiscost = 0;
            for (int j = 0; j < n; j++) {
                if (stock[j] >= single_composition[j]) {stock[j] -= single_composition[j];}
                else {
                    thiscost += (single_composition[j] - stock[j]) * cost[j];
                    if (thiscost > budget) return ans;
                    stock[j] = 0;
                }
            }
            if (thiscost > budget) return ans;
            // else
            budget -= thiscost;
            ans += 1;
        }
        return ans;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost) {
        if (k == 0 || budget <= 0) return 0;
        if (k == 1) return cal_Single(budget, n, composition[0], stock, cost);
        int this_max = cal_Single(budget, n, composition[0], stock, cost);
        vector<vector<int>> this_comp(composition.begin() + 1, composition.end());
        int this_budget = budget;
        vector<int> this_stock = stock;
        int ans = maxNumberOfAlloys(n, k - 1, this_budget, this_comp, this_stock, cost);

        for (int this_produce = 1; this_produce <= this_max && this_budget > 0; this_produce++) {
            for (int j = 0; j < n; j++) {
                if (this_stock[j] >= composition[0][j]) { this_stock[j] -= composition[0][j]; }
                else {
                    this_budget -= (composition[0][j] - this_stock[j]) * cost[j];
                    this_stock[j] = 0;
                }
            }
            ans = max(ans, this_produce + maxNumberOfAlloys(n, k - 1, this_budget, this_comp, this_stock, cost));

        }
        return ans;
    }
};
int main() {
    vector<vector<int>> c{
        {1,8,4,1,9,7,4},
        {8,1,3,3,9,4,5},
        {8,5,4,2,9,9,10},
        {2,10,3,3,3,10,8},
        {6,3,1,3,7,1,7},
        {3,5,7,6,8,10,10},
        {2,10,10,2,2,7,7},
        {3,2,10,9,4,1,2},
        {2,7,1,8,2,7,10},
        {10,9,2,8,10,1,4}
    };
    vector<int> s{ 0,3,5,10,0,9,9 };
    vector<int> cost{ 3,5,4,8,10,1,2 };
    cout << Solution().maxNumberOfAlloys(
        7, 10, 117, c,s,cost
    );
    //system("pause");
    return 0;
}
