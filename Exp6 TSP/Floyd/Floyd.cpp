#include <climits>
#include <cstring>
#include <iomanip>
#include <iostream>
const int MaxSize = 20;

// 村庄(顶点)类
struct Vertex {
    std::string name;
    int id;
};

class Graph {
   public:
    Graph();
    void GPrint();
    void DisPrint();
    void DegPrint();
    void Floyd();
    void getDegree();
    int degree[MaxSize];
    int v, e;
    Vertex vexs[MaxSize];

   private:
    int dist[MaxSize][MaxSize];
    int AdjMatrix[MaxSize][MaxSize];
};

Graph::Graph() {
    std::cout << "请输入该图的顶点个数和边的个数：" << std::endl;
    std::cout << "顶点个数：";
    std::cin >> v;
    std::cout << "边的个数：";
    std::cin >> e;

    std::cout << "依次输入各个村庄的名字:" << std::endl;
    for (int i = 0; i < v; i++) {
        std::cout << "村庄" << i << ":";
        std::cin >> vexs[i].name;
    }

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) {
            dist[i][j] = 0;

            if (i == j) {
                AdjMatrix[i][j] = 0;
                continue;
            }
            AdjMatrix[i][j] = INT_MAX;
        }

    int src, des, weight;
    std::cout << "请输入边长和两个端点[输入3个0结束]：" << std::endl;
    while (true) {
        std::cin >> src >> des >> weight;

        if (src == 0 && des == 0 && weight == 0) break;
        AdjMatrix[src][des] = weight;
    }
}

void Graph::Floyd() {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            dist[i][j] = AdjMatrix[i][j];
        }
    }
    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j] &&
                    dist[i][k] + dist[k][j] > 0)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
}
void Graph::getDegree() {
    int max;
    for (int i = 0; i < v; i++) {
        max = dist[0][i];
        for (int j = 0; j < v; j++) {
            if (dist[j][i] > max) max = dist[j][i];
        }
        degree[i] = max;
    }
}

void Graph::GPrint() {
    std::cout << "邻接矩阵：" << std::endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (AdjMatrix[i][j] == INT_MAX) {
                std::cout << "   #";
            } else {
                std::cout << std::setw(4) << AdjMatrix[i][j];
            }
        }
        std::cout << std::endl;
    }
}

void Graph::DisPrint() {
    std::cout << "距离矩阵：" << std::endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            std::cout << std::setw(4) << dist[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Graph::DegPrint() {
    std::cout << "偏心度表：" << std::endl;
    for (int i = 0; i < v; i++) {
        if (degree[i] == INT_MAX) {
            std::cout << "   #";
        } else {
            std::cout << std::setw(4) << degree[i];
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main() {
    Graph G;

    // 输出邻接矩阵
    G.GPrint();

    // 调用Floy算法
    G.Floyd();

    // 输出距离矩阵
    G.DisPrint();

    // 存放偏心度
    G.getDegree();

    // 输出各顶点的偏心度
    G.DegPrint();

    int index;
    // 得到最小村庄的编号和名称
    int min = G.degree[0];
    for (int i = 0; i < G.v; i++) {
        if (min > G.degree[i]) {
            min = G.degree[i];
            index = i;
        }
    }

    std::cout << "偏心度最小的村庄编号：" << index << std::endl;
    std::cout << "医院应该建立在：" << G.vexs[index].name << std::endl;
    return 0;
}