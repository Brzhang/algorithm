#ifndef _COUNTINGSORT_H_
#define _COUNTINGSORT_H_

#include <string.h>
#include "common.h"

/*! Get the largest item of the array

@return int the last item

@param pointer to array
@param the length of the array
*/
int GetMaxItem(int* _pArraySrc, int _iLength)
{
    int i = 0;
    int iMax = 0;
    for(i = 0; i < _iLength; ++i)
    {
        if(iMax < _pArraySrc[i])
        {
            iMax = _pArraySrc[i];
        }
    }
    return iMax;
}

/*! sort the array with counting sort

@return NULL

@param pointer to array
@param the length of the array
*/
void CountingSort(int* _pArraySrc, int _iLength)
{
    int i = 0;
    int iMaxItem = 0;
    int* pTmpArray = NULL;
    int* pSrcClone = NULL;

    iMaxItem = GetMaxItem(_pArraySrc, _iLength);
    pTmpArray = (int*)malloc(iMaxItem*sizeof(int));
    memset(pTmpArray, 0 ,iMaxItem*sizeof(int));

    pSrcClone = (int*)malloc(_iLength*sizeof(int));
    memcpy(pSrcClone, _pArraySrc, _iLength*sizeof(int));

    for(i = 0; i < _iLength; ++i)
    {
        ++pTmpArray[_pArraySrc[i]-1]; //count the same item
    }

    for(i = 1; i < iMaxItem; ++i)
    {
        pTmpArray[i] += pTmpArray[i-1];
    }

    for(i = _iLength - 1; i >= 0; --i)
    {
        _pArraySrc[ pTmpArray[ pSrcClone[i]-1 ] - 1 ] = pSrcClone[i];
        --pTmpArray[_pArraySrc[i]-1];
    }

    free(pTmpArray);
    free(pSrcClone);
}

#endif
