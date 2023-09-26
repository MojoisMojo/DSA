#include <bits/stdc++.h>

using namespace std;

typedef class Node_ {
public:
    Node_() {
        prev = next = nullptr;
        key = value = -1;
    }
    Node_(int key, int value) {
        prev = next = nullptr;
        this->key = key;
        this->value = value;
    }
    Node_(Node_ *prev, Node_ *next) {
        this->prev = prev;
        this->next = next;
        this->key = -1;
        this->value = -1;
    }
    Node_(Node_ *prev, Node_ *next, int key, int value) {
        this->prev = prev;
        this->next = next;
        this->key = key;
        this->value = value;
    }
    friend class LRUCache;
private:
    Node_ *prev;
    Node_ *next;
    int key;
    int value;
}*PNode_;



class LRUCache {
public:
    LRUCache(int capacity) {
        sb = new Node_();
        sb->prev = sb->next = sb;
        this->_capacity = capacity;
        this->_size = 0;
    }

    // ~LRUCache() {
    //     ;
    // }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        // else
        moveToHead(cache[key]);
        return cache[key]->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // has found
            PNode_ pn = cache[key];
            pn->value = value;
            moveToHead(pn);
            return;
        }
        // not found
        PNode_ pn = new Node_(key, value);
        cache[key] = pn;
        addToHead(pn);
        _size++;
        if (_size > _capacity) {
            
            removeTail();

        }
    }
    
private:

    void addToHead(PNode_ pnode) {
        if (!pnode) return;
        pnode->next = sb->next;
        pnode->prev = sb;
        pnode->next->prev = pnode;
        pnode->prev->next = pnode;
    }

    void moveToHead(PNode_ pnode) {
        addToHead(removeNode(pnode));
    }

    PNode_ removeNode(PNode_ pnode) {
        if (pnode->next == pnode)
            return nullptr;
        pnode->prev->next = pnode->next;
        pnode->next->prev = pnode->prev;
        return pnode;
    }

    void removeTail() {
        if (sb->next == sb) return;
        PNode_ pn = removeNode(sb->prev);
        cache.erase(cache.find(pn->key));
        if (pn) delete pn;
    }
    int _size,_capacity;
    PNode_ sb;
    unordered_map<int, PNode_> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


