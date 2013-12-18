#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_

#include "common.h"

/*! Sort the array with Insertion Sort

@return NULL

@param pointer to array
@param the start index of the array will be sorted
@param the end index of the array will be sorted
*/
void InsertionSort(int* _pArraySrc, int _iLength)
{
    int i = 0;
    int j = 0;

    for (j = 1; j < _iLength; ++j)
    {
        int iKey = _pArraySrc[j];
        i = j - 1;
        while (i >= 0 && _pArraySrc[i] > iKey)
        {
            copyValue(&_pArraySrc[i],&_pArraySrc[i+1]);
            --i;
        }
        copyValue(&iKey, &_pArraySrc[i+1]);
    }
}

#endif