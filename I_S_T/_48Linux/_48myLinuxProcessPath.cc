#include <iostream>
#include <string>
#include <queue>

using namespace std;

const char split_char = '/';
const string dot_token = ".";
const string last_token = "..";

// if found return idx, else return s.size();
int findNext(const string &s, char toke = '/', int start_pos = 0) {
    for (int i = start_pos;i < s.size(); ++i) {
        if (s[i] == toke) return i;
    }
    return s.size();
}

// ed 为 开区间
void processToken(const string &s, int st, int ed, deque<string> &simply) {
    // 是名字、是上级、是本级、是多重

    if (st + 1 >= ed) return; // 多重split

    string token = s.substr(st + 1, ed - st - 1);

    // 上级
    if (token == last_token) {
        if (!simply.empty()) {
            simply.pop_back();
        }
        return;
    }

    // 本级
    if (token == dot_token) {
        return;
    }

    simply.push_back(token);
}



int main() {
    string origin;
    cin >> origin;
    deque<string> simply; // 注意这个不存 split_char
    int pos = 0;
    while (pos < origin.size()) {
        if (origin[pos] != split_char) {
            try {
                throw "wtf";
            }
            catch (string s) {
                cout << s << endl;
            }
            continue;
        }
        // else
        int next_pos = findNext(origin, split_char, pos + 1);
        processToken(origin, pos, next_pos, simply);
        pos = next_pos;
    }

    if (simply.empty()) {
        cout << split_char << endl;
        return 0;
    }
    //else
    while (!simply.empty()) {
        cout << split_char << simply.front(); simply.pop_front();
    }
    cout << endl;
    //system("pause");
    return 0;
}
