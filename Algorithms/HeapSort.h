#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

#include "common.h"

/*! get the index of parent

@return parent index

@param current index
*/
int GetParentIndex(int _iIndex)
{
    return (_iIndex - 1) / 2;
}

/*! get the index of left child

@return left child's index

@param current index
*/
int GetLChildIndex(int _iIndex)
{
    return (_iIndex + 1) * 2 - 1;
}

/*! get the index of right child

@return right child's index

@param current index
*/
int GetRChildIndex(int _iIndex)
{
    return (_iIndex + 1) * 2;
}

/*! find the max of sub tree

@return NULL

@param pointer to array
@param the length of the array
@param the root index of the sub tree we will deal with
*/
void MaxHeapify(int* _pArraySrc, int _iLength, int _iIndex)
{
    int iLChildIndex = 0;
    int iRChildIndex = 0;
    int iLargestIndex = 0;

    iLChildIndex = GetLChildIndex(_iIndex);
    iRChildIndex = GetRChildIndex(_iIndex);
    if (iLChildIndex < _iLength && _pArraySrc[iLChildIndex] > _pArraySrc[_iIndex])
    {
        iLargestIndex = iLChildIndex;
    }
    else
    {
        iLargestIndex = _iIndex;
    }

    if (iRChildIndex < _iLength && _pArraySrc[iRChildIndex] > _pArraySrc[iLargestIndex])
    {
        iLargestIndex = iRChildIndex;
    }

    if (iLargestIndex != _iIndex)
    {
        swapValue(&_pArraySrc[_iIndex], &_pArraySrc[iLargestIndex]);
        MaxHeapify(_pArraySrc, _iLength, iLargestIndex);
    }
}

/*! build the array to be a heap (max-heap)

@return NULL

@param pointer to array
@param the length of the array
*/
void BuildMaxHeap(int* _pArraySrc, int _iLength)
{
    int i = 0;
    for (i = _iLength/2; i > 0; --i)
    {
        MaxHeapify(_pArraySrc, _iLength, i-1);
    }
}

/*! sort the array with heap sort

@return NULL

@param pointer to array
@param the length of the array
*/
void HeapSort(int* _pArraySrc, int _iLength)
{
    int i = 0;

    BuildMaxHeap(_pArraySrc, _iLength);

    for (i = _iLength - 1; i > 0; --i)
    {
        swapValue(&_pArraySrc[0], &_pArraySrc[i]);
        --_iLength;
        MaxHeapify(_pArraySrc, _iLength, 0);
    }
}

#endif
