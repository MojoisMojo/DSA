#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[27] = { 0 };
        for (auto &ch : s) cnt[ch - 'a'] += 1;
        deque<char> st;
        unordered_set<char> dic;
        for (auto ch : s) {
            if (dic.find(ch) != dic.end()) { cnt[ch - 'a']--; continue; }
            // else ch not in dic/st:
            while (!st.empty() && cnt[st.back() - 'a'] > 1 && st.back() > ch) {
                cnt[st.back() - 'a']--;
                dic.erase(st.back());
                st.pop_back();
            }
            st.push_back(ch);
            dic.emplace(ch);
        }
        string res = "";
        while (!st.empty()) {
            res += st.front();
            st.pop_front();
        }
        return res;
    }
};

int main() {
    cout << Solution().removeDuplicateLetters("bcabc");
    //system("pause");
    return 0;
}
