#include<iostream>
#include<string.h>
using namespace std;

struct Node {
    Node *l, *r;
    int mature; // 记录值
    int pos; // 记录idx
    int pos_fa;// 记录 father 的idx
    Node(int pos_ = -1, int pos_fa_ = -1, int mature_ = -1, Node *l_ = nullptr, Node *r_ = nullptr)
        :pos(pos_), pos_fa(pos_fa_), mature(mature_), l(l_), r(r_) {
    }
    void addson(Node *son) {
        if (l) { if (r) return; else r = son; return; }
        l = son;
    }
};


struct answer {
    int value;
    int begin, end;
    int lens_a;
    answer(int b_ = 0, int e_ = 0, int len_ = 0, int v_ = 0)
        :begin(b_), end(e_), value(v_), lens_a(len_) {
        ;
    }
};

struct leaf {
    int value;
    int pos_apple;
    leaf(int v_ = 0, int p_ = 0) {
        value = v_;
        pos_apple = p_;
    }
};

answer f[60000];
Node apple[60000];
int n;

answer dfs(int pos) {
    answer temp;
    Node &curr_node = apple[pos];
    temp.value = curr_node.mature;
    if (!curr_node.l && !curr_node.r) {
        //若 左右均为空->叶子节点
        temp.begin = temp.end = pos;
        temp.lens_a = 1;
        temp.value = apple[pos].mature;
        return temp;
    }
    int son = 0;
    answer ans_l, ans_r;
    Node *&sonl = curr_node.l;
    Node *&sonr = curr_node.r;
    ans_l = dfs(curr_node.l->pos);
    ans_r = dfs(curr_node.r->pos);
    if (curr_node.l && curr_node.r) {
        int value0 = ans_l.value, value1 = ans_r.value;
        bool flag0 = (value0 > 0), flag1 = (value1 > 0);

        if (flag0 == true && flag1 == true) {
            if (ans_l.value > ans_r.value) { son = 0; }
            else if (value0 < value1) { son = 1; }
            else {
                if (ans_l.lens_a > ans_r.lens_a) {
                    son = 1;
                }
                else if (ans_l.lens_a < ans_r.lens_a) {
                    son = 0;
                }
                else if (ans_l.begin > ans_r.begin) { son = 1; }
                else { son = 0; }
            }
        }
    }
    else {
        if (ans_l.value <= 0) {
            temp.begin = temp.end = pos;
            temp.lens_a = 1;
            temp.value = apple[pos].mature;
            return temp;
        }
    }
    if (son == 0) {
        temp.lens_a = ans_l.lens_a + 1;
        temp.begin = ans_l.begin;
        temp.end = pos;
        temp.value += ans_l.value;
    }
    else {
        temp.lens_a = ans_r.lens_a + 1;
        temp.begin = ans_r.begin;
        temp.end = pos;
        temp.value += ans_r.value;
    }
    return temp;
}

int find_path(int *path, int pos) {
    int m = 0;
    path[m] = pos;
    while (pos != 0) {
        pos = apple[pos].pos_fa;
        m++;
        path[m] = pos;
    }
    return m + 1;
}
void reversed(int *arr, int len) {
    int *new_arr = new int[len];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[len - 1 - i];
    }
    for (int i = 0; i < len; i++) {
        arr[i] = new_arr[i];
    }
    delete[]new_arr;
    return;
}

int main() {
    cin >> n;
    leaf *arr = new leaf[n];
    int *queue = new int[n];
    int count = -1, rear = 0, front = 0, i = 0;
    cin >> arr[0].value;
    count++;
    arr[i].pos_apple = count;
    apple[count].mature = arr[i].value;
    apple[count].pos = count;
    i++;
    queue[(rear++)] = count;//把根节点入队
    while (i < n) {
        cin >> arr[i].value;
        int fa = queue[(front++)];
        if (arr[i].value != 0) {
            count++;
            arr[i].pos_apple = count;
            apple[count].mature = arr[i].value;
            apple[count].pos = count;
            apple[fa].addson(&(apple[count]));
            apple[count].pos_fa = fa;
            queue[(rear++)] = count;
        }
        i++;
        if (i >= n) break;
        cin >> arr[i].value;
        if (arr[i].value != 0) {
            count++;
            arr[i].pos_apple = count;
            apple[count].mature = arr[i].value;
            apple[count].pos = count;
            apple[fa].addson(&(apple[count]));
            apple[count].pos_fa = fa;
            queue[(rear++)] = count;
        }
        i++;
    }

    answer temp[2];
    for (int pos = 0; pos <= count; pos++) {
        f[pos].value = apple[pos].mature;
        Node &curr_node = apple[pos];
        for (int j = 0; j < 2; j++) {
            temp[j] = j ? dfs((apple[pos].r)->pos) : dfs((apple[pos].l)->pos);
            f[pos].value += (temp[j].value > 0 ? temp[j].value : 0);
        }
        if (!curr_node.l && !curr_node.r) {
            f[pos].lens_a = 1;
            f[pos].begin = f[pos].end = pos;
            continue;
        }
        else if (curr_node.l && curr_node.r) {

            int value0 = temp[0].value, value1 = temp[1].value;
            int len0 = temp[0].lens_a, len1 = temp[1].lens_a;
            bool flag0 = (value0 > 0), flag1 = (value1 > 0);
            if (flag0 == true && flag1 == true) {
                int pre = (temp[0].begin > temp[1].begin ? 1 : 0);
                if (pre == 0) {//先存第一段再存第二段
                    f[pos].lens_a = len0 + len1 + 1;
                    f[pos].begin = temp[0].begin;
                    f[pos].end = temp[1].begin;
                }
                else {
                    f[pos].lens_a = len0 + len1 + 1;
                    f[pos].begin = temp[1].begin;
                    f[pos].end = temp[0].begin;
                }
            }
            else if (flag0 == false && flag1 == true) {
                f[pos].lens_a = temp[1].lens_a + 1;
                f[pos].begin = pos;
                f[pos].end = temp[1].begin;
            }
            else if (flag0 == true && flag1 == false) {
                f[pos].lens_a = temp[0].lens_a + 1;
                f[pos].begin = pos;
                f[pos].end = temp[0].begin;
            }
            else {
                f[pos].lens_a = 1;
                f[pos].begin = f[pos].end = pos;
            }

        }
        else {//只有一个孩子
            if (temp[0].value > 0) {
                f[pos].lens_a = temp[0].lens_a + 1;
                f[pos].begin = pos;
                f[pos].end = temp[0].begin;
            }
            else {
                f[pos].lens_a = 1;
                f[pos].begin = f[pos].end = pos;
            }
        }
    }

    int maxal = f[0].value;
    int lens = f[0].lens_a;
    int begin = f[0].begin;
    int end = f[0].end;
    for (int i = 0; i <= count; i++) {
        if (f[i].value > maxal) {
            maxal = f[i].value;
            lens = f[i].lens_a;
            begin = f[i].begin;
            end = f[i].end;
        }
        else if (f[i].value == maxal) {
            if (lens > f[i].lens_a) {
                maxal = f[i].value;
                lens = f[i].lens_a;
                begin = f[i].begin;
                end = f[i].end;
            }
            else if (lens == f[i].lens_a) {
                if (begin > f[i].begin) {
                    maxal = f[i].value;
                    lens = f[i].lens_a;
                    begin = f[i].begin;
                    end = f[i].end;
                }
            }
        }
    }

    int *ans = new int[n];
    if (lens == 1) {
        cout << begin;
        return 0;
    }

    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int len1 = find_path(arr1, begin);
    int len2 = find_path(arr2, end);
    reversed(arr1, len1);
    reversed(arr2, len2);

    int common = 0;
    for (int i = 1; i < min(len1, len2); i++) {
        if (arr1[i] == arr2[i]) common = i;
    }

    for (int i = len1 - 1; i >= common; i--) {
        cout << arr1[i] << " ";
    }
    for (int i = common + 1; i < len2; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}




//9
//7 0 1 1 3 2 0 0 0
