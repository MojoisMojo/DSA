#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int s_size = s.size();
        int cnt = -1;
        string ans = "";
        for (int i = 0; i < s_size; i++) cnt += (s[i] == '1');
        while (cnt-- > 0) { s_size--; ans += "1"; }
        while (--s_size > 0) ans += "0";
        return ans + "1";
    }
};

int main() {
    cout << Solution().maximumOddBinaryNumber("11111");
    //system("pause");
    return 0;
}
