#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i,j, temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selectionSort(int a[], int n){
    for(int i=0; i<n; i++)
    {
        int min =i;
        for(int j=1;j<n;j++)
        {
            if (a[j] > a[i])
            min = j;
        }
        if (min!=i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

int main() {
    clock_t start_t, end_t;
    double total_t;
    int i, n = 10000;
    int arr[10];
    for(i=0; i<n; i++)
    {
       //arr[i] = rand() ;//%15000; //-->average case
        //arr[i] = i+1; //-->best case
        arr[i] = 15000 -i; //--> worst case
    }
    start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);
    
    //insertionSort(arr, n);
    //selectionSort(arr, n);
 
   end_t = clock();
   printf("End of the big loop, end_t = %ld\n", end_t);
   
   total_t = (double)(end_t - start_t); 
   printf("Total time taken by CPU: %f\n",total_t);
   printf("Exiting of the program...\n");
}
