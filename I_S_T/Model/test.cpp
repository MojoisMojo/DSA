#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "ProrityQueue.h"
int main() {
    ProrityQueue<int> pq;
    while (!cin.eof()) {
        string line_string;
        getline(cin, line_string);
        stringstream line_input(line_string);
        string op;
        line_input >> op;
        if (op == "push") {
            int id;
            line_input >> id;
            pq.push(id);
        }
        else if (op == "pop") {
            pq.pop();
        }
        else if (op == "top") {
            cout << pq.top() << endl;
        }
        else if (op == "size") {
            cout << pq.size() << endl;
        }
        else if (op == "empty") {
            cout << (pq.empty() ? "Yes" : "No") << endl;
        }
        else if (op == "print") {
            pq.print();
        }
    }
    //system("pause");
    return 0;
}