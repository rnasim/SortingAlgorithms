/**
 *  \file insertion-sort-bisearch.cc
 *
 *  \brief Implement your insertion sort with binary search in this file.
 */

// Raiyan Nasim
// Armand Ahadi-Sarkani

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

int BinarySearch(keytype *A, keytype e, int low, int high)
{
    int mid = (high + low)/2;
    if(high <= low)
    {
        return (A[low] < e)? (low+1) : low;
    }
    if(e == A[mid])
    {
        return mid+1;
    }
    if(A[mid] < e)
    {
        return BinarySearch(A, e, mid+1, high);
    }
    else
    {
        return BinarySearch(A, e, low, mid-1);
    }
}

void
mySort (int N, keytype* A)
{
    for(int i = 1; i < N; i++)
    {
        keytype current = A[i]; // e is the currently selected number
        int j = i - 1;
        int result = BinarySearch(A, current, 0, j);
        while(j >= result)
        {
            A[j+1] = A[j]; // swap positions on the array to make room for current number
            j--;
        }
        A[j+1] = current;
    }
}

/* eof */
