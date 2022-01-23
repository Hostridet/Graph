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
    Array(int size)
    {
        this->size = size;
        arr = new list[size];
    }

    void resize(int new_size)
    {
        list* arr2 = new list[new_size];
        int count = 0;
        int b = sqrt(size) - 1;
        for(int i = 0; i < this->size; i++)
        {
            arr2[i + count].a = arr[i].a;
            if (i == b)
            {
                b = b + sqrt(size);
                count++;
            }
        }
        this->size = new_size;
        delete[] arr;
        arr = arr2;
    }

    void add(int pos, int value)
    {
        arr[pos].a = value;
    }

    void del(int pos)
    {
        arr[pos].a = 0;
    }

    void deleteArray()
    {
        delete[] arr;
    }

    void print()
    {
        int count = 1;
        for(int i = 0; i < size; i++)
        {
            if (i == sqrt(size) * count)
            {
                std:: cout << std::endl;
                count++;
            }
            std::cout << arr[i].a << " ";
        }
        std::cout << std::endl;
    }
    int getSize()
    {
        return this->size;
    }
};