#include<iostream>
#include<queue>
#include<vector>

using namespace std;
/**
 *这是一份 他人正确的代码
 *
*/
struct TreeNode {
    int val;//值
    int seq;//顺序
    int left_tree_max_sum;//左子树最大路径和
    int right_tree_max_sum;//右子树最大路径和
    int total_tree_max_sum;//以该节点为根的树的最大路径和
    int path_left_len;//最大路径落在左子树的长度
    int path_right_len;//最大路径落在右子树的长度
    int path_total_len;//最大路径长度
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(TreeNode &treenode) :val(treenode.val), seq(treenode.seq), left(treenode.left), right(treenode.right), parent(treenode.parent) {
        left_tree_max_sum = treenode.left_tree_max_sum;
        right_tree_max_sum = treenode.right_tree_max_sum;
        total_tree_max_sum = treenode.total_tree_max_sum;
        path_left_len = treenode.path_left_len;
        path_right_len = treenode.path_right_len;
        path_total_len = treenode.path_total_len;
    }
};

int cnt = 0;//用于生成节点编号
int max_length = INT_MIN;
int max_single = INT_MIN;
vector<vector<int>> res;//求和等于最大值的 有用的路径(但还没有最短)

TreeNode *buildTree(int value[], int sz) {//将层序遍历还原成二叉树
    if (sz == 0) return nullptr;
    TreeNode *root = new TreeNode(value[0]);
    root->seq = cnt++;
    queue<TreeNode *> queue;
    queue.emplace(root);

    for (int i = 1; i < sz; i++) {
        TreeNode *front = queue.front();
        queue.pop();
        if (value[i] != 0) {
            TreeNode *left = new TreeNode(value[i]);
            left->parent = front;
            left->seq = cnt++;
            front->left = left;
            queue.emplace(left);
        }
        if (value[++i] != 0) {
            TreeNode *right = new TreeNode(value[i]);
            right->parent = front;
            right->seq = cnt++;
            front->right = right;
            queue.emplace(right);
        }
    }
    return root;
}

int max_sum_of_tree(TreeNode *root, int &max_length) {//寻找最大路径和，并且更新每个节点的求和信息
    if (root == nullptr) return 0;
    root->left_tree_max_sum = max_sum_of_tree(root->left, max_length);
    root->right_tree_max_sum = max_sum_of_tree(root->right, max_length);
    root->total_tree_max_sum = max(root->left_tree_max_sum + root->right_tree_max_sum + root->val, 0);
    max_length = max_length < root->total_tree_max_sum ? root->total_tree_max_sum : max_length;
    return max(0, max(root->left_tree_max_sum, root->right_tree_max_sum) + root->val);
}

int generate_len(TreeNode *root) {//更新每个节点的最长路径长以及该路径落在左边和右边的长
    if (root == nullptr) return 0;
    root->path_left_len = generate_len(root->left);
    root->path_right_len = generate_len(root->right);
    root->path_total_len = root->path_left_len + root->path_right_len + 1;
    // if (root->total_tree_max_sum == max_length) seperate_path(root);//递归还没完成，此时就提取路径会有问题
    if (root->left_tree_max_sum + root->val <= 0 && root->right_tree_max_sum + root->val <= 0) return 0;

    if (root->left_tree_max_sum > root->right_tree_max_sum) return root->path_left_len + 1;
    else if (root->left_tree_max_sum < root->right_tree_max_sum) return root->path_right_len + 1;
    else return min(root->path_left_len, root->path_right_len) + 1;//"V"形结构不能递归，只能如此return
}

void seperate_path(TreeNode *root, vector<int> &path, int seq) {//寻找路径和等于最大值的部分有用的路径
    if (root == nullptr) return;
    //策略:默认从左到中间再到右边,后面输出的时候需要的话再调换
    if (root->path_left_len != 0 && root->path_right_len != 0 && root->seq == seq)//头节点:左边递归输出，输出root，右边顺序输出
    {
        seperate_path(root->left, path, seq);//左边
        path.push_back(root->seq);//root
        if (root->path_right_len != 0)//右边
        {
            TreeNode *head(root);
            head = head->right;
            path.push_back(head->seq);
            while (head->path_right_len != 0 || head->path_left_len != 0)//能走下去
            {
                if (head->path_left_len != 0 && head->path_right_len != 0)//有分叉
                {
                    //优先选择值大的
                    if (head->left_tree_max_sum > head->right_tree_max_sum) {
                        head = head->left;
                        path.push_back(head->seq);
                    }
                    else if (head->left_tree_max_sum < head->right_tree_max_sum) {
                        head = head->right;
                        path.push_back(head->seq);
                    }
                    //值相等选择路径短的
                    else {
                        if (head->path_left_len <= head->path_right_len) {
                            head = head->left;
                            path.push_back(head->seq);
                        }
                        else {
                            head = head->right;
                            path.push_back(head->seq);
                        }
                    }
                }
                //无分叉
                else {
                    if (head->path_left_len != 0) {
                        head = head->left;
                        path.push_back(head->seq);
                    }
                    else if (head->path_right_len != 0) {
                        head = head->right;
                        path.push_back(head->seq);
                    }
                }
            }
        }
    }
    else//非根节点，递归下去即可,同理
    {
        if (root->path_left_len != 0 && root->path_right_len != 0) {
            if (root->left_tree_max_sum > root->right_tree_max_sum) {
                seperate_path(root->left, path, seq);
            }
            else if (root->left_tree_max_sum < root->right_tree_max_sum) {
                seperate_path(root->right, path, seq);
            }
            else {
                if (root->path_left_len <= root->path_right_len) {
                    seperate_path(root->left, path, seq);
                }
                else {
                    seperate_path(root->right, path, seq);
                }
            }
        }
        else {
            if (root->path_left_len != 0) seperate_path(root->left, path, seq);
            else if (root->path_right_len != 0) seperate_path(root->right, path, seq);
        }
        path.push_back(root->seq);
    }
}

void preorder(TreeNode *root) {//前序遍历每个根节点的最大路径,寻找可能的答案
    if (root == nullptr) return;
    if (root->total_tree_max_sum == max_length)//找到一条求和符合要求的
    {
        vector<int>path;
        seperate_path(root, path, root->seq);
        res.push_back(path);
    }
    preorder(root->left);
    preorder(root->right);
}

void preorder_all_minus_case(TreeNode *root) {//处理节点数值全是负数的特殊情况
    if (root == nullptr) return;
    if (root->val == max_single) {
        cout << root->seq;
    }
    preorder_all_minus_case(root->left);
    preorder_all_minus_case(root->right);
}

int main(void) {
    int n;
    cin >> n;
    int v[60005] = { 0 };
    bool has_positive = false;//是否有正数
    for (int i = 0;i < n;i++) {
        cin >> v[i];
        if (v[i] >= 0) has_positive = true;
    }

    TreeNode *head = buildTree(v, n + 1);//多一位防止树构建出问题

    if (!has_positive)//没正数的特殊情况
    {
        if (has_positive == false) {
            max_single = v[0];
            for (int i = 0;i < n;i++) {
                max_single = max_single < v[i] ? v[i] : max_single;
            }
        }
        preorder_all_minus_case(head);
        return 0;
    }

    max_sum_of_tree(head, max_length);//求路径和
    generate_len(head);//生成路径长度数值和分布信息
    preorder(head);//前序遍历寻找路径

    //寻找符合要求的最短的路径,必要时反向打印
    int min = res[0].size();
    int minloc = 0;

    for (int i = 0;i < res.size();i++) {
        if (min > res[i].size()) {
            min = res[i].size();
            minloc = i;
        }
    }
    if (res[minloc][0] < res[minloc][res[minloc].size() - 1]) {
        for (int i = 0;i < res[minloc].size();i++) {
            cout << res[minloc][i] << " ";
        }
    }
    else {
        for (int i = res[minloc].size() - 1;i >= 0;i--) {
            cout << res[minloc][i] << " ";
        }
    }
    return 0;
}