/**
 *  \file mergesort.cc
 *
 *  \brief Implement your mergesort in this file.
 */
// Raiyan Nasim
// Armand Ahadi-Sarkani

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void Merge(keytype *A, int left, int middle, int right)
{
    keytype temp[right-left+1];
    int i = left, j = middle+1, k = 0;
    while(i <= middle && j <= right) // go through each half to the endpoints
    {
        if(A[i] < A[j])
        {
            temp[k] = A[i]; // set position on temp
            i++;
            k++;
        }
        else
        {
            temp[k] = A[j];
            j++;
            k++;
        }
    }
    while(i <= middle) // when pointer for i in left side of A doesn't reach the middle, fill in remaining values
    {
        temp[k] = A[i];
        i++;
        k++;
    }
    while(j <= right) // when pointer for j in right side of A doesn't reach the rightmost element, fill in remaining values
    {
        temp[k] = A[j];
        j++;
        k++;
    }
    for(i = left; i <= right; i++) // copy temp to A
    {
        A[i] = temp[i-left]; //temp starts from 0, A might be offset
    }
        

}
void MergeSort(keytype *A, int left, int right)
{
    if(left < right) // else do nothing
    {
        int middle = (left + right)/2;
        MergeSort(A, left, middle); // MergeSort the left half
        MergeSort(A, middle+1, right); // MergeSort the right half
        Merge(A, left, middle, right);
    }
}
void
mySort (int N, keytype* A)
{
    MergeSort(A, 0, N-1);
}

/* eof */
