#include <bits/stdc++.h>

using namespace std;

struct DSUNode {
    int val;
    DSUNode *f;
    int rank;
    DSUNode(int v = -1, DSUNode *f = nullptr, int rank = 1)
        :val(v), f(f), rank(rank) {
        ;
    }
};

class DisjointSetUnion {
private:
    unordered_set<DSUNode *> hashmap;
    int number_of_connectedComponent;

public:
    DisjointSetUnion() { number_of_connectedComponent = 0; }
    DSUNode *find(DSUNode *x) {
        if (!hashmap.count(x)) {
            x->f = x;
            hashmap.emplace(x);
            ++number_of_connectedComponent;
        }
        return x->f == x ? x : x->f = find(x->f);
    }


    void unionSet(DSUNode *x, DSUNode *y = nullptr) {
        DSUNode *fx = find(x);
        if (!y) return;
        DSUNode *fy = find(y);
        if (fx == fy) {
            return;
        }
        --number_of_connectedComponent;
        if (fx->rank < fy->rank) {
            swap(fx, fy);
        }
        fx->rank += fy->rank;
        fy->f = fx;
    }

    int numberOfConnectedComponent() {
        return number_of_connectedComponent;
    }
};

int main() {

}