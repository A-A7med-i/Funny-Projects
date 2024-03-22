#include <iostream>

using namespace std;

void bubbleSort(int *array, int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        for (size_t j = 0; j < sz - i - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}