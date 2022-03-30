#include <iostream>
#include "src/graph.h"
#include "src/array.h"

int main() {
    graph graph1(Array(0));
    graph1.print();
    graph1.addVertex(4);
    graph1.addArc(1, 2, 2);
    graph1.addArc(1, 3, 3);
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
    graph1.FloydAlgorithm();
    graph1.print();
    graph1.dfs(0);
    graph1.print();
    graph1.searchVertex(1);
    return 0;
}

