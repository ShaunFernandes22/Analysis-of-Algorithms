#include <stdio.h>
#include <stdlib.h>

int min, max;

void minmax(int arr[], int first, int last) {
    int max1, min1, mid;
    if (first == last) {
        max = arr[first];
        min = arr[first];
    }
    else if (first == last -1) {
        if (arr[first] > arr[last]) {
            max = arr[first];
            min = arr[last];
        }
        else {
            max = arr[last];
            min = arr[first];
        }
    }
    else {
        mid = (first + last)/2;
        minmax(arr, first, mid);
        max1 = max;
        min1 = min;
        minmax(arr, mid+1, last);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}

int main() {
    int i, n;
    int arr[20];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Randomly generated numbers : ");
    for (i=0; i<n; i++){
        arr[i] = rand() % 1000 + 1; // [1,1000]
        printf("%d ",arr[i]);
    }
    min = arr[0], max = arr[0];
    minmax(arr,0, n-1);
    printf("\nMax = %d\nMin = %d", max, min);
    return 0;
}
