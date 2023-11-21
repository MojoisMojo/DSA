#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{ 1,2,3,4,5 };
    auto iv = v.begin();
    for (int i = 0; i < 7; ++i) {
        cout << *(iv++) << " ";
    }
    //system("pause");
    return 0;
}
