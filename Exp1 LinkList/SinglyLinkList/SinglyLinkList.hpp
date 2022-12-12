#include <iostream>

#ifndef SinglyLinkList_HPP
#define SinglyLinkList_HPP

template <class DataType>
struct Node {
    DataType data;
    Node<DataType> *next;
};

template <class DataType>
class SinglyLinkList {
   public:
    SinglyLinkList();
    SinglyLinkList(DataType init_data[], int data_length);
    ~SinglyLinkList();
    void Insert(int index, DataType x);
    DataType Delete(int index);
    int Locate(DataType x);
    void PrintList();

   private:
    Node<DataType> *first;
};
#endif

template <class DataType>
SinglyLinkList<DataType>::SinglyLinkList() {
    first = new Node<DataType>;
    first->next == nullptr;
}

template <class DataType>
SinglyLinkList<DataType>::SinglyLinkList(DataType init_data[],
                                         int data_length) {
    Node<DataType> *r, *s;
    first = new Node<DataType>;
    r = first;
    for (int i = 0; i < data_length; i++) {
        s = new Node<DataType>;
        s->data = init_data[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}

template <class DataType>
SinglyLinkList<DataType>::~SinglyLinkList() {
    Node<DataType> *q = nullptr;
    while (first != nullptr) {
        q = first;
        first = first->next;
        delete q;
    }
}

template <class DataType>
void SinglyLinkList<DataType>::Insert(int index, DataType x) {
    Node<DataType> *p = first, *tmp;
    int count = 0;
    while (p != nullptr && count < index - 1) {
        p = p->next;
        count++;
    }
    if (p == nullptr) {
        throw "非法位置！";
    } else {
        tmp = new Node<DataType>;
        tmp->data = x;
        tmp->next = p->next;
        p->next = tmp;
    }
}
template <class DataType>
DataType SinglyLinkList<DataType>::Delete(int index) {
    Node<DataType> *p = first, *wait_del;
    DataType deleted_data;
    int count = 0;
    while (p != nullptr && count < index - 1) {
        p = p->next;
        count++;
    }
    if (p == nullptr || p->next == nullptr) {
        throw "非法位置!";
    } else {
        wait_del = p->next;
        deleted_data = wait_del->data;
        p->next = wait_del->next;
        delete wait_del;
        return deleted_data;
    }
}

template <class DataType>
int SinglyLinkList<DataType>::Locate(DataType x) {
    Node<DataType> *p = first->next;
    int count = 1;
    while (p != nullptr) {
        if (p->data == x) return count;
        p = p->next;
        count++;
    }
    return 0;
}

template <class DataType>
void SinglyLinkList<DataType>::PrintList() {
    if (first->next == nullptr) {
        std::cout << "空链表" << std::endl;
        return;
    }
    Node<DataType> *p = first;
    while (true) {
        p = p->next;
        if (p->next == nullptr) break;
        std::cout << p->data << "->";
    }
    std::cout << p->data << std::endl;
}
