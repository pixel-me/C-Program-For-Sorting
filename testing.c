#include<stdlib.h>
#include<stdio.h>
#include"sort.hh"

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
        Sort(A, 0, n);
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