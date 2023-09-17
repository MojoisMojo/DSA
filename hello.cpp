#include <iostream>
#include <stack>
using namespace std;

class MonotonicStack
{
private:
    stack<int> s;
public:
    int size() { return s.size(); }
    void pop() { if (!s.empty())s.pop(); }
    int top() { return s.top(); };
    int push(int element) {
        int r = 0;
        while (!s.empty() && s.top() > element) { r += 1;s.pop(); }
        s.push(element);
        return r;
    }
    int function(const int *arr, int n) {
        int res = 0;
        for (int i = 0; i < n; i++) res = res + arr[i] * (1 - this->push(arr[i]));
        return res;
    }
};

/*
其中成员变量s是stl中的stack类型的变量，是已经封装实现好的数据结构。
你可以使用它，使用s.size()将返回s内元素数量，使用s.push(int)将一个int型值入栈s，
s.top()返回s的栈顶元素，而s.pop()将弹出s的栈顶元素。
提示：在使用stack s时，进行s.pop()和s.top()前，应当检查s内是否有元素，否则容易引发段错误。

push的返回值在用例中不会进行测试（你可以返回任何值），这个返回值是一个保留接口：
你可以思考如何利用这个返回值巧妙地解决Part-2的问题 :)

需要你补充的内容已在MonotonicStack.cpp中用TODO标出！
需要你补充的内容已在MonotonicStack.cpp中用TODO标出！
需要你补充的内容已在MonotonicStack.cpp中用TODO标出！
*/
int main() {
    MonotonicStack *s = new MonotonicStack;
    // s->push(8);
    // s->push(4);
    // s->push(6);
    // s->push(2);
    // s->push(3);
    // cout << s->top() << ' ';
    int arr[] = { 8,4,6,2,3 };
    cout << s->function(arr, 5) << endl;
    delete s;
}