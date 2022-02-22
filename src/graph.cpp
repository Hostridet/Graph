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
int* graph::getRelated(int vertex)
{
    int* arr = new int[vertexCount];
    if (vertex <= vertexCount)
    {
        for (int i = 0; i < vertexCount; i++)
        {
            if((matrix.getValue(vertex, i) != 0))
            {
                arr[i] = i;
            }
            else
            {
                arr[i] = -1;
            }
        }

    }
    return arr;
}

void graph::dfs(int vertex)
{
    int currentPos = vertex;
    //Создаем массив с метками вершин
    bool isUsed[vertexCount];
    //Присваиваем каждой вершине значение "не пройдено"
    for (int i = 0; i < vertexCount; i++)
    {
        isUsed[i] = false;
    }
    //Семейство дуг
    int* array;
    array = getRelated(1);
    printMass(array);
    //L:
        //Пометить вершину
        //isUsed[currentPos] = true;
        //array = getRelated(currentPos);
        //printMass(array);
        //while(!isMassEmpty(array))
        //{
           // currentPos = findLast(array);
          //  if (!isUsed[currentPos])
       //         goto L;
     //   }
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

