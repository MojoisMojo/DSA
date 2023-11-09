#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        haystack = " " + haystack;
        needle = " " + needle;
        vector<int> next_start(m + 1);
        // 设置
        for (int i = 2, j = 0; i <= m; ++i) {
            while (j and needle[i] != needle[j + 1]) {
                j = next_start[j];
            }
            if (needle[i] == needle[j + 1]) ++j;
            next_start[i] = j;
        }

        for(int i = 1, j = 0; i <= n; i++){
            while(j and haystack[i] != needle[j + 1]) j = next_start[j];
            if(haystack[i] == needle[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }
};

int main() {
    
    //system("pause");
    return 0;
}
