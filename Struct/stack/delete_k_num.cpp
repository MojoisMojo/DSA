#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        deque<char> dq;
        for (const auto &ch : num) {
            while (!dq.empty() && dq.back() > ch && k-- > 0) dq.pop_back();
            dq.push_back(ch);
        }
        while(k-- > 0) dq.pop_back();
        string res = "";
        while (!dq.empty() && dq.front() == '0') dq.pop_front();
        while (!dq.empty()) { res += dq.front(); dq.pop_front(); }
        return res == "" ? "0" : res;
    }
};

int main() {
    int n;
    cin >> n;
    int a[n] = {0};

    //system("pause");
    return 0;
}
