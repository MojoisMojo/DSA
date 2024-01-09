#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        // 长度 + 个数
        vector<pair<int, int>> maxChar(26, { 0,0 }), secondmaxChar(26, { 0,0 });
        for (int i = 0; i < s.size();) {
            char target = s[i];
            int length = 1;
            while (++i < s.size() && s[i] == target) {
                length++;
            }
            int idx = target - 'a';
            if (maxChar[idx].first < length) {
                secondmaxChar[idx] = maxChar[idx];
                maxChar[idx] = { length,1 };
            }
            else if (maxChar[idx].first == length) {
                maxChar[idx] = { length, maxChar[idx].second + 1 };
            }
            else if (secondmaxChar[idx].first < length) {
                secondmaxChar[idx] = { length,1 };
            }
            else if (secondmaxChar[idx].first == length) {
                secondmaxChar[idx] = { length, secondmaxChar[idx].second + 1 };
            }
        }
        int ans = -1;
        for (int i = 0; i < 26; ++i) {
            int maxlength = maxChar[i].first,
                maxNum = maxChar[i].second,
                s_maxlength = secondmaxChar[i].first,
                s_maxNum = secondmaxChar[i].second;
            if (maxlength == 0) { continue; }
            int temp = -1;
            temp = maxlength - max(3 - maxNum, 0);
            if (s_maxlength != 0 && s_maxlength > temp && s_maxNum > 1) {
                temp + 1;
            }
            ans = max(temp < 1 ? -1 : temp, ans);
        }
        return ans;
    }
};

int main() {

    //system("pause");
    return 0;
}
