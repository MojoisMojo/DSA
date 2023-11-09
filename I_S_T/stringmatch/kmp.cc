#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool strStr(string src_string, string token) {
        int n = src_string.size(), m = token.size();
        if (m == 0) return false;
        src_string = " " + src_string;
        token = " " + token;
        int *next_start = new int[m + 1] {0};
        bool found = false;
        for (int i = 2, j = 0; i <= m; ++i) {
            while (j and token[i] != token[j + 1]) {
                j = next_start[j];
            }
            if (token[i] == token[j + 1]) ++j;
            next_start[i] = j;
        }

        for(int i = 1, j = 0; i <= n; i++){
            while(j and src_string[i] != token[j + 1]) j = next_start[j];
            if(src_string[i] == token[j + 1]) j++;
            if (j == m) { cout << i - m << " "; found = true; }
        }
        delete[]next_start;
        return found;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    string src_string, token;
    cin >> src_string >> token;
    if (! Solution().strStr(src_string, token)) {
        cout << -1;
    }
    cout << endl;
    //system("pause");
    return 0;
}

