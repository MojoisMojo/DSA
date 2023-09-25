#include <bits/stdc++.h>

using namespace std;


class CircularQueue {
public:
    CircularQueue(int capacity) {
        arr = new int[capacity];
        front_idx = 0;
        back_idx = -1;
        size = 0;
        max_capacity = capacity;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    int mod_cal(int value) {
        return (value + max_capacity) % max_capacity;
    }

    // 入队列，若队列已满则不添加
    void enqueue(int value) {
        //write ur code here.
        if (isFull()) return;
        arr[mod_cal(back_idx)] = value;
        back_idx = mod_cal(back_idx - 1);
        size++;
    }

    // 出队列
    void dequeue() {
        //write ur code here.
        if (isEmpty()) return;
        front_idx = mod_cal(front_idx + 1);
        size--;
    }

    // 返回队首元素
    int front() {
        //write ur code here.
        return arr[mod_cal(front_idx)];
    }

    // 返回队尾元素
    int rear() {
        //write ur code here.
        return arr[mod_cal(back_idx)];
    }

    // 检查是否为空
    bool isEmpty() {
        //write ur code here.
        return size == 0;
    }

    // 检查是否已满
    bool isFull() {
        //write ur code here.
        return size >= max_capacity;
    }

private:
    int *arr;
    int front_idx;
    int back_idx;
    int size;
    int max_capacity;
};

// #include "tools.h"


int main() {

    //system("pause");
    return 0;
}
