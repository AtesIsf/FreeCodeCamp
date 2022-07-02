#include <stdio.h>
/*
Given unsorted numbers from 1 to n, find the largest possible
value the unsorted numbers when it is read as a single continuous number
in b swaps at most
*/
void printarr(int *arr, int n)
{
    for (int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *arr, int target, int pos)
{
    int temp = arr[target];
    arr[target] = arr[pos];
    arr[pos] = temp;
}

int maxind(int *arr, int n, int start)
{
    int max = start;
    for (int i = start+1; i<n; i++)
        if (arr[i] > arr[max])
            max = i;
    printf("%d\n", max);
    return max;
}

int main()
{
    int n, b, i;
    scanf("%d%d", &n, &b);
    int arr[n];
    for (i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    int count = 0;
    int max;
    while (count<b)
    {
        max = maxind(arr, n, count);
        swap(arr, count, max);
        count++;
    }
    printarr(arr, n);
    return 0;
}