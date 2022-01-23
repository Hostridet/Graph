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

public:
    graph(Array matrix) : matrix(matrix) {
        this->vertexCount = 0;
        this->arcCount = 0;
    }

    //Добавление вершины
    int addVertex(int count);
    //Добавление дуги
    int addArc(int first, int second, int value);
    //Вывод матрицы смежности
    void print();
    //Получение количества вершин
    int getVertexCount();
    //Получение количества дуг
    int getArcCount();
    //обход в глубину
    void dfs(int height);

};

