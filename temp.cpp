#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    int idx[3] = { 1,2,3 };
    int *pos1 = idx,*pos2 = idx;
    cout << *(pos1++)**(pos2++);

    //system("pause");
    return 0;
}
