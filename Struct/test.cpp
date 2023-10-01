#include "146_LRU.cpp"

int main() {
    vector<string> ops{"LRUCache","put","put","get","put","get","put","get","get","get"};
    vector<vector<int>> params{ {2},{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4} };
    LRUCache *obj = nullptr;
    int N = ops.size();
    for (int i = 0; i < N; i++) {
        if (ops[i] == "LRUCache") {
            obj = new LRUCache(params[i][0]);
        }
        else if (ops[i] == "get") {
            if (!obj) { cout << "nullptr obj" << endl;continue; }
            cout << obj->get(params[i][0]) << endl;
        }
        else if (ops[i] == "put") {
            if (!obj) { cout << "nullptr obj" << endl;continue; }
            obj->put(params[i][0], params[i][1]);
        }
    }
    //system("pause");
    return 0;
}
