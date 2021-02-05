#include<stdlib.h>
#define QuickSort Sort

/**************Insertion Sort**************/
void InsertionSort(int *A, int n)
{
    int hole = 0;
    for (int x = 1; x < n; x++)/*for n-passes*/
    {
        hole = x;
        while (hole && A[hole] < A[hole - 1])
        {
            A[hole] += A[hole - 1] - (A[hole - 1] = A[hole]);
            hole--;
        }
    }
    return;
}

/*************Selection Sort****************/
void SelectionSort(int *A, int n)
{
    int min;
    for (int x = 0; x < n - 1; x++) /*for n-passes */
    {
        min = x;
        for (int y = x + 1; y < n; y++)
        {
            if (A[y] < min)
            {
                min = y;
            }
        }
        A[min] += A[x] - (A[x] = A[min]);
    }
    return;
}


/************Bubble Sort************/
void BubbleSort(int *A, int n)
{
    int flag = 0;
    for (int x = 0; x < n; x++) /* for n-passes */
    {
        for (int y = 0; y < n - x; y++)
        {
            if (A[y] > A[y + 1])
            {
                A[y + 1]+=A[y] - (A[y] = A[y + 1]);
                flag++;
            }
        }
        if (!flag)/*If array is already sorted then return.*/
        {
            return;
        }
    }
    return;
}

/****************Merge Sort*******************/
void conquor(int *A, int *lf, int *rf, int n)/*function to merge the two subarray*/
{
    int k = 0, i = 0, j = 0, mid = n / 2;
    while (i < mid && j < n - mid)
    {
        if (lf[i] < rf[j])
            A[k++] = lf[i++];
        else
            A[k++] = rf[j++];
    }
    while (i < mid)
        A[k++] = lf[i++];
    while (j < n - mid)
        A[k++] = rf[j++];
}
void MergeSort(int *A, int n) /*Average case time-complexity: O(n*logn)*/
{
    if (n <= 1) /*Exit condition*/
        return;
    int mid = n / 2;                               /*mid point*/
    int *lf = (int *)calloc(mid, sizeof(int));     /*Left Subarray*/
    int *rf = (int *)calloc(n - mid, sizeof(int)); /*Right Subarray*/
    for (int i = 0; i < mid; i++)/*filling the left sub-array*/
        lf[i] = A[i];
    for (int i = mid; i < n; i++)/*filling the right sub-array*/
        rf[i - mid] = A[i];
    MergeSort(lf, mid);     /*Recursive approach*/
    MergeSort(rf, n - mid); /*Recursive approach*/
    conquor(A, lf, rf, n);/*putting the sorted sub-arrays into original array*/
    free(lf);
    free(rf);
    return;
}

/***************Quick Sort*******************/
int divider(int* A, int start, int last)/*function to divide the left half and right half with respect to the pivot*/
{
    int pivot = last;/*Let's target the last index as pivot*/
    int pindex = start;
    for (int i = start; i < last; i++)
    {
        if (A[i] <= A[pivot])
        {
            A[i] += A[pindex] - (A[pindex] = A[i]);
            pindex++;
        }
    }
    A[last] += A[pindex] - (A[pindex] = A[last]);
    return pindex;/*finally returning the pivot index*/
}

void QuickSort(int *A, int start, int last)/*Worst case time-complexity: O(n*n)*/
{
    if (start < last)
    {
        int pindex = divider(A, start, last);/*here, pindex is index of pivot element*/
        QuickSort(A, start, pindex-1);/*Left patition from the starting and upto the pivot*/
        QuickSort(A, pindex+1, last);/*Right patition from the pivot and upto the end*/
    }
    return;
}