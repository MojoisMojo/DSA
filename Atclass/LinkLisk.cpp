#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode *Node) : val(value), next(Node) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (head) {
            ListNode *p = head->next;
            delete head;
            head = p;
        }
    }

    //在链表头部插入一个整数值
    void pushFront(int value) {
        //write ur code here.
        ListNode *pn = head;
        head = new ListNode(value, pn);
    }

    //在链表尾部插入一个整数值
    void pushBack(int value) {
        //write ur code here.
        if (!head) {
            pushFront(value);
            return;
        }
        // else head is not nullptr
        ListNode *p = head;
        while (p->next) p = p->next;
        p->next = new ListNode(value);
    }

    //检查链表中是否存在指定的整数值，如果存在返回true，否则返回false
    bool search(int value) {
        //write ur code here.
        if (!head) {
            return false;
        }
        // else head is not nullptr
        for (ListNode *p = head; p; p = p->next) {
            if (p->val == value) return true;
        }
        return false;
    }

    //从链表中删除指定的整数值，如果链表中不存在该值，则不执行任何操作
    void remove(int value) {
        //write ur code here.
        if (!head)  return;
        // else head is not nullptr
        if (head->val == value) {
            ListNode *to_delete = head;
            head = head->next;
            delete to_delete;
        }
        // head is not the target
        for (ListNode *p = head; p->next; p = p->next) {
            if (p->next->val == value) {
                ListNode *to_delete = p->next;
                p->next = p->next->next;
                delete to_delete;
                return;
            };
        }
        return;
    }

    //打印链表的内容,空格分隔
    void print() {
        //write ur code here.
        if (!head)  return;
        // else head is not nullptr
        for (ListNode *p = head; p; p = p->next) {
            cout << p->val << " ";
        }
        return;
    }
private:
    ListNode *head;
};


// #include "tools.h"


// int main(){
//    // code
//    return 0;
// }
