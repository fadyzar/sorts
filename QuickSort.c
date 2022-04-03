#include <stdio.h>
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low; // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++; // increment index of smaller elements
        }
    }
    swap(&arr[i], &arr[high]);
    return (i);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%4d", arr[i]);
    printf("\n");
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pivot = partition(arr, low, high);
        printArray(arr,6);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
    else {
        //stop condition
    }
}


// Driver Code
int main()
{
    int arr[] = { 14,33,27,10,35,19,42,44 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("unSorted array: \n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

// This code is contributed by rathbhupendra