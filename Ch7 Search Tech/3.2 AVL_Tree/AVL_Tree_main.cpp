#include <cstdio>
#include <iostream>

#include "AVL_Tree.cpp"
int main() {
    Node<int>* root = nullptr;
    root = AVL_Insert<int>(root, 30);
    root = AVL_Insert<int>(root, 20);
    root = AVL_Insert<int>(root, 40);
    root = AVL_Insert<int>(root, 10);
    root = AVL_Insert<int>(root, 25);
    // 插入节点在失衡结点的左子树的左边
    root = AVL_Insert<int>(root, 5);
    // 打印树，按照先打印左子树，再打印右子树的方式
    std::cout << root << std::endl;
    return 0;
}
