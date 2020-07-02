#pragma once
#include <vector>

// Standard partition process of QuickSort(). 
// It considers the last element as pivot 
// and moves all smaller element to left of 
// it and greater elements to right 
int quickselect_partition( std::vector<int> arr, int l, int r /*incl*/ )
{
    auto pivot = arr[r];
    auto i = l; // Index of smaller element
    for (auto j = l; j <= r - 1; j++) 
    {
        // If current element is smaller or equal than the pivot  
        if (arr[j] <= pivot) {
            std::swap( arr[i], arr[j] );
            i++; // increment index of smaller element  
        }
    }
    std::swap( arr[i], arr[r] );
    return i;
}

// This function returns k'th smallest  
// element in arr[l..r] using QuickSort  
// based method.  ASSUMPTION: ALL ELEMENTS 
// IN ARR[] ARE DISTINCT 
int quickselect_kthSmallest( std::vector<int> arr, int l, int r /*incl*/, int k )
{
    // If k is smaller than number of  
    // elements in array 
    if (k > 0 && k <= r - l + 1) {

        // Partition the array around last  
        // element and get position of pivot  
        // element in sorted array 
        int index = quickselect_partition( arr, l, r );

        // If position is same as k 
        if (index - l == k - 1)
            return arr[index];

        // If position is more, recur  
        // for left subarray 
        if (index - l > k - 1)
            return quickselect_kthSmallest( arr, l, index - 1, k );

        // Else recur for right subarray 
        return quickselect_kthSmallest( arr, index + 1, r,
            k - index + l - 1 );
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

/* low  --> Starting index,  high  --> Ending index */
void quicksort( std::vector<int> arr, int low, int high /*incl*/)
{
    if (low < high)
    {
        // partitioning_idx is partitioning index, arr[pi] is now at right place
        auto partitioning_idx = quickselect_partition( arr, low, high );

        quicksort( arr, low, partitioning_idx - 1 );  // Before partitioning_idx
        quicksort( arr, partitioning_idx + 1, high ); // After partitioning_idx
    }
}