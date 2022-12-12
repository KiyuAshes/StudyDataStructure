#include <iostream>

#include "LinkQueue.hpp"

int main() {
    LinkQueue<int> Q;
    if (Q.Empty())
        std::cout << "队列为空" << std::endl;
    else
        std::cout << "队列非空" << std::endl;
    std::cout << std::endl;

    std::cout << "元素10和元素15执行入队操作:" << std::endl;
    try {
        Q.EnQueue(10);
        Q.EnQueue(15);
    } catch (char* e_msg) {
        std::cout << e_msg << std::endl;
    }
    std::cout << "查看队头元素:" << std::endl;
    std::cout << Q.GetQueue() << std::endl;
    std::cout << std::endl;
    
    std::cout << "执行出队操作:" << std::endl;
    try {
        Q.DeQueue();
    } catch (char* e_msg) {
        std::cout << e_msg << std::endl;
    }
    std::cout << "查看队头元素:" << std::endl;
    std::cout << Q.GetQueue() << std::endl;
    std::cout << std::endl;

    return 0;
}