#include <bits/stdc++.h>

using namespace std;
struct cmp{
        bool operator() (int a, int b ){ 
            return a < b;
        }
    };
int main() {
    priority_queue<int, vector<int>, cmp> pq;
    // cmp => true, 选b，否则选a
    // less =》 is a less b ?
    pq.push(7);
    pq.push(10);
    pq.push(1);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    return 0;
}
