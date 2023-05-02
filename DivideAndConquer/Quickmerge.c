#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15000

void merge();
void mergeSort();
void swap();
int partition();
void quickSort();

int main(){
    clock_t start_t, end_t;
    double total_t;
    int i;
    int A[MAX];

    for (int i = 0; i < MAX; i++)
    {
        // A[i] = MAX - i;
        // A[i] = i + 1;
        A[i] = rand()%MAX;

    }

    start_t = clock();
    printf("Starting of the sorting, start time = %ld\n", start_t);

    // quickSort(A, 0, MAX);
    mergeSort(A, 0, MAX);

    end_t = clock();
    printf("Ending of the sorting, start time = %ld\n", end_t);

    total_t = (double)(end_t - start_t);
    printf("Execution time taken = %f\n", total_t);

}

void merge(int A[], int low, int mid, int high)
{
    int i = low,  j  = mid + 1, k =  low;
    int B[MAX];
    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else 
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[i];
        j++;
        k++;
    }
    for (i = 0; i <= high; i++)
    A[i] = B[i];
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

void swap(int *a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int A[], int low, int high)
{
    int pivot = A[low];
    int  i = low,  j = high;
    while(i < j)
    {
        while (A[i] <= pivot)
        i++;
        while (A[j] > pivot)
        j--;
        if (i < j)
        swap(&A[i], &A[j]);
    }
    swap(&A[low], &A[j]);
    return j;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int j = partition(A, low, high);
        quickSort(A, low, j-1);
        quickSort(A, j+1, high);
    }
}
