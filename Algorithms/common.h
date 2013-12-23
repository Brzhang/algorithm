#ifndef _COMMON_H_
#define _COMMON_H_

#include<string>

/*! *************************Matrix**************************** */

typedef struct
{
    int** pData;
    int iRow;
    int iColumn;
}Matrix;

/*! copyValue for struct

@return NULL

@param pointer to source
@param pointer to destination
*/
void CreateMatrix(Matrix* _pmatrix, int iRow, int iColumn)
{
    int i = 0;

    _pmatrix->iRow = iRow;
    _pmatrix->iColumn = iColumn;

    _pmatrix->pData = (int(**))malloc(_pmatrix->iRow * sizeof(int));
    for (i = 0; i < _pmatrix->iRow; ++i)
    {
        _pmatrix->pData[i] = (int(*))malloc(_pmatrix->iColumn * sizeof(int));
        memset(_pmatrix->pData[i], 0, _pmatrix->iColumn* sizeof(int));
    }
}

void ReleaseMatrix(Matrix* _pmatrix)
{
    int i = 0;

    for (i = 0; i< _pmatrix->iRow; ++i)
    {
        free(_pmatrix->pData[i]);
    }
    free(_pmatrix->pData);
    _pmatrix->pData = NULL;
    _pmatrix->iRow = 0;
    _pmatrix->iColumn = 0;
}

/*! *************************Common Function**************************** */

/*! copyValue for struct

@return NULL

@param pointer to source
@param pointer to destination
*/
void copyValue(int* _pSrc, int* _pDst)
{
    *_pDst = *_pSrc;
}

/*! swapValue for variables

@return NULL

@param pointer to valueA
@param pointer to valueB
*/
void swapValue(int* _pValueA, int* _pValueB)
{
    int iTemp = 0;

    if (_pValueA == _pValueB)
    {
        return;
    }

    copyValue(_pValueA,&iTemp);
    copyValue(_pValueB,_pValueA);
    copyValue(&iTemp,_pValueB);
}

/*! print Array

@return NULL

@param pointer to array
@param length of array
*/
void printArray(int* _pArraySrc, int _iLength)
{
    int i = 0;
    for(i = 0; i < _iLength; ++i)
    {
        printf("   %d",_pArraySrc[i]);
    }
    printf("\n");
}

#endif
