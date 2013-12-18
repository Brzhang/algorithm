#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include "common.h"

/*! Merge the array

@return NULL

@param pointer to array
@param the start index of the array will be merge
@param the middle index of the array will be merge
@param the end index of the array will be merge
*/
void Merge(int* _pArraySrc, int _iLeft, int _iMid, int _iRight)
{
    int n = _iMid - _iLeft + 1;
    int m = _iRight - _iMid;

    int i = 0;
    int j = 0;
    int k = 0;

    int* iLArray = NULL;
    int* iRArray = NULL;
    iLArray = (int*)malloc(n * sizeof(int));
    iRArray = (int*)malloc(m * sizeof(int));

    if (iLArray == NULL || iRArray == NULL)
    {
        return;
    }

    for (i = 0; i < n; ++i)
    {
        copyValue(&_pArraySrc[_iLeft+i], &iLArray[i]);
    }
    for (j = 0; j < m; ++j)
    {
        copyValue(&_pArraySrc[_iMid+j+1], &iRArray[j]);
    }

    i = 0;
    j = 0;
    for (k = _iLeft; k <= _iRight; ++k)
    {
        if (i < n && j < m)
        {
            if (iLArray[i] <= iRArray[j])
            {
                copyValue(&iLArray[i], &_pArraySrc[k]);
                ++i;
            }
            else
            {
                copyValue(&iRArray[j], &_pArraySrc[k]);
                ++j;
            }       
        }
        else if (i >= n)
        {
            copyValue(&iRArray[j], &_pArraySrc[k]);
            ++j;
        }
        else
        {
            copyValue(&iLArray[i], &_pArraySrc[k]);
            ++i;
        }  
    }

    free(iLArray);
    free(iRArray);    
}

/*! Sort the array with Merge Sort

@return NULL

@param pointer to array
@param the start index of the array will be sorted
@param the end index of the array will be sorted
*/
void MergeSort(int* _pArraySrc, int _iLeft, int _iRight)
{
    if (_iLeft < _iRight)
    {
        int k = (_iLeft + _iRight)/2;
        MergeSort(_pArraySrc, _iLeft, k);
        MergeSort(_pArraySrc, k+1, _iRight);
        Merge(_pArraySrc, _iLeft, k, _iRight);
    }
} 

#endif