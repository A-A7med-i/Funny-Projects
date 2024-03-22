import numpy as np


def merge(A, szA, B, szB):
    idxA = 0
    idxB = 0
    idxC = 0

    C = np.zeros(szA + szB, dtype=np.int32)

    while szA > idxA and szB > idxB:
        if A[idxA] > B[idxB]:
            C[idxC] = B[idxB]
            idxB += 1
        else:
            C[idxC] = A[idxA]
            idxA += 1
        idxC += 1

    while szA > idxA:
        C[idxC] = A[idxA]
        idxA += 1
        idxC += 1

    while szB > idxB:
        C[idxC] = B[idxB]
        idxB += 1
        idxC += 1

    A[: szA + szB] = C[: szA + szB]


def mergeSort(A, sz):
    if sz < 2:
        return

    half = sz // 2

    mergeSort(A, half)
    mergeSort(A[half:], sz - half)

    merge(A, half, A[half:], sz - half)
