#include<bits/stdc++.h>
using namespace std;
#define minSize 10
class DynamicArray {
public:
    DynamicArray() {
        _capacity = 10; // 初始容量为10
        _arr = new int[_capacity];
        _currentSize = 0;
    }
    ~DynamicArray() {
        delete[] _arr;
    }

    // 向数组末尾添加元素，如果数组已满，扩展容量，扩展为原来的两倍
    void append(int value) {
        if (_currentSize < _capacity) {
            ;
        }
        else {
            int *new_arr = new int[_capacity << 1];
            for (int i = 0; i < _capacity; i++) {
                new_arr[i] = _arr[i];
            }
            free(_arr);
            _arr = new_arr;
        }
        _arr[_currentSize++] = value;
        //write ur code here.
    }

    // 删除指定索引的元素，如果剩余元素不足capacity的一半，将capacity缩小一半，最小容量为10
    void erase(int index) {
        _currentSize--;
        for (int i = index; i < _currentSize; i++) {
            _arr[i] = _arr[i + 1];
        }
        if (_capacity >= (minSize << 1) && _currentSize < ((1 + _capacity) >> 1)) {
            _capacity >>= 1;
        }
        //write ur code here.
    }

    // 获取指定索引的元素
    int get(int index) {
        //write ur code here.
        return _arr[index];
    }

    // 设置指定索引的元素值
    void set(int index, int value) {
        //write ur code here.
        _arr[index] = value;
    }

    // 返回数组当前大小
    int size() {
        //write ur code here.
        return _currentSize;
    }

    // 返回数组容量
    int capacity() {
        //write ur code here.
        return _capacity;
    }

    // 打印数组的所有元素
    void print() {
        //write ur code here.
        for (int i = 0; i < _currentSize; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }

private:
    int *_arr;
    int _capacity;
    int _currentSize;
};

// #include "tools.h"


// int main() {
//     // code
//     string op;
//     DynamicArray *da;
//     while (cin >> op) {
//         if (op == "DynamicArray") {
//             da = new DynamicArray();
//             continue;
//         }
//         else if (op == "print") {
//             da->print();
//             continue;
//         }
//         else if (op == "size") {
//             da->size();
//             continue;
//         }
//         else if (op == "capacity") {
//             da->capacity();
//             continue;
//         }
//         int first;
//         cin >> first;
//         if (op == "append") {
//             da->append(first);
//             continue;
//         }
//         else if (op == "erase") {
//             da->erase(first);
//             continue;
//         }
//         else if (op == "get") {
//             da->get(first);
//             continue;
//         }
//         else if (op == "set") {
//             int second;
//             cin >> second;
//             da->set(first, second);
//             continue;
//         }
//         else {
//             ;
//         }
//     }return 0;
// }
