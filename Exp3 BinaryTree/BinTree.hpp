// #ifndef BINTREE_HPP
// #define BINTREE_HPP
// #include <queue>
// #include <stack>
// #include <iostream>
// template <class DataType>
// struct BinNode
// {
//     DataType data = 0;
//     BinNode<DataType> *left = nullptr, *right = nullptr;
// };

// template <class DataType>
// class BinTree
// {
// public:
//     BinTree();          // 构造函数，创建一棵二叉树
//     ~BinTree();         // 析构函数，释放各结点的存储空间
//     void PreOrder();    // 前序遍历二叉树
//     void InOrder();     // 中序遍历二叉树
//     void PostOrder();   // 后续遍历二叉树
//     void LevelOrder();  // 层序遍历二叉树
//     void ClearStack();  // 清理遍历栈
// private:
//     BinNode<DataType> *root = nullptr;
// };

// template <class DataType>
// BinTree<DataType>::BinTree()
// {
//     std::stack<BinNode<DataType> **> stack;
//     BinNode<DataType> **p = nullptr;
//     DataType data;

//     stack.push(root);

//     while (!stack.empty())
//     {
//         std::cin
//         p = stack.top();
//         stack.pop();

//         *p = new BinNode<DataType>;
//         (*p).data = data;
//     }
// }

// // template <class DataType>
// // void BinTree<DataType>::ClearStack()
// // {
// //     // 将栈中内容全部出栈。
// //     while (!tree_stack.empty())
// //     {
// //         tree_stack.pop();
// //     }
// // }

// #endif