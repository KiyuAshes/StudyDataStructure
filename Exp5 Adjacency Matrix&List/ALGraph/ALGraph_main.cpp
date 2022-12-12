#include <iostream>

#include "ALGraph.hpp"

int main() {
    char ch[] = {'A', 'B', 'C', 'D', 'E'};
    ALGraph<char> ALG(ch, 5, 6);
    ALG.VisitedClear();

    std::cout<<"深度优先的遍历顺序是:";
    ALG.DFSTraverse(0);
    std::cout<<std::endl;

    ALG.VisitedClear();
    std::cout<<"广度优先的遍历顺序是:";
    ALG.BFSTraverse(0);
    std::cout<<std::endl;

    return 0;
}