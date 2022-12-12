#include <iostream>

#include "MGraph.hpp"

int main() {
    char ch[] = {'A', 'B', 'C', 'D', 'E'};
    MGraph<char> MG(ch, 5, 6);
    MG.VisitedClear();

    std::cout<<"深度优先的遍历顺序是:";
    MG.DFSTraverse(0);
    std::cout<<std::endl;

    MG.VisitedClear();
    std::cout<<"广度优先的遍历顺序是:";
    MG.BFSTraverse(0);
    std::cout<<std::endl;

    return 0;
}