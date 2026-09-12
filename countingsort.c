#include <stdio.h>

// Function to find the maximum element in the array
int getMax(int arr[], int len)
{
    int max = arr[0];

    // Check every element to find the largest value
    for(int i = 1; i < len; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

// Function to perform Counting Sort
void countingSort(int arr[], int len)
{
    // Find the maximum value
    int max = getMax(arr, len);

    // Create count array
    // Size is max + 1 because index starts from 0
    int count[max + 1];

    // Initialize all count values to 0
    for(int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Count how many times each number occurs
    for(int i = 0; i < len; i++)
    {
        count[arr[i]]++;
    }

    // Put the sorted values back into the original array
    int index = 0;

    for(int i = 0; i <= max; i++)
    {
        // If count[i] is greater than 0,
        // add i to the array that many times
        while(count[i]--)
        {
            arr[index] = i;
            index++;
        }
    }
}

// Function to display the array
void display(int arr[], int len)
{
    for(int i = 0; i <len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Main function
int main()
{
    int arr[] = {2, 9, 8, 6, 4, 4, 1};
    int len = 7;

    printf("Before sorting:\n");
    display(arr, len);

    // Call Counting Sort
    countingSort(arr, len);

    printf("After sorting:\n");
    display(arr, len);

    return 0;
}