#ifndef _SQUAREMATRIXMULTIPLY_H_
#define _SQUAREMATRIXMULTIPLY_H_

#include "common.h"

/*! Matrix multiply

@return NULL

@param matrix A
@param matrix B has the same row equal column as matrix A.
@param pointer to the result matrix, the pointer should be define and release by the caller.
*/
void SquareMatrixMultiply(const Matrix _matrixA, const Matrix _matrixB, Matrix *_pResult)
{
    int i = 0;
    int j = 0;
    int k = 0;

    CreateMatrix(_pResult, _matrixA.iRow, _matrixA.iColumn);
    
    for (i = 0; i < _pResult->iRow; ++i)
    {
        for (j = 0; j < _pResult->iColumn; ++j)
        {
            for (k = 0; k < _pResult->iRow; ++k)
            {
                _pResult->pData[i][j] = _pResult->pData[i][j] + _matrixA.pData[i][k] * _matrixB.pData[k][j];
            }            
        }        
    }    
}

#endif