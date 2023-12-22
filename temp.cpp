#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> hh{ 10,6,4,8,1,5,9,11 };
    vector<int> id;
    vector<int> ans(hh.size(), 0);
    vector<int> id_ans{ 4,2,1,3,0 };
    auto cmp = [&](const int &i, int value)->bool {return hh[i] < value;};
    for (int i = 0; i < hh.size(); ++i) {
        auto it = lower_bound(id.begin(), id.end(), hh[i], cmp);
        // ans[i] = it - id.begin();
        // if(ans[i] > 0) ans[i] += 
        id.insert(it, i);
        for (auto i : id) {
            cout << i << " ";
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}
