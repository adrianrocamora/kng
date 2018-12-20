void partition(int *a, int size) {
    int pivot = a[0];   // Note: not the best pivot choice
    // Take the median of 3 random numbers in the range
    int left, right;
    for(left = 1, right = size-1; left < right; )
    {
        if(a[left] > pivot && a[right] <= pivot)
        {
            swap(left, right, a);
        }
        if(a[left] <= pivot) left++;
        if(a[right] > pivot) right--;
    }
}
