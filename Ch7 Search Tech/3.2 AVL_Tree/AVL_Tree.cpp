#include "AVL_Tree.h"

template <class DataType>
int getDepth(Node<DataType>* node) {
    return node == nullptr ? 0 : node->depth;
}

template <class DataType>
Node<DataType>* AVL_Find(Node<DataType>* root, DataType data) {
    // 搜索到目标
    if (root->data == data) return root;

    // 左子树搜索
    if (data < root->data && root->left != nullptr) {
        return Find(root->left, data);
    }

    if (data > root->data && root->right != nullptr) {
        return Find(root->left, data);
    }

    // 叶子节点
    return nullptr;
}

template <class DataType>
Node<DataType>* AVL_Insert(Node<DataType>* root, DataType data) {
    if (root == nullptr) {
        root = new Node<DataType>;
        root->depth = 1;
        root->data = data;
        return root;
    }

    if (data == root->data) {
        return root;
    }

    if (data < root->data) {
        // 插入左子树
        root->left = AVL_Insert(root->left, data);
        if (getDepth(root->left) - getDepth(root->right) > 1) {
            if (data < root->left->data) {
                // LL型插入
                root = LL_Rotate(root);
            } else {
                // LR型插入
                root = LR_Rotate(root);
            }
        }
    } else {
        // 插入右子树
        root->right = AVL_Insert(root->right, data);
        if (getDepth(root->left) - getDepth(root->right) < -1) {
            if (data > root->right->data) {
                // RR型插入
                root = RR_Rotate(root);
            } else {
                // RL型插入
                root = RL_Rotate(root);
            }
        }
    }

    root->depth = std::max(getDepth(root->left), getDepth(root->right)) + 1;
    return root;
}

template <class DataType>
Node<DataType>* LL_Rotate(Node<DataType>* root) {
    Node<DataType>* leftSubTree = root->left;
    root->left = leftSubTree->right;
    leftSubTree->right = root;
    // 调整原root节点的高度
    root->depth = std::max(getDepth(root->left), getDepth(root->right)) + 1;
    // 新根高度在插入函数中修正
    root = leftSubTree;
    return root;
}

template <class DataType>
Node<DataType>* RR_Rotate(Node<DataType>* root) {
    Node<DataType>* rightSubTree = root->right;
    root->right = rightSubTree->left;
    rightSubTree->left = root;
    // 调整原root节点的高度
    root->depth = std::max(getDepth(root->left), getDepth(root->right)) + 1;
    // 新根高度在插入函数中修正
    root = rightSubTree;
    return root;
}

template <class DataType>
Node<DataType>* LR_Rotate(Node<DataType>* root) {
    // 对左子树做RR旋转
    root->left = RR_Rotate(root->left);
    // 修正左子树高度
    root->left->depth = root->depth =
        std::max(getDepth(root->left->left), getDepth(root->left->right)) + 1;
    // 对root做LL旋转
    root = LL_Rotate(root);
    return root;
}

template <class DataType>
Node<DataType>* RL_Rotate(Node<DataType>* root) {
    // 对右子树做LL旋转
    root->right = LL_Rotate(root->left);
    // 修正右子树高度
    root->right->depth =
        std::max(getDepth(root->right->left), getDepth(root->right->right)) + 1;
    // 对root做RR旋转
    root = RR_Rotate(root);
    return root;
}

template <class DataType>
std::ostream& operator<<(std::ostream& out, Node<DataType>* root) {
    std::cout << root->data << std::endl;
    if (root->left != nullptr) {
        std::cout << root->data << "-left:" << root->left << std::endl;
    }
    if (root->right != nullptr) {
        std::cout << root->data << "-right:" << root->right << std::endl;
    }
    return out;
}
