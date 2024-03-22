#include <iostream>

using namespace std;

void merge(int *A, int szA, int *B, int szB)
{

    int idxA = 0;
    int idxB = 0;
    int idxC = 0;

    int *C = new int[szA + szB];

    while (szA > idxA && szB > idxB)
    {

        if (A[idxA] > B[idxB])
            C[idxC++] = B[idxB++];

        else
            C[idxC++] = A[idxA++];
    }

    while (szA > idxA)
        C[idxC++] = A[idxA++];

    while (szB > idxB)
        C[idxC++] = B[idxB++];

    for (size_t i = 0; i < szA + szB; i++)
    {
        A[i] = C[i];
    }

    delete[] C;
}

void mergeSort(int *A, int sz)
{

    if (sz < 2)
        return;

    int half = sz / 2;

    mergeSort(A, half);
    mergeSort(A + half, sz - half);

    merge(A, half, A + half, sz - half);
}
