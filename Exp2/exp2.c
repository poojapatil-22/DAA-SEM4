#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>

void dataInput()
{
        FILE *fptr;
        fptr = fopen("data.txt", "w");
    for (int i = 0; i < 100000; i++)
    {
        int temp = rand() ;
        fprintf(fptr, "%d\n", temp);
    }
        fclose(fptr);
}
void merge(long arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1] ;
    int R[n2];


    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// function to swap elements
void swap(long *a, long *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(long array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(long array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    dataInput();

    FILE *fptr;
    fptr = fopen("data.txt", "r");
    long arr[100000], arr1[100000], arr2[100000];
    for (int i = 0; i < 100000; i++)
    {
        fscanf(fptr, "%8ld", &arr[i]);
    }
    int s = 100;

    printf("Size\tMerge Sort\tQUICK sORT \n");
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j < 100000; j++)
        {
            arr1[j] = arr[j];
            arr2[j] = arr[j];
        }

        double diff1,diff2;
        struct timespec start, end;
        int i;

        clock_gettime(CLOCK_MONOTONIC, &start);

        int arr_size = sizeof(arr1) / sizeof(arr1[0]);
        mergeSort(arr1, 0, s);
        clock_gettime(CLOCK_MONOTONIC, &end);



        diff1 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

       clock_gettime(CLOCK_MONOTONIC, &start);
        quickSort(arr2,0, s);
        clock_gettime(CLOCK_MONOTONIC, &end);
        diff2 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000000000.0;
        printf("%d\t%f\t%f\n", s, diff1, diff2);
        s+=100;
}
        return 0;
    
}
