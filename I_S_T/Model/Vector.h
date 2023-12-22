#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
namespace _Vector
{
    const static int minSize = 10;// 初始容量为10
} // namespace _Vector

template <class T>
class Vector {
    void changeCapacity(int new_capacity) {
        if (new_capacity < this->_currentSize) {
            throw runtime_error("Capacity can not be smaller than size!");
            return;
        }
        this->_capacity = new_capacity;
        T *old = this->_arr;
        if (this->_capacity > 0) {
            this->_arr = new T[this->_capacity];
            for (int i = 0; i < this->_currentSize; ++i) {
                _arr[i] = old[i];
            }
        }
        else {
            this->_arr = nullptr;
        }
        delete[] old;
        old = nullptr;
    }
    // 获取指定索引的元素
    T &get(int index) {
        if (index >= _currentSize) {
            throw runtime_error("index overflows!");
        }
        return _arr[index];
    }
public:
    Vector() {
        _capacity = _Vector::minSize;
        _arr = new T[_capacity];
        _currentSize = 0;
    }
    Vector(int _size) {
        _capacity = max(_Vector::minSize, _size);
        _currentSize = _size;
        _arr = new T[_capacity];
    }
    Vector(int _size, const T &t) {
        _capacity = max(_Vector::minSize, _size);
        _currentSize = _size;
        _arr = new T[_capacity];
        for (int i = 0; i < _currentSize; ++i) {
            _arr[i] = t;
        }
    }
    Vector(initializer_list<T> t_array) {
        _capacity = _currentSize = t_array.size();
        _arr = new T[_capacity];
        auto it = t_array.begin();
        for (int i = 0; i < _currentSize; it++, i++) {
            _arr[i] = *it;
        }
    }
    ~Vector() {
        if (_arr)
            delete[] _arr;
        this->_arr = nullptr;
        this->_capacity = 0;
        this->_currentSize = 0;
    }
    Vector(const Vector &other) {
        this->_capacity = other._capacity;
        this->_currentSize = other._currentSize;
        if (_capacity > 0) {
            this->_arr = new T[this->_capacity];
            for (int i = 0; i < this->_currentSize; ++i) {
                this->_arr[i] = other._arr[i];
            }
        }
        else {
            this->_arr = nullptr;
        }
    }

    Vector &operator=(const Vector &other) {
        if (this == &other) return *this;
        this->~Vector();
        this->_capacity = other._capacity;
        this->_currentSize = other._currentSize;
        if (_capacity > 0) {
            this->_arr = new T[this->_capacity];
            for (int i = 0; i < this->_currentSize; ++i) {
                this->_arr[i] = other._arr[i];
            }
        }
        return *this;
    }

    // 向数组末尾添加元素，如果数组已满，扩展容量，扩展为原来的1.5倍
    void push_back(T value) {
        if (_currentSize >= _capacity) {
            this->changeCapacity((this->_capacity * 3) / 2);
        }
        _arr[_currentSize++] = value;
    }

    void pop_back() {
        this->erase(_currentSize - 1);
    }

    // 删除指定索引的元素
    void erase(int index) {
        if (index >= _currentSize) {
            throw runtime_error("index overflows!");
        }
        else if (index == --_currentSize) {
        }
        else {
            for (int i = index; i < _currentSize - 1; ++i) {
                _arr[i] = _arr[i + 1];
            }
        }
    }

    T &operator[](int index) {
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

    friend ostream &operator<<(ostream &ost, const Vector<T> &v) {
        for (int i = 0; i < v._currentSize; i++) {
            ost << v._arr[i] << " ";
        }
        return ost;
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
