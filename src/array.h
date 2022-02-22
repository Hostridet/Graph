#pragma once

#include <cmath>


struct list
{
    int a = 0;
    list* next;
};

class Array
{
    int size;
    list* arr;

public:
    //Конструктор
    Array(int size);
    //Увеличение размера при добавлении вершины
    void resize(int new_size);
    //Уменьшение размера при удалении вершины
    void resizeDel(int new_size);
    //Добавление значения
    void add(int i, int j, int value);
    //Удаление значения
    void del(int pos);
    //Удаление массива
    void deleteArray();
    //Вывод в виде матрицы
    void print();
    //Вывод в иде одномерного массива
    void printArray();
    //Получение значения
    int getValue(int i, int j);
    //Получение размера
    int getSize();
};