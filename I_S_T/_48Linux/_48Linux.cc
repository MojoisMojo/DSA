#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ptr = 0;
    // 建议不要原地修改
    while (ptr != s.size() - 1) {
        if (s[ptr] == '/') {
            // 处理 多重'/' 建议使用while循环处理比较易懂
            if (s[ptr + 1] == '/') {
                s = s.substr(0, ptr + 1) + s.substr(ptr + 2, s.size() - ptr - 2);
            }
            else if (s[ptr + 1] != '.') {
                ptr++;
                while (s[ptr] != '/' && ptr < s.size() - 1) ptr++;
            }
            else if (s[ptr + 1] == '.') {
                bool isname = false;
                for (int i = ptr + 2;;) {
                    if (isalpha(s[i])) isname = true;
                    if (s[i] == '/') break;
                    i++;
                }
                if (isname) {
                    while (s[ptr + 1] != '/') ptr++;
                    ptr++;
                }
                else {
                    if (s[ptr + 2] == '/') {
                        s = s.substr(0, ptr + 1) + s.substr(ptr + 3, s.size() - ptr - 3);
                    }
                    else {
                        int index = 0;
                        for (index = ptr - 1;s[index] != '/';index--);
                        s = s.substr(0, index + 1) + s.substr(ptr + 4, s.size() - ptr - 4);
                        ptr = index;
                    }
                }
            }
        }
    }
    if (s[s.size() - 1] == '/') s = s.substr(0, s.size() - 1);
    cout << s;
    return 0;
}