#include<stdio.h>
#include <stdlib.h>
#include <time.h>

double insertation_sorting();
void random_number();
double with_file();

double insertion_sorting()
{

    int n, i, j, temp;
    int data[100];

    printf("Enter size = ");
    scanf("%d" , &n);
    printf("Enter data:\n");
    for(i=0; i<n; i++)
        scanf("%d", &data[i]);

    clock_t start_time = clock();
    for ( i = 0; i < n; i++)
    {
        j = i;
        /* Asc: data[j] < data[j-1]
          Desc: data[j] > data[j-1] */
        while (j > 0 && data[j] < data[j-1])
        {
            temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j--;
        }
    }
    clock_t end_time = clock();
    double time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Sorting time taken is : %lf seconds\n", time);
    printf("Processor clocks : %d \n", end_time-start_time);

    printf("In ascending order: \n");
    for(i=0; i<n; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");

    return time;

}

void random_number()
{
    int n = 10 , j , i , temp;
    int data[n];

    printf("\nRandom numbers in [1,%d]\n", n);
    for (i = 0; i < n; i++)
    {
        data[i] = rand() % n + 1;
        printf("%d ", data[i]);
    }

    for (i = 0; i < n; i++)
    {
        j = i;
        /* Asc: data[j] < data[j-1]
          Desc: data[j] > data[j-1] */
        while (j > 0 && data[j] < data[j-1])
        {
            temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j--;
        }
    }
    printf("\nIn ascending order: ");
    for(i=0; i<n; i++)
        printf("%d ",data[i]);

}

double with_file()
{

    int n = 100000 , j , i , temp;
    int data[n];

    FILE *input_fptr;
    input_fptr = fopen("G:\\LAB\\input.txt","w+");

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

    printf("Data:(on file)\n");
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
    output_fptr = fopen("G:\\LAB\\output.txt","w+");

    int num;
    if(output_fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    clock_t start_time = clock();
    for (i = 0; i < n; i++)
    {
        j = i;
        /* Asc: data[j] < data[j-1]
        Desc: data[j] > data[j-1] */
        while (j > 0 && data[j] < data[j-1])
        {
            temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j--;
        }
    }
    clock_t end_time = clock();
    double time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Sorting time taken is : %lf seconds\n", time);
    printf("Processor clocks : %d \n", end_time-start_time);

    printf("\nSorted data in ascending order: (on file)\n");
    fprintf(output_fptr,"\nSorted data in ascending order: [",data[i]);

    for(i=0; i <= n-1; i++)
    {
        fprintf(output_fptr,"%d ",data[i]);
        //printf("%d ",data[i]);
    }
    fprintf(input_fptr,"]\n ");
    fclose(output_fptr);
    return time;
}

int main()
{

    double t1 = insertion_sorting();
    random_number(); //not in file
    double t2 = with_file();
    double t = t1 - t2;

    printf("Comparing sorting time: %lf" , t);

    return 0;
}


