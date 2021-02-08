#include <stdio.h>
#include <stdlib.h>

void setdata(int *A, int count) /*function to take user input at runtime*/
{
    for (int i = 0; i < count; i++)
    {
        scanf("%i", (A + i));
    }
    return;
}

void printdata(int *A, int n) /*function to print the elements of array*/
{
    for (int i = 0; i < n; i++)
    {
        printf("%i\t", *(A + i));
    }
    printf("\n");
    return;
}

/*
1. Inplace Sorting-algorithm.
2. 
*/

/*Average Case Time complexity O(n*logn), */
/*Worst Case Time Complexity O(n*n)*/
void QuickSort(int *A, int start, int last)
{
    if (start < last)
    {
        int pivot;
        for (int i = start; i < last; i++)
        {
            if (A[i] > A[pivot])
            {
                A[i] = A[i] + A[pivot] - (A[pivot] = A[i]);
            }
        }
        QuickSort(A, start, pivot - 1); /*Left patition from the starting and upto the pivot*/
        QuickSort(A, pivot + 1, last);  /*Right patition from the pivot and upto the end*/
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the lenght of array: ");
    scanf("%i", &n);
    int *A = (int *)calloc(n, sizeof(int));
    if (!*A)
    {
        *(A + n) = '\n';
        printf("\nEnter the elements: ");
        setdata(A, n);
        QuickSort(A, 0, n - 1);
        printf("The sorted elements are: ");
        printdata(A, n);
        free(A); /*Securing the assets*/
    }
    else
    {
        printf("\n*******Failed to allocate the memory:*******\n");
    }
    return 0;
}
