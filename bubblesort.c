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

void BubbleSort(int *A, int n)
{
    int flag = 0;
    for (int x = 0; x < n; x++) /* n passes */
    {
        for (int y = 0; y < n - x; y++)
        {
            if (A[y] > A[y + 1])
            {
                A[y + 1]+=A[y] - (A[y] = A[y + 1]);
                flag++;
            }
        }
        if (!flag)
        {
            return;
        }
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
        BubbleSort(A, n);
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
