#include <bits/stdc++.h>

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
    }
    Vector(const Vector &other) {
        *this = other;
    }

    Vector &operator=(const Vector &other) {
        if (this == &other) return *this;
        this->~Vector();
        this->_capacity = other._capacity;
        this->_currentSize = other._currentSize;
        this->_arr = new T[this._capacity];
        memcpy(_arr, other._arr, sizeof(T) * this->_currentSize);
        return *this;
    }

    // 向数组末尾添加元素，如果数组已满，扩展容量，扩展为原来的两倍
    void push_back(T value) {
        if (_currentSize >= _capacity) {
            this->changeCapacity(this->_capacity << 1);
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
        _currentSize--;
        for (int i = index; i < _currentSize; i++) {
            _arr[i] = _arr[i + 1];
        }
        if (_capacity >= (minSize << 1) && _currentSize < ((1 + _capacity) >> 1)) {
            this->changeCapacity(this->_capacity >> 1);
        }
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
        try {
            for (int i = 0; i < _currentSize; i++) {
                cout << _arr[i] << " ";
            }
            cout << endl;
        }
        catch () {
            cerr << "error" << endl;
        }
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


class Solution {
public:
    vector<int> defeatMosters(Vector<int> &monsters, int M) {
        priority_queue<int, vector<int>, greater<int>> minpq; // the biggest x/M numbers
        priority_queue<int> maxpq; // left numbers
        vector<int> ans;
        /**
         *
         * some nums > minpq.top() > maxpq.top() > some nums
         * when a number in, we have 2 situations,
         *      num > minpq.top();
         *      num <= minpq.top();
        */
        for (int i = 0; i < monsters.size(); ++i) {
            int monster = monsters[i];
            if (!minpq.empty() && monster > minpq.top()) {
                maxpq.push(minpq.top());
                minpq.pop();
                minpq.push(monster);
            }
            else {
                maxpq.push(monster);
            }
            if (i % M == 0) {
                minpq.push(maxpq.top());maxpq.pop();
            }
            ans.push_back(minpq.top());
        }
        return ans;
    }
};

int main() {
    int M, N;
    cin >> M >> N;
    Vector<int> monsters;
    while (N--) {
        int x;
        cin >> x;
        monsters.push_back(x);
    }
    for (auto ans : Solution().defeatMosters(monsters, M)) {
        cout << ans << " ";
    }
    cout << endl;
    //system("pause");
    return 0;
}
