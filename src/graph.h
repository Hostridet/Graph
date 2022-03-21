#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "array.h"
#include <list>



using namespace std;

class graph {
private:
    //Колиичество вершин
    int vertexCount;
    //матрица смежности
    Array matrix;
    //Количество ребер
    int arcCount;
    void printMass(int* mas);
    int* fillUnmarkedVertex();
    void markVertex(int* &mas, int vertex);
    bool isMarkedVertex(int* mas, int vertex);
    void dfsStart(int vertex, int* &markedVertex, Array &markedArcs);
    int* getRelated(int vertex);
    void fillUnmarkedArcs(Array &mas, int vertex);
    void markArc(Array &mas, int vertex, int index);
    void printArcs(Array mas, int vertex);
    bool isEmpty(Array mas);
    int getFirstValue(Array &mas);

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
    //Существует ли такая вершина
    bool searchVertex(int vertex);
    //Алгоритм Флойда
    void FloydAlgorithm();

};
