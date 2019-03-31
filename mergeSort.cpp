// can't work on 1M input for random numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mergeSort(int [], int, int, int, int);
void merging(int [],int, int, int);

void random_number();
double with_file();

int main()
{
    int i, n;

    printf("Enter total number of elements:");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    int data[n];
    for(i = 0; i < n; i++)
    {
         scanf("%d", &data[i]);
    }

    clock_t start_time = clock();

    merging(data, 0, n - 1, n);
    printf("After merge sort:\n");
    for(i = 0;i < n; i++)
    {
         printf("%d   ",data[i]);
    }

    clock_t end_time = clock();
    double time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("\nSorting time taken is : %lf seconds\n", time);
    printf("Processor clocks : %d \n", end_time-start_time);

    random_number();

    double t2 = with_file();
    double t = t2 - time;

    printf("Comparing sorting time: %lf" , t);

    return 0;
}

void merging(int data[], int low, int high, int n)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;
        merging(data, low, mid, n);
        merging(data, mid + 1, high, n);
        mergeSort(data, low, mid, high, n);
    }
}

void mergeSort(int data[],int low,int mid,int high,int n)
{
    int i, mi, k, lo, temp[n];

    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (data[lo] <= data[mi])
        {
            temp[i] = data[lo];
            lo++;
        }
        else
        {
            temp[i] = data[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = data[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = data[k];
             i++;
        }
    }

    for (k = low; k <= high; k++)
    {
        data[k] = temp[k];
    }
}

void random_number()
{
    int n = 100 , j , i , temp;
    int data[n];

    printf("\nRandom numbers in [1,%d]\n", n);
    for (i = 0; i < n; i++)
    {
        data[i] = rand() % n + 1;
        printf("%d ", data[i]);
    }
    //SORTING
    merging(data, 0, n - 1, n);

    printf("\nAfter merge sort:\n");
    for(i = 0;i < n; i++)
    {
         printf("%d   ",data[i]);
    }

}

double with_file()
{

    int n = 100000 , j , i , temp;
    int data[n];

    FILE *input_fptr;
    input_fptr = fopen("G:\\LAB\\input_merge.txt","w+");

    if(input_fptr == NULL){
        printf("Error!");
        exit(1);
    }

    //printf("\nEnter size: ");
    //scanf("%d",&n);

    fprintf(input_fptr,"size = %d\n", n);

    for (i = 0; i < n; i++)
        data[i] = rand() % 100000 + 1;

    fprintf(input_fptr,"\nData = [",n);

    printf("\n\nData:(on file)\n");
    for(i=0; i<n; i++)
    {
        //scanf("%d", &data[i]);
        //printf("%d ", data[i]);
        fprintf(input_fptr,"%d ",data[i]);
    }
    printf("\n");
    fprintf(input_fptr,"]\n ");
    fclose(input_fptr);

    FILE *output_fptr;
    output_fptr = fopen("G:\\LAB\\output_merge.txt","w+");

    int num;
    if(output_fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    clock_t start_time = clock();
    //SORTING

    merging(data, 0, n - 1, n);
    printf("After merge sort:\n");
    for(i = 0;i < n; i++)
    {
         printf("%d   ",data[i]);
    }

    clock_t end_time = clock();
    double time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Sorting time taken is : %lf seconds\n", time);
    printf("Processor clocks : %d \n", end_time-start_time);

    printf("\nSorted data in ascending order: (on file)\n");
    fprintf(output_fptr,"\nSorted data in ascending order: [",data[i]);

    for(i=0; i < n; i++)
    {
        fprintf(output_fptr,"%d ",data[i]);
        //printf("%d ",data[i]);
    }
    fprintf(input_fptr,"]\n ");
    fclose(output_fptr);

    return time;

}

