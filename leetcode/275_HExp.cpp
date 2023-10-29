#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int c : citations) {
            cnt[min(c, n)]++; 
        }
        int s = 0;
        for (int i = n; ; --i) {
            s += cnt[i];
            if (s >= i) { 
                return i;
            }
        }
    }
};


int main() {

    //system("pause");
    return 0;
}
