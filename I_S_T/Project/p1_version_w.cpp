#include <iostream>
#include <string.h>
#include <string>

using namespace std;

template<class T>
class Greater {
public:
    bool operator()(const T &t1, const T &t2) {
        return t1 > t2;
    }
};
template<class T>
class Less {
public:
    bool operator()(const T &t1, const T &t2) {
        return t1 < t2;
    }
};

template <class T>
class Vector {
    const int minSize = 10;
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
        this->_arr = new T[this->_capacity];
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

template <class T, class cmpclass = Less<T>>
class Heap {
public:
    Heap() :_size(0) {
        _arr.push_back(T());
    }
    ~Heap() {
        _size = 0;
        // delete _arr;
    }

    void push(T val) {
        //write ur code here.
        _size++;
        _arr.push_back(val);
        flowup();
    }

    void pop() {
        //write ur code here.
        if (_size == 0) return;
        _arr[1] = _arr[_size--];
        _arr.pop_back();
        sinkdown();
    }

    T top() {
        //write ur code here.
        if (empty()) { throw("heap is empty!"); }
        return _arr[1];
    }

    size_t size() {
        //write ur code here.
        return _size;
    }

    void print() {
        for (size_t i = 1; i <= _size; ++i) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }

    bool empty() {
        return _size == 0;
    }

protected:
    cmpclass cmp;
    Vector<T> _arr;
    size_t _size;
    /**
 * 1
 * 2,           3
 * 4,   5       6,      7
 * 8,9  10,11   12,13   14,15
 *
 *
*/
    size_t father(size_t idx) {
        return idx >> 1;
    }

    size_t son_l(size_t idx) {
        size_t l = idx << 1;
        return l <= _size ? l : 0;
    }

    size_t son_r(size_t idx) {
        size_t r = 1 + (idx << 1);
        return r <= _size ? r : 0;
    }

    void flowup() {
        // push 之后
        for (size_t pos = _size, _father = father(pos);
            _father != 0 && cmp(_arr[_father], _arr[pos]);
            pos = _father, _father = father(pos))
            swap(_arr[pos], _arr[_father]);
    }

    void sinkdown() {
        // pop 之后
        if (_size == 0) return;
        for (size_t pos = 1; ; ) {
            size_t sonl = son_l(pos), sonr = son_r(pos);
            if (sonl == 0 && sonr == 0) return;
            size_t toswap = (cmp(_arr[sonr], _arr[sonl]) ? sonl : sonr);
            if (!cmp(_arr[pos], _arr[toswap]))
                return;
            swap(_arr[pos], _arr[toswap]);
            pos = toswap;
        }
    }
};

template <class T, class cmp = Less<T>>
class ProrityQueue:public Heap<T,cmp> {

};

class Solution {
public:
    Vector<int> defeatMosters(Vector<int> &monsters, int M) {
        ProrityQueue<int, Greater<int>> minpq; // the biggest x/M numbers
        ProrityQueue<int> maxpq; // left numbers
        Vector<int> ans;
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
    Solution().defeatMosters(monsters, M).print();
    //system("pause");
    return 0;
}
