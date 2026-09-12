#include <stdio.h>

int pivot(int arr[], int start, int end)
{
    int piv = arr[end];

    int j = start - 1;

    for (int i = start; i < end; i++)
    {
        if (arr[i] < piv)
        {
            j++;

            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    // left side of pivot
    j++;

    int temp = arr[j];
    arr[j] = arr[end];
    arr[end] = temp;

    return j;
}

void partition(int arr[], int start, int end)
{
    if (start < end)
    {
        int pindex = pivot(arr, start, end);

        // left
        partition(arr, start, pindex - 1);

        // right
        partition(arr, pindex + 1, end);
    }
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};

    int len = 6;

    printf("Unsorted array: ");
    display(arr, len);

    partition(arr, 0, len - 1);

    printf("Sorted array: ");
    display(arr, len);

    return 0;
}


