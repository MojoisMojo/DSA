#include <bits/stdc++.h>

using namespace std;

class LockingTree {
    vector<unordered_set<int>> sons;
    vector<int> fathers;
    vector<int> states;
public:
    LockingTree(vector<int> &parent) {
        int N = parent.size();
        this->sons.resize(N);
        this->fathers.resize(N);
        this->states.resize(N,-1);
        for (int i = 0; i < N; i++) {
            int p = i;
            while ((p = parent[p]) != -1) this->sons[p].insert(i);
            this->fathers[i] = parent[i];
        }
    }
    
    bool lock(int num, int user) {
        if (this->states[num] != -1) return false;
        // else
        this->states[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (this->states[num] != user) return false;
        // else
        this->states[num] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (this->states[num] != -1) return false;
        // is locked
        bool valid = false;
        for (const int &son : this->sons[num]) {
            if (this->states[son] == -1) continue;
            valid = true;
            break;
        }
        if (!valid) return false;
        // else it has locked sons
        int p = num;
        while ((p = fathers[p]) != -1)
            if (this->states[p] != -1) return false;

        this->states[num] = user;
        for (const int &son : this->sons[num]) this->states[son] = -1;
        
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main() {
    
    //system("pause");
    return 0;
}
