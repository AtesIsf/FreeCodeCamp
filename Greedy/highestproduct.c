#include <stdio.h>
/*
    Find the largest possible product of three elements
    in the given array.
*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr, n);

    int case1 = arr[n-3] * arr[n-2] * arr[n-1]; // Highest 3
    int case2 = arr[0] * arr[1] * arr[n-1]; // Highest, Lowest 2 (Considering negatives)

    if (case1 > case2)
        printf("%d\n", case1);
    else
        printf("%d\n", case2);
    return 0;
}