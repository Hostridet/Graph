#include <iostream>
#include "src/graph.h"
#include "src/array.h"

int main() {
    int matrix[4][4] = {
            {0, 2, 3, 2},
            {6, 0, 3, 2},
            {1, 2, 0, 4},
            {1, 2, 1, 0},
    };

    for(int i = 0; i < 4; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            std::cout << matrix[i][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                //Новое значение ребра равно минимальному между старым
                //и суммой ребер i <-> k + k <-> j (если через k пройти быстрее)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 0; i < 4; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            std::cout << matrix[i][k] << " ";
        }
        std::cout << std::endl;
    }

    graph graph1(Array(0));
    graph1.print();
    graph1.addVertex(4);
    graph1.addArc(1, 2, 2);
    graph1.addArc(1, 3, 3);
    graph1.addArc(1, 4, 9);
    graph1.addArc(2, 1, 6);
    graph1.addArc(2, 3, 3);
    graph1.addArc(2, 4, 2);
    graph1.addArc(3, 1, 1);
    graph1.addArc(3, 2, 2);
    graph1.addArc(3, 4, 4);
    graph1.addArc(4, 1, 1);
    graph1.addArc(4, 2, 2);
    graph1.addArc(4, 3, 1);

    graph1.print();
    graph1.addVertex(1);
    graph1.addArc(4,1, 1);
    graph1.addArc(4,3, 4);
    graph1.addVertex(2);
    graph1.addArc(2,6,2);
    graph1.addArc(2, 5, 7);
    graph1.addArc(6,5, 9);
    graph1.print();
    graph1.FloydAlgorithm();
    graph1.delVertex(1);
    graph1.print();
    //graph1.dfs(1);
    return 0;
}

