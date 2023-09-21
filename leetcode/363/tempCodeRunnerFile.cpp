class Solution {

    int cal_Single(int budget, int n, const vector<int> &single_composition, vector<int> stock, const vector<int> &cost) {
        if (budget < 0) return 0;
        long ans = 0;
        long l = 0, r = max_element(stock.begin(), stock.end())[0] + budget;
        long this_money = 0;
        while (l + 1 < r) {
            long mid = l + (r - l) >> 1;
            bool valid = true;
            for (int i = 0; i < n && valid; i++,valid = (budget < this_money)) {
                this_money += max(0L, (single_composition[i] * mid - stock[i]) * cost[i]);
            }
            if (valid) l = mid;
            else r = mid;
            ans = max(ans, l);
        }
        return (int)ans;
    }
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost) {
        if (k == 0 || budget < 0) return 0;
        if (k == 1) return cal_Single(budget, n, composition[0], stock, cost);
        int ans = 0;
        for (int i = 0; i < k; i++) ans = max(ans, cal_Single(budget, n, composition[i], stock, cost));
        return (int)ans;
    }
};