#ifndef MGraph_HPP
#define MGraph_HPP

#include <iostream>
#include <queue>

const int MaxSize = 10;

template <class DataType>
class MGraph {
   public:
    MGraph(DataType data_[], int n, int e);
    ~MGraph(){};
    void DFSTraverse(int v);  // 深度有限遍历
    void BFSTraverse(int v);  // 广度有限遍历
    void VisitedClear();

   private:
    DataType vertex[MaxSize];
    bool visited[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum, arcNum;
};

template <class DataType>
MGraph<DataType>::MGraph(DataType data_[], int n, int e) {
    vertexNum = n;
    arcNum = e;
    int x, y;

    // 存储图的顶点信息
    for (int i = 0; i < vertexNum; i++) vertex[i] = data_[i];

    for (int i = 0; i < vertexNum; i++)
        for (int j = 0; j < vertexNum; j++) {
            arc[i][j] = 0;
        }

    for (int i = 0; i < arcNum; i++) {
        std::cout << "请输入两个顶点的序号:";
        std::cin >> x >> y;
        arc[x][y] = 1;
        arc[y][x] = 1;
    }
}

template <class DataType>
void MGraph<DataType>::DFSTraverse(int v) {
    std::cout << vertex[v] << " ";
    visited[v] = true;
    for (int j = 0; j < vertexNum; j++) {
        if (arc[v][j] == 1 && visited[j] == false) DFSTraverse(j);
    }
}

template <class DataType>
void MGraph<DataType>::BFSTraverse(int v) {
    std::queue<int> Q;
    std::cout << vertex[v] << " ";
    visited[v] = true;
    Q.push(v);

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (int j = 0; j < vertexNum; j++)
            if (arc[v][j] == 1 && visited[j] == false) {
                std::cout << vertex[j] << " ";
                visited[j] = true;
                Q.push(j);
            }
    }
}

template <class DataType>
void MGraph<DataType>::VisitedClear() {
    for (int i = 0; i < MaxSize; i++) {
        visited[i] = false;
    }
}
#endif