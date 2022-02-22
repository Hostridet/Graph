#pragma once
#include <iostream>
#include "array.h"

using namespace std;

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
    int* getRelated(int vertex);
    //Алгоритм Флойда
    void FloydAlgorithm();

};
