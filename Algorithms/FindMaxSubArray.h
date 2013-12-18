#ifndef _FINDMAXSUBARRAY_H_
#define _FINDMAXSUBARRAY_H_

#include "common.h"

/*! find the maximum sub array when cross mid index

@return maximum value

@param pointer to array
@param the start index of the array
@param the middle index of the array
@param the end index of the array
@param the start index of the subArray
@param the end index of subArray
*/
int FindMaxCrossSubArray(int* _pArraySrc, int _iLeft, int _iMid, int _iRight, int* _pStart, int* _pEnd)
{
    int iLeftSum = 0;
    int iRightSum = 0;
    int iSum = 0;
    
    int i = 0;
    for (i = _iMid; i >= _iLeft; --i)
    {
        iSum = iSum + _pArraySrc[i];
        if (iSum > iLeftSum)
        {
            iLeftSum = iSum;
            *_pStart = i;
        }        
    }

    iSum = 0;
    for (i = _iMid + 1; i <= _iRight; ++i)
    {
        iSum = iSum + _pArraySrc[i];
        if (iSum > iRightSum)
        {
            iRightSum = iSum;
            *_pEnd = i;
        }        
    }
    return iLeftSum + iRightSum;    
} 


/*! find the maximum sub array

@return maximum value

@param pointer to array
@param the start index of the array
@param the end index of the array
@param the start index of the subArray
@param the end index of subArray
*/
int FindMaxSubArray(int* _pArraySrc, int _iLeft, int _iRight, int* _pStart, int* _pEnd)
{
    int iMid = 0;
    int iLeftSum = 0;
    int iCrossSum = 0;
    int iRightSum = 0;

    if (_iLeft == _iRight)
    {
        *_pStart = *_pEnd = _iLeft;
        return _pArraySrc[_iLeft];
    }
    else
    {
        iMid = (_iLeft + _iRight)/2;
        iLeftSum = FindMaxSubArray(_pArraySrc, _iLeft, iMid, _pStart, _pEnd);
        iRightSum = FindMaxSubArray(_pArraySrc, iMid+1, _iRight, _pStart, _pEnd);
        iCrossSum = FindMaxCrossSubArray(_pArraySrc, _iLeft, iMid, _iRight, _pStart, _pEnd);

        if (iLeftSum >= iRightSum && iLeftSum >= iCrossSum)
        {
            return iLeftSum;
        }
        else if (iRightSum >= iLeftSum && iRightSum >= iCrossSum)
        {
            return iRightSum;
        }
        else
        {
            return iCrossSum;
        }       
    }
} 

#endif