#include <bits/stdc++.h>

using namespace std;



class Solution {
    bool check(int x, int t) {
        if (x < 0 || t < 0) return false;
        if (x == t) return true;
        if (x == 0) return false;
        int i = 1;
        while (x > 0) {
            t -= i * (x % 10);
            x /= 10;
            i *= 10;
            if (check(x, t)) {
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int powi = i * i;
            if (check(powi, i)) {
                sum += powi;
            }
        }
        return sum;
    }
};



int main() {
    cout << Solution().punishmentNumber(1000);
    //system("pause");
    return 0;
}
