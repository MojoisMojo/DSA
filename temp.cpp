#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int idx[3] = { 1,2,3 };
    int *pos1 = idx,*pos2 = idx;
    cout << *(pos1++) * *(pos2++);
    string s = "" + 1;
    //system("pause");
    return 0;
}
