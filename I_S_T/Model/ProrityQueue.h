#ifndef HEAP_H
#include "Heap.h"
#endif
#ifndef VECTOR_H
#include "Vector.h"
#endif
#ifndef FUNCTION_H
#include "function.h"
#endif
#ifndef PRORITYQUEUE
#define PRORITYQUEUE
template <class T, class cmp = Less<T>>
class ProrityQueue:public Heap<T,cmp> {

};

#endif