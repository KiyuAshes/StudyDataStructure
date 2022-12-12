#ifndef ALGraph_HPP
#define ALGraph_HPP

#include <iostream>
#include <queue>

const int MaxSize = 10;

class ArcNode {
   public:
    int adjvex;  // 边终点序号
    ArcNode* next;
    ArcNode(int adjvex_, ArcNode* next_ = nullptr)
        : adjvex(adjvex_), next(next_) {}
};

template <class DataType>
class VertexNode {
   public:
    DataType vertex;  // 顶点数据
    ArcNode* firstedge;
    VertexNode(DataType vertex_ = 0, ArcNode* firstedge_ = nullptr)
        : vertex(vertex_), firstedge(firstedge_) {}
};

template <class DataType>
class ALGraph {
   public:
    ALGraph(DataType data_[], int n, int e);
    ~ALGraph();
    void DFSTraverse(int v);  // 深度有限遍历
    void BFSTraverse(int v);  // 广度有限遍历
    void VisitedClear();

   private:
    VertexNode<DataType> adjlist[MaxSize];
    bool visited[MaxSize];
    int vertexNum, arcNum;
};

template <class DataType>
ALGraph<DataType>::ALGraph(DataType data_[], int n, int e) {
    ArcNode* tmp;
    vertexNum = n;
    arcNum = e;
    int x, y;

    for (int i = 0; i < vertexNum; i++) adjlist[i].vertex = data_[i];

    for (int i = 0; i < arcNum; i++) {
        std::cout << "请输入两个顶点的序号:";
        std::cin >> x >> y;
        tmp = new ArcNode(y, adjlist[x].firstedge);
        adjlist[x].firstedge = tmp;
    }
}

template <class DataType>
ALGraph<DataType>::~ALGraph() {
    ArcNode* p;
    for (int i = 0; i < vertexNum; i++) {
        p = adjlist[i].firstedge;
        while (p != nullptr) {
            adjlist[i].firstedge = p->next;
            delete p;
            p = adjlist[i].firstedge;
        }
    }
}

template <class DataType>
void ALGraph<DataType>::DFSTraverse(int v) {
    ArcNode* p = adjlist[v].firstedge;
    int y;

    std::cout << adjlist[v].vertex << " ";
    visited[v] = true;

    while (p != nullptr) {
        y = p->adjvex;
        if (visited[y] == false) DFSTraverse(y);
        p = p->next;
    }
}

template <class DataType>
void ALGraph<DataType>::BFSTraverse(int v) {
    ArcNode* p = adjlist[v].firstedge;
    std::queue<int> Q;

    std::cout << adjlist[v].vertex << " ";
    visited[v] = true;
    Q.push(v);

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        p = adjlist[v].firstedge;
        while (p != nullptr) {
            int j = p->adjvex;
            if (visited[j] == false) {
                std::cout << adjlist[j].vertex << " ";
                visited[j] = true;
                Q.push(j);
            }
            p = p->next;
        }
    }
}

template <class DataType>
void ALGraph<DataType>::VisitedClear() {
    for (int i = 0; i < MaxSize; i++) {
        visited[i] = false;
    }
}
#endif