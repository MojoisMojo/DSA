#include <iostream>
#include <stack>
using namespace std;

int main() {
    int x;
    goto hh;
l:
    x = 0;
hh: x = 1;
    goto l;
}