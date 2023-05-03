#include <stdio.h>
#define MAX 20

void min_max(int A[], int i, int j, int max[], int min[], int index, int* min_both, int* max_both)
{
    if (i == j) //Single element
    {
        min[index] = A[i];
        max[index] = A[i];
        return;
    } 
    else if (i == j - 1)  // 2 elements
    {
        if (A[i] < A[j]) {
            min[index] = A[i];
            max[index] = A[j];
        } else {
            min[index] = A[j];
            max[index] = A[i];
        }
        return;
    } 
    else // more than 2 elements
    {
        int mid = (i + j) / 2; 
        
        min_max(A, i, mid, max, min, 0, min_both,  max_both); //left subarray call
        
        min_max(A, mid + 1, j, max, min, 1, min_both,  max_both); //right subarray call

         if (max[0] < max[1] && * max_both < max[1])
            * max_both = max[1];
        else if (max[0] > max[1] && * max_both < max[0])
            * max_both = max[0];
        if (min[0] < min[1] && * min_both > min[0])
            * min_both = min[0];
        else if (min[0] > min[1] && * min_both > min[1])
            * min_both = min[1];
    }
}

int main() {
    // int arr[] = {1,5,7,110,100,90};
    // int n = sizeof(arr)/sizeof(int);
    int n, arr[MAX];
    printf("Enter number of elements : ");
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        printf("Enter number %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    
    // array to store min max from 2 function calls
    int max[2], min[2];
    int i=0, j=n-1;
    // final var to compare values from both calls
    int minimum = arr[0], maximum = arr[0];
    
    // initialize to reference
    max[0]=arr[0], min[0] =arr[0], max[1] = arr[0], min[1]= arr[0];
    
    min_max(arr, i, j, max, min, 0, &minimum, &maximum);
    // printf("%d \n%d", maximum, minimum);
    printf("Maximum : %d\n", maximum);
    printf("Minimum : %d", minimum);
    
    return 0;
}
