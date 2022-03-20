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

int graph::delVertex(int count)
{
    for (int i = 0; i < count; i++)
    {
        this->vertexCount--;
        this->matrix.resizeDel(vertexCount * vertexCount);
    }
}

bool graph::searchVertex(int vertex) {
    if (vertex <= vertexCount && vertex > 0)
        return true;
    else
        return false;
}

int graph::addArc(int first, int second, int value)
{
    if (vertexCount > 1 && first != second && first <= vertexCount && second <= vertexCount)
    {
        this->arcCount++;
        matrix.add(first, second, value);
    }
}

int graph::delArc(int first, int second)
{
    if (vertexCount > 1 && first != second && first <= vertexCount && second <= vertexCount)
    {
        this->arcCount--;
        matrix.del(first * vertexCount - vertexCount - 1 + second);
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

//Функции для обхода
bool graph::isMassEmpty(int* mas)
{
    bool flag = true;
    for(int i = 0; i < vertexCount; i++)
    {
        if (mas[i] != 0)
            flag = false;
    }
    return flag;
}

//Функции для обхода
int graph::findLast(int *mas)
{
    int value = 0;
    for (int i = 0; i < vertexCount; i++)
    {
        if (mas[i] != 0)
            value = i;
    }
    return value;
}

//Функции для обхода
void graph::printMass(int *mas)
{
    cout << "обход" << endl;
    cout << "{ ";
    for (int i = 0; i < vertexCount; i++)
    {
        //if (mas[i] != -1)
            cout  << mas[i] << " ";
    }
    cout << "}" << endl;
}
//Функции для обхода
void graph::getRelated(int vertex, ArcStack &arcs)
{
    if (vertex <= vertexCount)
    {
        for (int i = 0; i < vertexCount; i++)
        {
            if((matrix.getValue(vertex, i) != 0))
            {
                arcs.(matrix.getValue(vertex, i));
            }
        }

    }
}

List graph::fillUnmarkedVertex() {
    List list;
    for (int i = 0; i < vertexCount; i++)
    {
        list.push_back(i + 1);
    }
    return list;
}

void graph::markVertex(List &list, int vertex) {
    auto iter = list.cbegin();
    for (int i = 0; i < vertex - 1; i ++)
        iter++;
    list.erase(iter);
    auto iter2 = list.cbegin();
    for (int i = 0; i < vertex - 1; i ++)
        iter2++;
    list.emplace(iter2 , -1);
    // -1 - вершина помечена
}

bool graph::isMarkedVertex(List list, int vertex) {
    auto iter = find_if(list.cbegin(), list.cend(), [&]( const int v ){ return 0 == ( v % vertex );});
    if ( list.end() == iter )
    {
        return false;
    }
    return true;
}
void printList(List arcs) {
    for (int n : arcs)
    {
        std::cout << n << "\t";
    }
}
void printStack(ArcStack s)
{
    while (!s.empty())
    {
        cout << s.top() <<' ';
        s.pop();
    }
}
void graph::dfs(int vertex)
{
    if (!searchVertex(vertex))
    {
        cout << "Такая  вершина не существует" << endl;
        return;
    }
    //Вершины с пометками
    List markedVertex = fillUnmarkedVertex();
//    markVertex(markedVertex, 4);
//    isMarkedVertex(markedVertex, 8);
//    printList(markedVertex);
    Array markedArcs(vertexCount * vertexCount);
    ArcStack arcs;
//    markedArcs.print();
    dfsStart(markedVertex, vertex, markedArcs, arcs);

}

void graph::dfsStart(List &markedVertex, int vertex, Array &markedArcs, ArcStack &arcs) {
    //Помечаем вершину
    markVertex(markedVertex, vertex);
    printList(markedVertex);
    getRelated(vertex, arcs);
    cout << "2323" << endl;
    printStack(arcs);
}
int graph::getArcCount()
{
    return this->arcCount;
}

void graph::FloydAlgorithm()
{
    cout << "-----------------------------------------------------" << endl;
    cout << "Матрица смежности до алгоритма Флойда: " << endl;

    //Создаем новую матрицу в которой будем выводить результат алгоритма
    Array resultMatrix(vertexCount * vertexCount);
    resultMatrix = matrix;
    resultMatrix.print();

    for(int k = 0; k < vertexCount; k++)
    {
        for(int i = 0; i < vertexCount; i++)
        {
            for(int j = 0; j < vertexCount; j++)
            {
                if (resultMatrix.getValue(k + 1, j + 1) != 0 && resultMatrix.getValue(i + 1, k + 1) != 0 && resultMatrix.getValue(i + 1, j + 1) != 0)
                    resultMatrix.add(i + 1, j + 1, min(resultMatrix.getValue(k + 1, j + 1) + resultMatrix.getValue(i + 1, k + 1), resultMatrix.getValue(i + 1, j + 1)));
            }
        }
    }

    cout << "Матрица смежности после алгоримта Флойда: " << endl;
    resultMatrix.print();
    cout << "-----------------------------------------------------" << endl;



}

int graph::getVertexCount()
{
    return this->vertexCount;
}

