#include <iostream>
#include <unordered_map>
using namespace std;
class DisjointSetUnion {
private:
    unordered_map<int, int> f, rank;
    int number_of_connectedComponent;
public:
    DisjointSetUnion() { number_of_connectedComponent = 0; }
    int find(int x) {
        if (!f.count(x)) {
            f[x] = x;
            rank[x] = 1;
            ++number_of_connectedComponent;
        }
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return true;
        }
        --number_of_connectedComponent;
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return false;
    }

    int numberOfConnectedComponent() {
        return number_of_connectedComponent;
    }
};