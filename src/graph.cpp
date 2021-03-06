#include "graph.h"
using namespace std;


int graph::addVertex(int count = 1)
{
    for (int i = 0; i < count; i++)
    {
        this->vertexCount++;
        this->matrix.resize(vertexCount * vertexCount);
    }
    for (int i = 0; i < vertexCount+1; i++)
        for (int k = 0; k < vertexCount+1; k++)
            if (k == i)
                matrix.add(i,k,0);
}

int graph::delVertex(int count)
{
    if (vertexCount  > 0)
        for (int i = 0; i < count; i++)
        {
            this->vertexCount--;
            this->matrix.resizeDel(vertexCount * vertexCount);
        }
}

void graph::searchVertex(int vertex) {
    if (vertex <= vertexCount && vertex > 0)
    {
        cout << "Вершина: " << vertex << endl;
        cout << "[ ";
        for (int i = 0; i < vertexCount; i++)
        {
            cout << matrix.getValue(vertex, i + 1) << " ";
        }
        cout << "]" << endl;
    }
    else
        cout << "Поиск: вершина " << vertex <<" не существует" << endl;
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
    cout << "Матрица смежности: " << endl;
    this->matrix.print();
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
}



//Функции для обхода
void graph::printMass(int *mas)
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (mas[i] == -1)
            cout  << i + 1 << " ";
    }
    cout << endl;
}
//Функции для обхода
int* graph::getRelated(int vertex)
{
    int* mas = new int[vertexCount];
    if (vertex <= vertexCount)
    {
        for (int i = 0; i < vertexCount; i++)
        {
           mas[i] = matrix.getValue(vertex,i + 1);
        }

    }
    return mas;
}
// ------------------------- Функции для вершин ------------------------------
//Создание масивва непомеченных вершин
int* graph::fillUnmarkedVertex() {
   int* mas = new int[vertexCount];
   for (int i = 0; i < vertexCount; i++)
       mas[i] = i + 1;
   return mas;
}

//Помечаем вершину пройденой
void graph::markVertex(int* &mas, int vertex) {
    mas[vertex - 1] = -1;
}

//Проверяемм пройдена ли вершина
bool graph::isMarkedVertex(int* mas, int vertex) {
    if (mas[vertex - 1] == -1)
        return true;
    return false;
}
// -----------------------------------------------------------------------------
// ------------------------- Функции для дуг -----------------------------------
// Пометить дугу как пройденную
void graph::markArc(Array &mas, int vertex, int index) {
    mas.add(vertex, index + 1, 0);
}

// Заполняем неполмеченные дуги из вершины vertex
void graph::fillUnmarkedArcs(Array &mas, int vertex) {
    for (int i = 0; i < vertexCount; i++)
    {
        if (matrix.getValue(vertex, i + 1) != 999 && matrix.getValue(vertex, i + 1) != 0)
            mas.add(vertex, i + 1, 1);
    }
}

void graph::printArcs(Array mas, int vertex) {
    int count = 1;
    for (int i = 0; i < vertexCount * vertexCount; i++)
    {
        if (mas.getValueMas(i) == 1)
        {
            int first = (i + 1) % vertexCount;
            int second = (i + 1) / vertexCount;
            cout << second + 1 << " >> " << first << endl;
        }
    }
}

bool graph::isEmpty(Array mas) {
    for (int i = 0; i < vertexCount * vertexCount; i++) {
        if (mas.getValueMas(i) == 1)
            return false;
    }
    return true;

}

int graph::getFirstValue(Array &mas) {
    for (int i = 0; i < vertexCount * vertexCount; i++)
    {
        if (mas.getValueMas(i) == 1)
        {
            mas.setValue(i, 0);
            if (i < vertexCount)
                return i + 1;
            else
                return (i  %  vertexCount) + 1;
        }

    }
}

// -----------------------------------------------------------------------------

void graph::dfs(int vertex)
{
    if (!(vertex <= vertexCount && vertex > 0))
    {
        cout << "Такая  вершина не существует" << endl;
        return;
    }
    //Создаем массив пройденных вершин
    int* markedVertex = fillUnmarkedVertex();

    //Создаем массив пройденных дуг
    Array markedArcs(vertexCount * vertexCount);
    dfsStart(vertex, markedVertex, markedArcs);
    cout << "Пройденные вершины: " << endl;
    printMass(markedVertex);

}

void graph::dfsStart(int vertex, int* &markedVertex, Array &markedArcs) {
    //Помечем вершину
    markVertex(markedVertex, vertex);

    //Создаем массив смежных вершин по дугам
    fillUnmarkedArcs(markedArcs, vertex);

    //Вывод для пользователя
    cout << "Вершина: " << vertex << endl;
    cout << "Множество дуг: " << endl;
    markedArcs.print();

    while (!isEmpty(markedArcs))
    {
        int newPos = getFirstValue(markedArcs);
        if (!isMarkedVertex(markedVertex, newPos))
            dfsStart(newPos, markedVertex, markedArcs);
    }
}

bool graph::findCycle(Array resultMatrix) {
    for (int i = 0; i < vertexCount + 1; i++)
        for (int k = 0; k < vertexCount + 1; k++)
            if (i == k && resultMatrix.getValue(i,k) < 0)
                return true;
    return false;
}

void graph::FloydAlgorithm()
{
    cout << "-----------------------------------------------------" << endl;
    cout << "Матрица смежности до алгоритма Флойда: " << endl;

    //Создаем новую матрицу в которой будем выводить результат алгоритма
    Array resultMatrix(vertexCount * vertexCount);
    resultMatrix = matrix;
    resultMatrix.print();
    for(int k = 0; k < vertexCount; ++k)
    {
        for(int i = 0; i < vertexCount; ++i)
        {
            for(int j = 0; j < vertexCount; ++j)
            {
                if (resultMatrix.getValue(k + 1, j + 1) < 999 && resultMatrix.getValue(i + 1, k + 1) < 999)
                    resultMatrix.add(i + 1, j + 1, min(resultMatrix.getValue(k + 1, j + 1) + resultMatrix.getValue(i + 1, k + 1), resultMatrix.getValue(i + 1, j + 1)));
            }
        }
    }

    cout << "Матрица смежности после алгоримта Флойда: " << endl;
    if (findCycle(resultMatrix))
        cout << "Обнаружен отрицательный цикл" << endl;
    resultMatrix.print();
    cout << "-----------------------------------------------------" << endl;



}

int graph::getVertexCount()
{
    return this->vertexCount;
}

