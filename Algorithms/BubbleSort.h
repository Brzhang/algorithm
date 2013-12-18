#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include "common.h"

/*! Sort the array with bubble Sort

@return NULL

@param pointer to array
@param the end index of the array will be sorted
*/
void BubbleSort(int* _pArraySrc, int _iRight)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < _iRight-1; ++i)
    {
        for (j = _iRight; j > i; --j)
        {
            if (_pArraySrc[j] < _pArraySrc[j-1])
            {
                swapValue(&_pArraySrc[j], &_pArraySrc[j-1]);
            }            
        }        
    }    
} 

#endif