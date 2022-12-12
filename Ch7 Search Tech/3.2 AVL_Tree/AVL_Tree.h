#ifndef AVL_Tree_H
#define AVL_Tree_H
#include <iostream>
template <class DataType>
struct Node {
    DataType data;                                    // 数据
    Node<DataType>*left = nullptr, *right = nullptr;  // 左右子节点
    int depth;                                        // 子树深度
};

template <class DataType>
Node<DataType>* AVL_Find(Node<DataType>* root, DataType data);

template <class DataType>
Node<DataType>* AVL_Insert(Node<DataType>* root, DataType data);

// template <class DataType>
// void Delete(Node<DataType>* root, DataType data);

template <class DataType>
Node<DataType>* LL_Rotate(Node<DataType>* root);

template <class DataType>
Node<DataType>* RR_Rotate(Node<DataType>* root);

template <class DataType>
Node<DataType>* LR_Rotate(Node<DataType>* root);

template <class DataType>
Node<DataType>* RL_Rotate(Node<DataType>* root);

template <class DataType>
std::ostream& operator<<(std::ostream& out, Node<DataType>* root);

template <class DataType>
int getDepth(Node<DataType>* node);

#endif