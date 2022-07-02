#include <stdio.h>
/*
Given an array of intervals, find the biggest 
possible number of mutually disjoint intervals.
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int *cor, int n)
{
    for(int i = 0; i<n-1; i++)
        for(int j = 0; j<n-1-i; j++)
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j + 1]);
                swap(&cor[j], &cor[j + 1]);
            }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    // Corresponding arrays
    int start_arr[n];
    int end_arr[n];

    for (i = 0; i<n; i++)
        scanf("%d%d", &start_arr[i], &end_arr[i]);

    sort(end_arr, start_arr, n);
    int count = 1;

    for (i = 0; i<n; i++)
    {
        if (start_arr[i+1] > end_arr[i])
            count+=1;

    }

    printf("%d\n", count);
    return 0;
}