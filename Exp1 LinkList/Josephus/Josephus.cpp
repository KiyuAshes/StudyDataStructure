#include <iostream>

// 链表节点
class Node {
   public:
    int data;
    Node* next;
    Node(int data_ = 0, Node* next_ = nullptr) : data(data_), next(next_) {}
};

void PrintList(Node* first) {
    if (first->next == nullptr) {
        std::cout << "空链表!" << std::endl;
        return;
    }

    Node* p = first;

    while (true) {
        p = p->next;
        if (p->next == first->next) break;
        std::cout << p->data << "->";
    }
    std::cout << p->data << std::endl;
}

int main() {
    int n, m, count;  // n总人数,m出圈序号。
    Node *first = new Node(), *p, *pre;

    std::cin >> n >> m;

    // 创建循环链表
    p = first;
    for (int i = 1; i <= n; i++) {
        p->next = new Node(i);
        p = p->next;
    }
    p->next = first->next;

    count = 2;
    pre = first->next;
    p = pre->next;
    while (pre != p) {
        if (count == m) {
            std::cout << "出圈前:";
            PrintList(first);
            std::cout << "出圈者编号:" << p->data << std::endl;
            pre->next = p->next;

            //头结点指向节点被删除的情况
            if (p == first->next) first->next = p->next;

            delete p;
            p = pre->next;
            std::cout << "出圈后:";
            PrintList(first);
            std::cout << std::endl;
            count = 1;
        } else {
            pre = pre->next;
            p = p->next;
            count++;
        }
    }
    std::cout << "存活者:" << p->data << std::endl;
    return 0;
}