#ifndef LinkQueue_HPP
#define LinkQueue_HPP
template <class DataType>
class Node {
   public:
    DataType data;
    Node<DataType> *next;
    Node(DataType data_ = 0, Node<DataType> *next_ = nullptr)
        : next(next_), data(data_){};
};

template <class DataType>
class LinkQueue {
   public:
    LinkQueue();
    ~LinkQueue();
    void EnQueue(DataType x);
    DataType DeQueue();
    DataType GetQueue();
    bool Empty();

   private:
    Node<DataType> *front, *rear;
};

template <class DataType>
LinkQueue<DataType>::LinkQueue() {
    front = new Node<DataType>;
    rear = front;
}

template <class DataType>
LinkQueue<DataType>::~LinkQueue() {
    Node<DataType> *p = nullptr;
    while (front != nullptr) {
        p = front->next;
        delete front;
        front = p;
    }
}

template <class DataType>
void LinkQueue<DataType>::EnQueue(DataType x) {
    rear->next = new Node<DataType>(x);
    rear = rear->next;
}

template <class DataType>
DataType LinkQueue<DataType>::DeQueue() {
    DataType front_data;
    Node<DataType> *p = nullptr;
    if (rear == front) throw "下溢";
    p = front->next;
    // 头结点是个空节点，第二个才是队首
    front_data = p->data;
    front->next = p->next;
    delete p;
    return front_data;
}

template <class DataType>
DataType LinkQueue<DataType>::GetQueue() {
    if (front != rear)
        return front->next->data;
    else
        return 0;
}

template <class DataType>
bool LinkQueue<DataType>::Empty() {
    if (front == rear)
        return true;
    else
        return false;
}
#endif
