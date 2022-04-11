#include "array.h"
#include <iostream>

Array::Array(int size)
{
    this->size = size;
    arr = new list[size];
}

void Array::resize(int new_size)
{
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
}

void Array::resizeDel(int new_size)
{
    list* arr2 = new list[new_size];
    int count = 0;
    int b = sqrt(new_size);
    for(int i = 0; i < new_size; i++)
    {
        if (i == b)
        {
            b = b + sqrt(size) - 1;
            count++;
        }
        arr2[i].a = arr[i + count].a;
        //std::cout << "i = " << i << " b = " << b << " arr[i] = " << arr[i].a  << " arr[i + count] = " << arr[i+count].a << std::endl;

    }

    this->size = new_size;
    delete[] arr;
    arr = arr2;
}

void Array::del(int pos)
{
    arr[pos].a = 0;
}

void Array::deleteArray()
{
    delete[] arr;
}

void Array::print()
{
    {
        int count = 1;
        for(int i = 0; i < size; i++)
        {
            if (i == sqrt(size) * count)
            {
                std::cout << std::endl;
                count++;
            }
            if (arr[i].a == 999)
                std::cout << "∞" << " ";
            else
                std::cout << arr[i].a << " ";
        }
        std::cout << std::endl;
    }
}

void Array::printArray()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i].a << " ";
    }
    std::cout << std::endl;
}

int Array::getValue(int i, int j)
{
    int b = sqrt(size);
    return this->arr[i * b - b + j - 1].a;
}

void Array::add(int i, int j, int value)
{
    int b = sqrt(size);
    arr[i * b - b + j - 1].a = value;
}

int Array::getSize()
{
    return this->size;
}

int Array::getValueMas(int i) {
    return this->arr[i].a;
}

void Array::setValue(int i, int value) {
    this->arr[i].a = value;
}

