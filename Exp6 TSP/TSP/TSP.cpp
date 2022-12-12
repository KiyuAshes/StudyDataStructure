#include <climits>
#include <iostream>
const int MaxSize = 100;

int main() {
    // 邻接矩阵定义
    int v = 0;
    int adj_matrix[MaxSize][MaxSize];
    bool visited[MaxSize];

    // 矩阵初始化
    for (int i = 0; i < MaxSize; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < MaxSize; i++)
        for (int j = 0; j < MaxSize; j++) {
            adj_matrix[i][j] = 0;
        }

    // 默认起点城市为0号城市
    int p = 0;      // 当前城市
    int count = 1;  // 已经走过的城市
    int sum = 0;

    visited[0] = true;
    std::cout << "最短路径:" << std::endl;
    std::cout << "0->";

    v = 5;
    int input[5][5] = {
        {-1, 3, 3, 2, 6}, {3, -1, 7, 3, 2}, {3, 7, -1, 2, 5},
        {2, 3, 2, -1, 3}, {6, 2, 5, 3, -1},
    };

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) {
            adj_matrix[i][j] = input[i][j];
        }

    while (count <= v - 1) {
        int min = INT_MAX, index = 0;
        for (int i = 0; i < v; i++) {
            if (adj_matrix[p][i] != -1 && adj_matrix[p][i] < min &&
                !visited[i]) {
                min = adj_matrix[p][i];
                index = i;
            }
        }

        std::cout << index << "->";
        sum += min;
        visited[index] = true;
        p = index;

        count++;
    }

    sum += adj_matrix[p][0];
    std::cout << "0" << std::endl;
    std::cout << std::endl;
    std::cout << "总路程:" << sum;

    return 0;
}
