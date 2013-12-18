#ifndef _SQUAREMATRIXMULTIPLYRECURSIVE_H_
#define _SQUAREMATRIXMULTIPLYRECURSIVE_H_

#include "common.h"

/*! Matrix multiply with recursive

@return NULL

@param matrix A
@param matrix B has the same row equal column as matrix A.
@param pointer to the result matrix, the pointer should be define and release by the caller.
*/
void SquareMatrixMultiplyRecursive(const Matrix _matrixA, const Matrix _matrixB, Matrix *_pResult)
{
    int i = 0;
    int j = 0;
    int k = 0;

    CreateMatrix(_pResult, _matrixA.iRow, _matrixA.iColumn);

    if (_matrixA.iRow == 1)
    {
        pResult->pData[1][1] = _matrixA.pData[1][1] * _matrixB.pData[1][1];
    }
    else
    {
        for (i = 0; i < 2; ++i)
        {
            for (j = 0; j < 2; ++j)
            {
                //TODO: cut the matrix into sub matrix
                //_pResult->pData[i][j] = SquareMatrixMultiplyRecursive();
            }        
        }    
    }
}

#endif