#include "graph.h"
using namespace std;


int graph::addVertex(int count = 1)
{
    for (int i = 0; i < count; i++)
    {
        this->vertexCount++;
        this->matrix.resize(vertexCount * vertexCount);
    }
}


int graph::addArc(int first, int second, int value)
{
    if (vertexCount > 1 && first != second && first <= vertexCount && second <= vertexCount)
    {
        this->arcCount++;
        matrix.add(first * vertexCount - vertexCount - 1 + second , value);
    }
}

void graph::print() {
    cout << "-----------------------------------------------------" << endl;
    cout << "Количество вершин: " << this->vertexCount << endl;
    cout << "Количество дуг: " << this->arcCount << endl;
    cout << "Матрица смежности: " << endl;
    this->matrix.print();
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
}

void graph::dfs(int height)
{
    bool isUsed[vertexCount];
    isUsed[height] = true;

}

int graph::getArcCount()
{
    return this->arcCount;
}

int graph::getVertexCount()
{
    return this->vertexCount;
}

