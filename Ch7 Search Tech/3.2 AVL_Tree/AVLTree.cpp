/*
 * @Author: Askr_Yggdrasills
 * @Date: 2021-12-20 14:24:16
 * @LastEditTime: 2022-11-14 18:43:31
 * @LastEditors: Askr_Yggdrasills
 * @Description:
 * @FilePath: \003.DataStructure_Study\AVLTree\AVLTree.cpp
 * Copyright © 2021 Askr_Yggdrasills, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
using namespace std;

//定义节点结构体
template <typename Data>
struct Node {
    int height = 0;
    Data data = 0;
    Node *left = NULL, *right = NULL;
};

//查找节点的方法
Node<int> *TreeSearch(int needFind, Node<int> *root) {
    Node<int> *ans = root;
    while (ans == NULL || ans->data == needFind) {
        if (root->data < needFind)
            ans = root->left;
        else
            ans = root->right;
    }
    return ans;
}

//插入节点的方法
// void TreeInsert(int needInsert, Node<int> *root) {
//     if (!(TreeSearch(needInsert, root))) return;
//     while (ans == NULL || ans->data == needFind) {
//         if (root->data < needFind)
//             ans = root->left;
//         else
//             ans = root->right;
//     }
// }

//四种子树旋转方法
void RR() {}
void LL() {}
void RL() {}
void LR() {}

int main() {
    Node<int> *root = new Node<int>;
    int n;
    cin >> n;
    cin >> root->data;
    for (int i = 0; i < n - 1; i++) {
    }
    return 0;
}
