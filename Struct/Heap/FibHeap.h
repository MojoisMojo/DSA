#include <bits/stdc++.h>

using namespace std;

/// <summary>
    /// 斐波那契堆
    /// </summary>
class FibHeap {
private:
    int keyNum;         // 堆中节点的总数

    struct FibNode {
        int key;            // 关键字(键值)
        int degree;            // 度数
        FibNode *left;        // 左兄弟
        FibNode *right;        // 右兄弟
        FibNode *child;        // 第一个孩子节点
        FibNode *parent;        // 父节点
        bool marked;     // 是否被删除第一个孩子

        FibNode(int key)
            :key(key), degree(0), marked(false), left(this), right(this), parent(nullptr), child(nullptr) {
        }
    }*min;        // 最小节点(某个最小堆的根节点)

public:
    FibHeap() {
        this->keyNum = 0;
        this->min = nullptr;
    }
    ~FibHeap() {
        this->destroy();
    }
private:
    /*
     * 将node从双链表移除
     */
    void removeNode(FibNode *node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }
public:
    /*
     * 将node堆结点加入root结点之前(循环链表中)
     *   a …… root
     *   a …… node …… root
    */
    void addNode(FibNode *node, FibNode *root) {
        node->left = root->left;
        root->left->right = node;
        node->right = root;
        root->left = node;
    }
private:
    /*
     * 将节点node插入到斐波那契堆中
     */
    void insert(FibNode *node) {
        if (keyNum == 0)
            min = node;
        else {
            addNode(node, min);
            if (node->key < min->key)
                min = node;
        }

        keyNum++;
    }
public:
    /*
     * 新建键值为key的节点，并将其插入到斐波那契堆中
     */
    void insert(int key) {
        FibNode *node = new FibNode(key);
        if (node == nullptr)
            return;

        insert(node);
    }
private:
    /*
     * 将双向链表b链接到双向链表a的后面
     */
    void catList(FibNode *a, FibNode *b) {
        FibNode *tmp;

        tmp = a->right;
        a->right = b->right;
        b->right->left = a;
        b->right = tmp;
        tmp->left = b;
    }
public:
    /*
     * 将other合并到当前堆中 不删除other
     */
    void unionHeap(FibHeap *other) {
        if (other == nullptr)
            return;

        if ((this->min) == nullptr) {                // this无"最小节点"
            this->min = other->min;
            this->keyNum = other->keyNum;
            // other = nullptr;
        }
        else if ((other->min) == nullptr) {        // this有"最小节点" && other无"最小节点"
            // other = nullptr;
        }
        else {                                // this有"最小节点" && other有"最小节点"
            // 将"other中根链表"添加到"this"中
            catList(this->min, other->min);

            if (this->min->key > other->min->key)
                this->min = other->min;
            this->keyNum += other->keyNum;
            // other = nullptr;
        }
    }
private:
    /*
     * 将"堆的最小结点"从根链表中移除，
     * 这意味着"将最小节点所属的树"从堆中移除!
     */
    FibNode *extractMin() {
        FibNode *p = min;

        if (p == p->right)
            min = nullptr;
        else {
            removeNode(p);
            min = p->right;
        }
        p->left = p->right = p;

        return p;
    }
    /*
     * 将node链接到root根结点
     */
    void link(FibNode *node, FibNode *root) {
        // 将node从双链表中移除
        removeNode(node);
        // 将node设为root的孩子
        if (root->child == nullptr)
            root->child = node;
        else
            addNode(node, root->child);

        node->parent = root;
        root->degree++;
        node->marked = false;
    }
    /*
     * 合并斐波那契堆的根链表中左右相同度数的树
     */
    void consolidate() {
        // 计算log2(keyNum)，floor意味着向上取整！
        // ex-> log2(13) = 3，向上取整为4。
        int maxDegree = floor(log2(keyNum));
        int D = maxDegree + 1;
        FibNode **cons = new FibNode * [D + 1];

        for (int i = 0; i < D; i++)
            cons[i] = nullptr;

        // 合并相同度的根节点，使每个度数的树唯一
        while (min != nullptr) {
            FibNode *x = extractMin();            // 取出堆中的最小树(最小节点所在的树)
            int d = x->degree;                        // 获取最小树的度数
            // cons[d] != null，意味着有两棵树(x和y)的"度数"相同。
            while (cons[d] != nullptr) {
                FibNode *y = cons[d];                // y是"与x的度数相同的树" 
                if (x->key > y->key) {    // 保证x的键值比y小
                    FibNode *tmp = x;
                    x = y;
                    y = tmp;
                }

                link(y, x);    // 将y链接到x中
                cons[d] = nullptr;
                d++;
            }
            cons[d] = x;
        }
        min = nullptr;

        // 将cons中的结点重新加到根表中
        for (int i = 0; i < D; i++) {

            if (cons[i] != nullptr) {
                if (min == nullptr)
                    min = cons[i];
                else {
                    addNode(cons[i], min);
                    if ((cons[i])->key < min->key)
                        min = cons[i];
                }
            }
        }

        delete[]cons;
    }
public:
    /*
     * 移除最小节点
     */
    void removeMin() {
        if (min == nullptr)
            return;

        FibNode *m = min;
        // 将min每一个儿子(儿子和儿子的兄弟)都添加到"斐波那契堆的根链表"中
        while (m->child != nullptr) {
            FibNode *child = m->child;

            removeNode(child);
            if (child->right == child)
                m->child = nullptr;
            else
                m->child = child->right;

            addNode(child, min);
            child->parent = nullptr;
        }

        // 将m从根链表中移除
        removeNode(m);
        // 若m是堆中唯一节点，则设置堆的最小节点为null；
        // 否则，设置堆的最小节点为一个非空节点(m->right)，然后再进行调节。
        if (m->right == m)
            min = nullptr;
        else {
            min = m->right;
            consolidate();
        }
        keyNum--;

        m = nullptr;
    }
public:
    /*
     * 获取斐波那契堆中最小键值；失败返回-1
     */
    int minimum() {
        if (min == nullptr) {
            cerr << "no element in FibHeap!\n"; return -1;
        }

        return min->key;
    }
private:
    /*
     * 修改度数
     */
    void renewDegree(FibNode *parent, int degree) {
        parent->degree -= degree;
        if (parent->parent != nullptr)
            renewDegree(parent->parent, degree);
    }
    /*
     * 将node从父节点parent的子链接中剥离出来，
     * 并使node成为"堆的根链表"中的一员。
     */
    void cut(FibNode *node, FibNode *parent) {
        removeNode(node);
        renewDegree(parent, node->degree);
        // node没有兄弟
        if (node == node->right)
            parent->child = nullptr;
        else
            parent->child = node->right;

        node->parent = nullptr;
        node->left = node->right = node;
        node->marked = false;
        // 将"node所在树"添加到"根链表"中
        addNode(node, min);
    }
    /*
     * 对节点node进行"级联剪切"
     *
     * 级联剪切：如果减小后的结点破坏了最小堆性质，
     *     则把它切下来(即从所在双向链表中删除，并将
     *     其插入到由最小树根节点形成的双向链表中)，
     *     然后再从"被切节点的父节点"到所在树根节点递归执行级联剪枝
     */
    void cascadingCut(FibNode *node) {
        FibNode *parent = node->parent;

        if (parent != nullptr) {
            if (node->marked == false)
                node->marked = true;
            else {
                cut(node, parent);
                cascadingCut(parent);
            }
        }
    }
    /*
     * 将斐波那契堆中节点node的值减少为key
     */
    void decrease(FibNode *node, int key) {
        if (min == nullptr || node == nullptr)
            return;

        if (key > node->key) {
            cerr << "decrease failed: the new key" << key << " is no smaller than current key" << node->key << endl;
            return;
        }

        FibNode *parent = node->parent;
        node->key = key;
        if (parent != nullptr && (node->key < parent->key)) {
            // 将node从父节点parent中剥离出来，并将node添加到根链表中
            cut(node, parent);
            cascadingCut(parent);
        }

        // 更新最小节点
        if (node->key < min->key)
            min = node;
    }
    /*
     * 将斐波那契堆中节点node的值增加为key
     */
    void increase(FibNode *node, int key) {
        if (min == nullptr || node == nullptr)
            return;

        if (key <= node->key) {
            cerr << "increase failed: the new key " << key << " is no greater than current key " << node->key << endl;
            return;
        }

        // 将node每一个儿子(不包括孙子,重孙,->)都添加到"斐波那契堆的根链表"中
        while (node->child != nullptr) {
            FibNode *child = node->child;
            removeNode(child);               // 将child从node的子链表中删除
            if (child->right == child)
                node->child = nullptr;
            else
                node->child = child->right;

            addNode(child, min);       // 将child添加到根链表中
            child->parent = nullptr;
        }
        node->degree = 0;
        node->key = key;

        // 如果node不在根链表中，
        //     则将node从父节点parent的子链接中剥离出来，
        //     并使node成为"堆的根链表"中的一员，
        //     然后进行"级联剪切"
        // 否则，则判断是否需要更新堆的最小节点
        FibNode *parent = node->parent;
        if (parent != nullptr) {
            cut(node, parent);
            cascadingCut(parent);
        }
        else if (min == node) {
            FibNode *right = node->right;
            while (right != node) {
                if (node->key > right->key)
                    min = right;
                right = right->right;
            }
        }
    }
    /*
     * 更新斐波那契堆的节点node的键值为key
     */
    void update(FibNode *node, int key) {
        if (key < node->key)
            decrease(node, key);
        else if (key > node->key)
            increase(node, key);
        else
            clog << "No need to update!!!\n";
    }
public:
    void update(int oldkey, int newkey) {
        FibNode *node;

        node = search(oldkey);
        if (node != nullptr)
            update(node, newkey);
    }
private:
    /*
     * 在最小堆root中查找键值为key的节点
     */
    FibNode *search(FibNode *root, int key) {
        FibNode *t = root;    // 临时节点
        FibNode *p = nullptr;    // 要查找的节点

        if (root == nullptr)
            return root;

        do {
            if (t->key == key) {
                p = t;
                break;
            }
            else {
                if ((p = search(t->child, key)) != nullptr)
                    break;
            }
            t = t->right;
        } while (t != root);

        return p;
    }
    /*
     * 在斐波那契堆中查找键值为key的节点
     */
    FibNode *search(int key) {
        if (min == nullptr)
            return nullptr;

        return search(min, key);
    }
public:
    /*
     * 在斐波那契堆中是否存在键值为key的节点。
     * 存在返回true，否则返回false。
     */
    bool contains(int key) {
        return search(key) != nullptr ? true : false;
    }
private:
    void remove(FibNode *node);
public:
    void remove(int key);
private:
    void destroyHelper(FibNode *node);
public:
    void destroy();
private:
    void printHelper(FibNode *node, FibNode *prev, int direction);
public:
    void print();
};


/*
 * 删除结点node
 */
void FibHeap::remove(FibNode *node) {
    int m = min->key;
    decrease(node, m - 1);
    removeMin();
}
/*
 * 删除一个值
 */
void FibHeap::remove(int key) {
    if (min == nullptr)
        return;

    FibNode *node = search(key);
    if (node == nullptr)
        return;

    remove(node);
}

/*
 * 销毁斐波那契堆
 */
void FibHeap::destroy() {
    destroyHelper(min);
    min = nullptr;
}

/*
 * 销毁斐波那契堆
 */
void FibHeap::destroyHelper(FibNode *node) {
    if (node == nullptr)
        return;

    FibNode *start = node;
    do {
        destroyHelper(node->child);
        FibNode *todelete = node;
        // 销毁node，并将node指向下一个
        node = node->right;
        node->left = nullptr;
        delete todelete;
    } while (node != start);
}

/*
 * 打印"斐波那契堆"
 *
 * 参数说明：
 *     node       -- 当前节点
 *     prev       -- 当前节点的前一个节点(父节点or兄弟节点)
 *     direction  --  1，表示当前节点是一个左孩子;
 *                    2，表示当前节点是一个兄弟节点。
 */
void FibHeap::printHelper(FibNode *node, FibNode *prev, int direction) {
    FibNode *start = node;

    if (node == nullptr)
        return;
    do {
        if (direction == 1)
            clog << node->key << "(" << node->degree << ") is " << prev->key << "'s child\n";
        else
            clog << node->key << "(" << node->degree << ") is " << prev->key << "'s next\n";

        if (node->child != nullptr)
            printHelper(node->child, node, 1);

        // 兄弟节点
        prev = node;
        node = node->right;
        direction = 2;
    } while (node != start);
}

void FibHeap::print() {
    if (min == nullptr) {
        cerr << "no element in Heap!!\n";
        return;
    }

    int i = 0;
    FibNode *p = min;
    clog << "== 斐波那契堆的详细信息: ==\n";
    do {
        i++;
        clog << i << "-> " << p->key << "(" << p->degree << ") is root\n";

        printHelper(p->child, p, 1);
        p = p->right;
    } while (p != min);
    clog << endl;
}
