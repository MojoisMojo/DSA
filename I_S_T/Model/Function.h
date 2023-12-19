#ifndef FUNCTION_H
#define FUNCTION_H

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
#endif