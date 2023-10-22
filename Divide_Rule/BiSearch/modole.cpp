#include <bits/stdc++.h>

using namespace std;

bool check(long long x);

int modoleOne() {
    long long l = 0, r = 2e8;
    while (l < r) {
        long long mid = l + ((r - l + 1) >> 1); //mid > l
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
    
}

int modoleTwo() {
    long long l = 0, r = 2e8;
    long long res = -1;
    while (l <= r) {
        long long mid = l + ((r - l) >> 1);
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res == -1 ? 0 : res;
}

int modoleThree() {
    long long l = 0, r = 2e8+10;
    while (l + 1 < r) { // 开区间模板 左闭右开
        long long mid = l + ((r - l) >> 1);
        if (check(mid)) l = mid; // need right half
        else r = mid;
    }
    return l;
}

int main() {

    //system("pause");
    return 0;
}
