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
/*
    Properties of selectionsort algorithm
1. It is a inplace algorithm.
2. It is a stable algorithm
*/
void SelectionSort(int *A, int n)
{
    int min;
    for (int x = 0; x < n - 1; x++) /* n passes */
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
        SelectionSort(A, n);
        printf("The sorted elements are: ");
        printdata(A, n);
        free(A);/*Securing the assets*/
    }
    else
    {
        printf("\n*******Failed to allocate the memory:*******\n");
    }
    return 0;
}
