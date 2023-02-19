#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int * rand_num(){
 static int arr[100000];
 int i;
 for (i = 0; i < 100000; ++i){
 arr[i] = rand();
 }

 return arr;
}
void insertionSort(int array[], int n)
{
 int i, element, j;
 for (i = 1; i < n; i++) { element = array[i]; j = i - 1; while (j
>= 0 && array[j] > element) {
 array[j + 1] = array[j];
 j = j - 1;
 }
 array[j + 1] = element;
 }
}
void swap(int *xp, int *yp)
{
 int temp = *xp;
 *xp = *yp;
 *yp = temp;
}
void selectionSort(int arr[], int n)
{
 int i, j, min_idx;

 for (i = 0; i < n-1; i++)
 {

 min_idx = i;
 for (j = i+1; j < n; j++)
 if (arr[j] < arr[min_idx])
 min_idx = j;

 if(min_idx != i)
 swap(&arr[min_idx], &arr[i]);
 }
}
int main()
{
 int *x1;
 int i,i1;
 int arr[100000];
 x1 = rand_num();
 FILE *fp;
 int ch;
 fp = fopen("rand_num.txt","w");
 for (i1 = 0; i1 < 100000; ++i1){
 fprintf(fp,"%d\n",*(x1 + i1));
 }
 fp = fopen("rand_num.txt", "r");

 for ( i = 0; i < 100000; i++)
 {
 fscanf(fp,"%d\n",&arr[i]);
 }

 FILE *file = fopen("output.txt","w");

 int num = 100;
 for ( i = 0; i < 1000; i++)
 {
 clock_t t1 = clock();
 insertionSort(arr,num);
 clock_t t2 = clock();
 clock_t t3 = clock();
 selectionSort(arr,num);
 clock_t t4 = clock();
 double insertion_time =
(double)(t2-t1)/(double)CLOCKS_PER_SEC;
 double selection_time =
(double)(t4-t3)/(double)CLOCKS_PER_SEC;
 fprintf(file,"%d\t",i+1);
 fprintf(file,"%f\t",insertion_time);
 fprintf(file,"%f\n",selection_time);

 num += 100;
 }
 fclose(fp);
 fclose(file);
 return 0;
}
