#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &st, const string &token) {
    vector<string> res;
    
    int length_of_token = token.size();
    size_t pos = 0;
    for (size_t edpos = st.find(token, pos);
        edpos != string::npos;
        pos = edpos + length_of_token, edpos = st.find(token, pos)
        ) {
        res.push_back(st.substr(pos, edpos - pos));
    }
    if (pos < st.size()) res.push_back(st.substr(pos));
    return res;
}

int main() {
    
    vector<string> vs = split("the good boy, f, yhh", ",");
    for (auto &v : vs) cout << v << "  ";
    //system("pause");
    return 0;
}
