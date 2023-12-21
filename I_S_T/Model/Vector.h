#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
#define minSize 10
template <class T>
class Vector {
    void changeCapacity(int new_capacity) {
        if (new_capacity < this->_currentSize) {
            throw("Capacity can not be smaller than size!");
            return;
        }
        this->_capacity = new_capacity;
        T *old = this->_arr;
        if (this->_capacity > 0) {
            this->_arr = new T[this->_capacity];
            memcpy(_arr, old, sizeof(T) * this->_currentSize);
        }
        else {
            this->_arr = nullptr;
        }
        delete[] old;
    }
    // 获取指定索引的元素
    int &get(int index) {
        if (index >= _currentSize) {
            throw("index overflows!");
        }
        return _arr[index];
    }
public:
    Vector() {
        _capacity = 10; // 初始容量为10
        _arr = new T[_capacity];
        _currentSize = 0;
    }
    ~Vector() {
        delete[] _arr;
        _arr = nullptr;
    }
    Vector(const Vector &other) {
        *this = other;
    }

    Vector &operator=(const Vector &other) {
        if (this == &other) return *this;
        this->~Vector();
        this->_capacity = other._capacity;
        this->_currentSize = other._currentSize;
        this->_arr = new T[this->_capacity];
        memcpy(_arr, other._arr, sizeof(T) * this->_currentSize);
        return *this;
    }

    // 向数组末尾添加元素，如果数组已满，扩展容量，扩展为原来的两倍
    void push_back(T value) {
        if (_currentSize >= _capacity) {
            this->changeCapacity((this->_capacity * 3) / 2);
        }
        _arr[_currentSize++] = value;
    }

    void pop_back() {
        this->erase(_currentSize - 1);
    }

    // 删除指定索引的元素，如果剩余元素不足capacity的一半，将capacity缩小一半，最小容量为10
    void erase(int index) {
        if (index >= _currentSize) {
            throw("index overflows!");
        }
        memmove(_arr + index, _arr + index + 1, ((--_currentSize) - index) * sizeof(T));
        // if (_capacity >= (minSize << 1) && _currentSize < ((1 + _capacity) >> 1)) {
        //     this->changeCapacity(this->_capacity >> 1);
        // }
    }

    int &operator[](int index) {
        return get(index);
    }

    // 返回数组当前大小
    int size() {
        return _currentSize;
    }

    // 返回数组容量
    int capacity() {
        return _capacity;
    }

    // 打印数组的所有元素
    void print() {
        for (int i = 0; i < _currentSize; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }

    void clear() {
        int _currentSize = 0;
    }

    void shrink_to_fit() {
        this->changeCapacity(this->_currentSize);
    }

private:
    T *_arr;
    int _capacity;
    int _currentSize;
};

#endif
