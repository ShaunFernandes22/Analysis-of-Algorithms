#include <stdio.h>

int binarySearch(int [], int, int);

int main()
{
    int arr[20], n, i, key, ind;
    printf("Enter the number of elements:\t");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter element %d:\t",i+1);
        scanf("%d",&arr[i]);
    }
    
    printf("Enter the particular value you want to search:\t");
    scanf("%d",&key);
    ind = binarySearch(arr, n, key);
    if (ind == -1)
    printf("The entered element %d is not found in the list.\n",key);
    else 
    printf("The element is found at position %d (i.e. at index %d)",ind + 1, ind);
    return 0;
}

int binarySearch(int arr[], int n, int key) {
    int left, mid, right;
    left = 0;
    right = n - 1;
    while (left<=right)
    {
        mid = (left + right)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            right = mid - 1;
        }
        else 
        {
            left = mid +1;
        }
    }
    return -1;
}
