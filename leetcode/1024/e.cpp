#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;

vector<int> countSets(int n, int k, int m) {
    vector<vector<int>> dp(m, vector<int>(m, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int a = 1; a <= n; ++a) {
                dp[i][j] = (dp[i][j] + dp[i - 1][(j - a + m) % m]) % MOD;
            }
        }
    }
    
    vector<int> answer(m);
    for (int i = 0; i < m; ++i) {
        answer[i] = dp[n][i];
    }
    
    return answer;
}

int main() {
    int n = 2;
    int k = 1;
    int m = 3;
    
    vector<int> result = countSets(n, k, m);
    
    for (int i = 0; i < m; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}
