#ifndef VECTOR_H
#include "Vector.h"
#endif
#ifndef FUNCTION_H
#include "function.h"
#endif
#ifndef HEAP_H
#define HEAP_H
template <class T, class cmpclass = Less<T>>
class Heap {
public:
    Heap() :_size(0) {
        _arr.push_back(T());
    }
    ~Heap() {
        _size = 0;
        _arr.clear();
    }

    void push(T val) {
        _size++;
        _arr.push_back(val);
        flowup();
    }

    void pop() {
        if (_size == 0) return;
        _arr[1] = _arr[_size--];
        _arr.pop_back();
        sinkdown();
    }

    inline T top() {
        if (empty()) { throw runtime_error("heap is empty!"); }
        return _arr[1];
    }

    inline size_t size() {
        return _size;
    }

    void print() {
        for (size_t i = 1; i <= _size; ++i) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }

    inline bool empty() {
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
    inline size_t father(size_t idx) {
        return idx >> 1;
    }

    inline size_t son_l(size_t idx) {
        return idx << 1;
    }

    inline size_t son_r(size_t idx) {
        return 1 + (idx << 1);
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
        if (empty()) return;
        for (size_t pos = 1; ; ) {
            size_t sonl = son_l(pos), sonr = son_r(pos);
            if (sonl > _size && sonr > _size) return;
            size_t toswap = sonl;
            if (sonl > _size) toswap = sonr;
            else if (sonr <= _size) {
                toswap = (cmp(_arr[sonr], _arr[sonl]) ? sonl : sonr);
            }
            if (!cmp(_arr[pos], _arr[toswap]))
                return;
            swap(_arr[pos], _arr[toswap]);
            pos = toswap;
        }
    }
};
#endif