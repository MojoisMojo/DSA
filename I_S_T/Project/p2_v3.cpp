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

    ~Vector() {
        if (_arr)
            delete[] _arr;
        this->_arr = nullptr;
        this->_capacity = 0;
        this->_currentSize = 0;
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


template <class T, class cmp = Less<T>>
class ProrityQueue :public Heap<T, cmp> {
};

typedef struct E {
    int first, second;
    E(int first = 0, int second = 0) :first(first), second(second) {}
    friend bool operator<(const E &e1, const E &e2) {
        return e1.first < e2.first || (e1.first == e2.first && e1.second < e2.second);
    }
    friend bool operator>(const E &e1, const E &e2) {
        return e1.first > e2.first || (e1.first == e2.first && e1.second > e2.second);
    }
} E;
const static int NULLVAL = -1;
class Solution {
    Vector<int> Dijsktra(int n, Vector<Vector<E>> &graph, int start) {
        ProrityQueue<E, Greater<E>> pq;
        Vector<int> dis(n, NULLVAL);
        pq.push(E(dis[start] = 0, start));
        while (!pq.empty()) {
            auto e = pq.top(); pq.pop();
            int d = e.first, u = e.second;
            for (int i = 0; i < graph[u].size(); ++i) {
                int v = graph[u][i].first, w = graph[u][i].second;
                if (dis[v] != NULLVAL && d + w >= dis[v]) { continue; }
                dis[v] = d + w;
                pq.push(E(dis[v], v));
            }
        }
        return dis;
    }
public:
    int minDistanceToD(int n, Vector<Vector<int>> &edges, int s1, int s2, int d) {
        Vector<Vector<E>> graph1(n), graph2(n);
        for (int i = 0; i < edges.size(); ++i) {
            auto &edge = edges[i];
            int u = edge[0], v = edge[1], w = edge[2];
            graph1[u].push_back({ v,w });
            graph2[v].push_back({ u,w });
        }
        auto disfroms1 = Dijsktra(n, graph1, s1);
        auto disfroms2 = Dijsktra(n, graph1, s2);
        auto distod = Dijsktra(n, graph2, d);
        int ans = 0x7f7f7f7f;
        for (int i = 0; i < n; ++i) {
            if (disfroms1[i] != NULLVAL && disfroms2[i] != NULLVAL && distod[i] != NULLVAL)
                ans = min(ans, disfroms1[i] + disfroms2[i] + distod[i]);
        }
        return ans == 0x7f7f7f7f ? -1 : ans;
    }
};

int main() {
    int M, N, S1, S2, D;
    cin >> M >> N >> S1 >> S2 >> D;
    Vector<Vector<int>>edges;
    while (N--) {
        int u, v, w;
        cin >> u >> v >> w;
        Vector<int> e(3, 0);
        e[0] = u;
        e[1] = v;
        e[2] = w;
        edges.push_back(e);
    }
    try {
        cout << Solution().minDistanceToD(M, edges, S1, S2, D);
    }
    catch (runtime_error &e) {
        cerr << e.what() << endl;
    }
    //system("pause");
    return 0;
}
