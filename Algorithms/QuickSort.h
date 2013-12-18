#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include "common.h"

/*! partition the array

@return partition index

@param pointer to array
@param the start index of the array will be partitioned
@param the end index of the array will be partitioned
*/
int partition(int* _pArraySrc, int _iLeft, int _iRight)
{
    int iKey = 0;
    int i = _iLeft-1;
    int j = 0;

    copyValue(&_pArraySrc[_iRight], &iKey);
    
    for (j = _iLeft; j < _iRight; ++j)
    {
        if(_pArraySrc[j] <= iKey)
        {
            ++i;
            swapValue(&_pArraySrc[i],&_pArraySrc[j]);
        }
    }
    swapValue(&_pArraySrc[_iRight],&_pArraySrc[i+1]);
    return i+1;
}

/*! Sort the array with Quick Sort

@return NULL

@param pointer to array
@param the start index of the array will be sorted
@param the end index of the array will be sorted
*/
void QuickSort(int* _pArraySrc, int _iLeft, int _iRight)
{
    if (_iLeft < _iRight)
    {
        int k = partition(_pArraySrc, _iLeft, _iRight);
        QuickSort(_pArraySrc, _iLeft, k-1);
        QuickSort(_pArraySrc, k+1, _iRight);
    }
} 

#endif