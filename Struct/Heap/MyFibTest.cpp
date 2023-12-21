#include "FibHeap.h"

int main() {
    stack<FibHeap *> fb_stack;
    string line;
    string op;
    FibHeap *fheap = nullptr;

    while (getline(cin,line)) {
        stringstream inputs(line);
        inputs >> op;
        int val, val2;
        if (op == "FibHeap") {
            fb_stack.push(fheap);
            fheap = new FibHeap;
        }
        else if (fheap == nullptr) {  cerr << "no heap!!\n";continue;  }
        else if (op == "print") {
            fheap->print();
        }
        else if (op == "top") {
            clog << fheap->minimum() << endl;
        }
        else if (op == "pop") {
            clog << fheap->minimum() << endl;
            fheap->removeMin();
        }
        else if (op == "destroy") {
            fheap->destroy();
        }
        else if (op == "delete") {
            delete fheap;
            if (fb_stack.empty()) fheap = nullptr;
            else { fheap = fb_stack.top();  fb_stack.pop(); }
        }
        else if (op == "uion") {
            if (fb_stack.empty()) continue;
            fheap->unionHeap(fb_stack.top());
        }

        
        else if (!(inputs >> val)) { cerr << "no args!!\n";continue; }
        else if (op == "insert") {
            fheap->insert(val);
        }
        else if (op == "contains") {
            clog << (fheap->contains(val) ? "exist" : "not exist") << endl;
        }
        else if (op == "remove") {
            fheap->remove(val);
        }

        else if (!(inputs >> val2)) { cerr << "no args!!\n";continue; }
        else if (op == "update") {
            fheap->update(val, val2);
        }
    }

}