#include <iostream>

#include "SinglyLinkList.hpp"
int main() {
    int r[5] = {1, 2, 3, 4, 5};
    SinglyLinkList<int> L(r, 5);

    std::cout << "执行插入操作前的数据为:" << std::endl;
    L.PrintList();
    try {
        L.Insert(2, 3);
    } catch (char *err_info) {
        std::cout << err_info << std::endl;
    }
    std::cout << "执行插入操作后的数据为:" << std::endl;
    L.PrintList();

    std::cout << std::endl;
    std::cout << "值为5的元素的位置:" << L.Locate(5) << std::endl;
    std::cout << std::endl;

    std::cout << "执行删除操作前的数据为:" << std::endl;
    L.PrintList();
    try {
        L.Delete(1);
    } catch (char *err_info) {
        std::cout << err_info << std::endl;
    }
    std::cout << "执行删除操作后的数据为:" << std::endl;
    L.PrintList();
    std::cout << std::endl;

    return 0;
}
