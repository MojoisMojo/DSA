#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define MAX_ID 1000005

class Element {
public:
    int id;
    int strength;
    string s;
    inline Element(int id, int strength, const string &s) :id(id), strength(strength), s(s) { ; }
    inline Element(const Element &_e) : id(_e.id), strength(_e.strength), s(_e.s) { ; }
    // Element &operator=(const Element &other) { this->id = other.id; return *this; }
    inline bool operator<(const Element &other) {
        return this->id < other.id;
    }
    inline bool operator<=(const Element &other) {
        return this->id <= other.id;
    }
    inline bool operator>=(const Element &other) {
        return !(*this < other);
    }
    inline bool operator>(const Element &other) {
        return !(*this <= other);
    }
    inline bool operator==(const Element &other) {
        return this->id == other.id;
    }

    inline bool operator!=(const Element &other) {
        return !(*this == other);
    }

    inline friend ostream &operator<<(ostream &ost, const Element &e) {
        return ost << e.id << " " << e.s << " " << e.strength;
    }
};

Element(*id_map)[MAX_ID];

class TrieNode {
public:
    TrieNode *children[52];
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string &word) {
        TrieNode *node = root;
        for (char ch : word) {
            int i = ch - 'A';
            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(const std::string &word) {
        TrieNode *node = root;
        for (char ch : word) {
            int i = ch - 'A';
            if (node->children[i] == nullptr) {
                return false;
            }
            node = node->children[i];
            return node->isEnd;
        }
    }

    bool startsWith(const std::string &prefix) {
        TrieNode *node = root;
        for (char ch : prefix) {
            int i = ch - 'A';
            if (node->children[i] == nullptr) {
                return false;
            }
            node = node->children[i];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    std::cout << (trie.search("apple") ? "Found" : "Not Found") << std::endl;   // Output: Found
    std::cout << (trie.search("app") ? "Found" : "Not Found") << std::endl;     // Output: Not Found
    std::cout << (trie.startsWith("app") ? "Found" : "Not Found") << std::endl; // Output: Found
    return 0;
}
