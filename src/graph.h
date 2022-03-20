#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "array.h"
#include <list>



using namespace std;
using List = std::list<int>;
using ArcStack = std::stack<int>;
using ArcQueue = std::queue<Array*>;
using VertexQueue = std::queue<Array>;

class graph {
private:
    //Колиичество вершин
    int vertexCount;
    //матрица смежности
    Array matrix;
    //Количество ребер
    int arcCount;
    bool isMassEmpty(int* mas);
    int findLast(int* mas);
    void printMass(int* mas);
    List fillUnmarkedVertex();
    void markVertex(List &list, int vertex);
    bool isMarkedVertex(List list, int vertex);
    void dfsStart(List &markedVertex, int vertex, Array &markedArcs, ArcStack &arcs);

public:
    graph(Array matrix) : matrix(matrix) {
        this->vertexCount = 0;
        this->arcCount = 0;
    }

    //Добавление вершины
    int addVertex(int count);
    //Удаление вершины
    int delVertex(int count);
    //Добавление дуги
    int addArc(int first, int second, int value);
    //Удаление дуги
    int delArc(int first, int second);
    //Вывод матрицы смежности
    void print();
    //Получение количества вершин
    int getVertexCount();
    //Получение количества дуг
    int getArcCount();
    //обход в глубину
    void dfs(int height);
    //Получение дуг из вершины
    void getRelated(int vertex, ArcStack &arcs);
    //Существует ли такая вершина
    bool searchVertex(int vertex);
    //Алгоритм Флойда
    void FloydAlgorithm();

};
