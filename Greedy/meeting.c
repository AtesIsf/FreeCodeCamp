#include <stdio.h>
/*
Find the minimum number of rooms needed for the given meeting time intervals
*/
typedef struct tuple
{
    int time;
    int room_change;
}tuple_t;

void swap(tuple_t *a, tuple_t *b)
{
    tuple_t temp = *a;
    *a = *b;
    *b = temp;
}

void sort(tuple_t *arr, int n)
{
    for (int i = 0; i<n-1; i++)
        for (int j = 0; j<n-1-i; j++)
            if (arr[j].time > arr[j+1].time)
                swap(&arr[j], &arr[j+1]);
}
void printarr(tuple_t *arr, int n)
{
    for (int i = 0; i<n; i++)
        printf("%d ", arr[i].time);
    printf("\n");
}

int main()
{
    int n, i;
    scanf("%d", &n);
    tuple_t times[n*2];
    for (i = 0; i<n*2; i++)
    {
        scanf("%d", &times[i].time);
        if (i % 2 == 0)
            times[i].room_change = 1;
        else
            times[i].room_change = -1;
    }
    sort(times, n*2);

    int curr = 0;
    int max = 0;
    for (i = 0; i<n*2; i++)
    {
        curr+=times[i].room_change;
        if (curr > max)
            max = curr;
    }
    printf("%d\n", max);
    return 0;
}
