#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAX_r = 1e9 + 7;

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

/** @class 存储的Element均不相同*/
class Treap {
private:
    struct TreeNode {
    public:
        Element e;
        TreeNode *father, *left, *right;
        int priorty;//越小优先级越高
        TreeNode(const Element &_e) :father(nullptr), left(nullptr), right(nullptr), e(e) {
            priorty = rand() % MAX_r;
        }
        TreeNode(const TreeNode &node) :father(node.father), left(node.left), right(node.right), e(node.e) {
            priorty = rand() % MAX_r;
        }
    }*root;
    int size_;
    /// @brief 
    void turnLeft(TreeNode *node);
    void turnRight(TreeNode *node);
    void floatup(TreeNode *node);
    void sinkdown(TreeNode *node);
public:
    Treap();
    bool insert(const Element &e);
    bool erase(const Element &e);
};


int main() {
    srand(time(nullptr));
    int M, N;
    cin >> M >> N;
    Treap tp;
    string readed;
    while (M--) {
        int id;
        string s;
        int strength;
        getline(cin, readed);
        stringstream sst(readed);
        sst >> id >> s >> strength;
        tp.insert(Element(id, strength, s));
    }
    while (N--) {

    }

    //system("pause");
    return 0;
}

void Query(Treap &T, string &instr) {//传进来的去掉了“QUERY ”
    if (instr.find("name =") != string::npos) {
        instr.erase(0, 7);
        T.FindName(T.root, instr);

    }
    else if (instr.find("strength") != string::npos) {
        if (instr[0] == 's' && instr[1] == 't') {
            instr.erase(0, 9);
            int f;
            string temp = instr.substr(0, 2);
            if (temp == "> ") {
                f = 0;
                instr.erase(0, 2);
            }
            else if (temp == "< ") {
                f = 1;
                instr.erase(0, 2);
            }
            else if (temp == ">=") {
                f = 2;
                instr.erase(0, 3);
            }
            else if (temp == "<=") {
                f = 3;
                instr.erase(0, 3);
            }
            else if (temp == "!=") {
                f = 4;
                instr.erase(0, 3);
            }
            else if (temp == "= ") {
                f = 5;
                instr.erase(0, 2);
            }

            T.FindCompareOne(T.root, f, stoi(instr));
        }
        else {
            string temp_id1 = instr.substr(0, instr.find_first_of(" "));
            instr.erase(0, instr.find_first_of(" ") + 1);
            string temp_id2 = instr.substr(0, instr.find_first_of(" "));
            instr.erase(0, instr.find_first_of(" ") + 1);
            instr.erase(0, 9);
            int f;
            string temp = instr.substr(0, 2);
            if (temp == "> ") {
                f = 0;
                instr.erase(0, 2);
            }
            else if (temp == "< ") {
                f = 1;
                instr.erase(0, 2);
            }
            else if (temp == ">=") {
                f = 2;
                instr.erase(0, 3);
            }
            else if (temp == "<=") {
                f = 3;
                instr.erase(0, 3);
            }
            else if (temp == "!=") {
                f = 4;
                instr.erase(0, 3);
            }
            else if (temp == "= ") {
                f = 5;
                instr.erase(0, 2);
            }


            T.FindCompareTwo(T.root, f, stoi(instr), stoi(temp_id1), stoi(temp_id2));
        }

    }
    else {
        T.FindID(stoi(instr));
    }

}
Treap::Treap(/* args */) {
    root = nullptr;
    size_ = 0;
}

bool Treap::insert(const Element &e) {
    TreeNode **pos = &root, *F = nullptr;
    while (*pos) {
        F = *pos;
        if ((*pos)->e < e) {
            pos = &((*pos)->right);

        }
        else if ((*pos)->e == e)
            return false;
        else {
            pos = &((*pos)->left);
        }
    }
    *pos = new TreeNode(e);
    (*pos)->father = F;
    floatup(*pos);
    ++size_;
    return true;
}

bool Treap::erase(const Element &e) {
    TreeNode **pos = &root;
    while (*pos) {
        if ((*pos)->e < e) pos = &((*pos)->right);
        else if ((*pos)->e == e) break;
        else pos = &((*pos)->left);
    }
    if (*pos) {
        sinkdown(*pos);
        TreeNode *F = (*pos)->father;
        if (!F) { ; }
        else if (F->left == *pos) { F->left = nullptr; }
        else if (F->right == *pos) { F->right = nullptr; }
        delete *pos;
        *pos = nullptr;
        --size_;
        return true;
    }
    return false;
}
/**
 * @param pnode 需要左转的节点
*/
void Treap::turnLeft(TreeNode *node) {
    if (!node->right) return;
    TreeNode *sonr = node->right;
    TreeNode *F = node->father;

    node->right = sonr->left;
    if (sonr->left) sonr->left->father = node;
    sonr->left = node;

    sonr->father = F;
    if (!F) {
        root = sonr;
        return;
    }
    if (F->e > sonr->e) {
        F->left = sonr;
    }
    else {
        F->right = sonr;
    }

}
/**
 * @param pnode 需要右转的节点
*/
void Treap::turnRight(TreeNode *node) {
    if (!node->left) return;
    TreeNode *sonl = node->left;
    TreeNode *F = node->father;

    node->left = sonl->right;
    if (sonl->right) sonl->right->father = node;
    sonl->right = node;


    sonl->father = F;
    if (!F) {
        root = sonl;
        return;
    }
    if (F->left == node) {
        F->left = sonl;
    }
    else {
        F->right = sonl;
    }
}

void Treap::floatup(TreeNode *node) {
    TreeNode *F = node->father;
    for (;F && node->priorty < F->priorty;F = node->father) {
        if (F->right == node) {
            // node 从father的右边来
            turnLeft(F);
        }
        else {
            turnRight(F);
        }
    }
}

void Treap::sinkdown(TreeNode *node) {
    for (TreeNode *sl = node->left, *sr = node->right; sl || sr; sl = node->left, sr = node->right) {
        bool isturnLeft = (sr && (!sl || sr->priorty < sl->priorty));
        isturnLeft ? turnLeft(node) : turnRight(node);
    }
}