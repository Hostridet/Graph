#include <iostream>
#include "src/graph.h"
#include "src/array.h"

int main() {
    graph graph1(Array(0));
    graph1.print();
    graph1.addVertex(3);
    graph1.addArc(3, 1, 8);
    graph1.addArc(3, 2, 6);
    graph1.addArc(1, 2, 4);
    graph1.addArc(1, 3, 2);
    graph1.addArc(2, 1, 7);
    graph1.addArc(2, 3, 3);
    graph1.print();
    graph1.addVertex(1);
    graph1.addArc(4,1, 1);
    graph1.addArc(4,3, 4);

    graph1.print();
    graph1.addVertex(1);
    graph1.print();

    return 0;
}
