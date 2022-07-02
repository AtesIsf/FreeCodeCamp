#include <stdio.h>
/*
Given n bulbs, either on or off (1 or 0), find the minimum
number of swithces to turn all the bulbs on if switching one makes all
to its right to flip as well
*/

void printarr(int *arr, int n)
{
    for (int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void arrcpy(int *arr, int *cpy, int n)
{
    for (int i = 0; i<n; i++)
        cpy[i] = arr[i];
}

void flip(int *arr, int ind, int n)
{
    for (int i = ind; i<n; i++)
    {
        if (arr[i] == 0)
            arr[i] = 1;
        else
            arr[i] = 0;
    }
}

void result(int *bulbs, int n, int cost)
{
    printf("\nResult: ");
    printarr(bulbs, n);
    printf("Cost: %d\n", cost);
}

void naive()
{
    int n;
    scanf("%d", &n);
    int bulbs[n];
    for (int i = 0; i<n; i++)
        scanf("%d", &bulbs[i]);
    int cost = 0;

    for (int i = 0; i<n; i++)
        if (bulbs[i] == 0)
        {
            flip(bulbs, i, n);
            cost++;
        }
    result(bulbs, n, cost);
}

void greedy()
{
    int n;
    scanf("%d", &n);
    int bulbs[n];
    for (int i = 0; i<n; i++)
        scanf("%d", &bulbs[i]);
    int cost = 0;

    for (int i = 0; i<n; i++)
    {
        if (cost % 2 == 1)
            bulbs[i] = !bulbs[i];
        if (bulbs[i] == 0)
            cost++;
    }

    result(bulbs, n, cost);
    // As you can see, it didn't change the result but it did find the cost
}

int main()
{
    // naive(); // The Naive Approach O(n^2) time complexity
    greedy(); // The Greedy Approach O(n) time complexity
    return 0;
}