#include <stdio.h>
#include <stdlib.h>
#include "Algorithms/common.h"

#define _INSERTIONSORT_
#define _MERGESORT_
#define _BUBBLESORT_
#define _HEAPSORT_
#define _QUICKSORT_
#define _FINDMAXSUBARRAY_
#define _SQUAREMATRIXMULTIPLY_

#ifdef _INSERTIONSORT_
#include "Algorithms/InstertionSort.h"
#endif

#ifdef _MERGESORT_
#include "Algorithms/MergeSort.h"
#endif

#ifdef _BUBBLESORT_
#include "Algorithms/BubbleSort.h"
#endif

#ifdef _HEAPSORT_
#include "Algorithms/HeapSort.h"
#endif

#ifdef _QUICKSORT_
#include "Algorithms/QuickSort.h"
#endif

#ifdef _FINDMAXSUBARRAY_
#include "Algorithms/FindMaxSubArray.h"
#endif

#ifdef _SQUAREMATRIXMULTIPLY_
#include "Algorithms/SquareMatrixMultiply.h"
#define CONST_MATRIX_ROW   3
#endif

#define CONST_INT_LISTNUM  10

void main()
{
    int iIntList[CONST_INT_LISTNUM];
    int iStart = 0;
    int iEnd = 0;
    int iSum = 0;

    int i = 0; 
    int j = 0;

#ifdef _SQUAREMATRIXMULTIPLY_
    Matrix matrixA;
    Matrix matrixB;
    Matrix RetMatrix;
    RetMatrix.pData = NULL;

    CreateMatrix(&matrixA, CONST_MATRIX_ROW, CONST_MATRIX_ROW);
    CreateMatrix(&matrixB, CONST_MATRIX_ROW, CONST_MATRIX_ROW);
    for (i = 0; i < matrixA.iRow; ++i)
    {
        for (j = 0; j < matrixA.iColumn; ++j )
        {
            matrixA.pData[i][j] = 2;
            matrixB.pData[i][j] = 3;
        }        
    }
    
#endif

    for(i = 0; i < CONST_INT_LISTNUM; ++i)
    {
        iIntList[i] = rand()%100;
        if(iIntList[i] & 0x1)
        {
            iIntList[i] *= -1 ;
        }
    }

    printArray(iIntList, CONST_INT_LISTNUM);

#ifdef _INSERTIONSORT_
    InsertionSort(iIntList, CONST_INT_LISTNUM);
    
    printf("InsertionSort:\n");
    printArray(iIntList, CONST_INT_LISTNUM);
#endif

#ifdef _MERGESORT_
    MergeSort(iIntList, 0, CONST_INT_LISTNUM-1);

    printf("MergeSort:\n");
    printArray(iIntList, CONST_INT_LISTNUM);
#endif

#ifdef _BUBBLESORT_
    BubbleSort(iIntList, CONST_INT_LISTNUM-1);

    printf("BubbleSort:\n");
    printArray(iIntList, CONST_INT_LISTNUM);
#endif

#ifdef _HEAPSORT_
    HeapSort(iIntList, CONST_INT_LISTNUM);

    printf("HeapSort:\n");
    printArray(iIntList, CONST_INT_LISTNUM);
#endif

#ifdef _QUICKSORT_
    QuickSort(iIntList, 0, CONST_INT_LISTNUM-1);

    printf("QuickSort:\n");
    printArray(iIntList, CONST_INT_LISTNUM);
#endif

#ifdef _FINDMAXSUBARRAY_
    iSum = FindMaxSubArray(iIntList, 0, CONST_INT_LISTNUM-1, &iStart, &iEnd);
    
    printf("Max subArray sum = %d, startIndex = %d, endIndex = %d,\n", iSum, iStart, iEnd);
#endif

#ifdef _SQUAREMATRIXMULTIPLY_
    SquareMatrixMultiply(matrixA, matrixB, &RetMatrix);
    
    for(i = 0; i < matrixA.iRow; ++i)
    {
       printArray(RetMatrix.pData[i],matrixA.iColumn);
    }

    ReleaseMatrix(&RetMatrix);
    ReleaseMatrix(&matrixA);
    ReleaseMatrix(&matrixB);
#endif

    return;
}
