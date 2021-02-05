#include <stdio.h>
#include <stdlib.h>

void setdata(int *A, int count)
{
    for (int i = 0; i < count; i++)
    {
        scanf("%i", (A + i));
    }
    return;
}

void printdata(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i\t", *(A + i));
    }
    printf("\n");
    return;
}
void conquor(int *A, int *lf, int *rf, int n)
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
        MergeSort(A, n);
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
