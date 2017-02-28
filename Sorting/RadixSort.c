#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int* Barray, A_length;
int* COUNTING_SORT(int*, int*, int);
void RADIX_SORT(int*, int);
int main(void)
{
    srand(time(NULL));
    int i, number, digit;
    printf("請輸入個數：");
    scanf("%d", &number);
    A_length=number;
    int* array=(int*)malloc(number*sizeof(int));
    Barray=(int*)malloc(number*sizeof(int));
    printf("請輸入位元數：");
    scanf("%d", &digit);
    for(i=0; i<number; i++)
         array[i]=(rand()%((int)pow(10, digit)-(int)pow(10,digit-1)))+(int)pow(10,digit-1);
    printf("基數排序前：");
    for(i=0; i<number; i++)
        printf("%*d ", 3, array[i]);
    printf("\n");
    RADIX_SORT(array, digit);
    printf("基數排序後：");
    for(i=0; i<number; i++)
    {
        if(i!=number-1)
            printf("%*d < ", 3, Barray[i]);
        else
            printf("%*d", 3, Barray[i]);
    }
    printf("\n");
    free(array);
    free(Barray);
    system("PAUSE");
    return 0;
}
void RADIX_SORT(int* A, int d)
{
    int i;
    for(i=0; i<d; i++)
        Barray=COUNTING_SORT(A, Barray, (int)pow(10, i+1)-1);
}
int* COUNTING_SORT(int* A, int* B, int k)
{
     int i, j, number;
     int* C=(int*)malloc((k+1)*sizeof(int));
     for(i=0; i<k+1; i++)
         C[i]=0;
     for(j=0; j<A_length; j++)
         C[A[j]%(k+1)]=C[A[j]%(k+1)]+1;
     for(i=1; i<k+1; i++)
         C[i]=C[i]+C[i-1];
     for(j=A_length-1; j>-1; j--)
     {
         B[C[A[j]%(k+1)]-1]=A[j];
         C[A[j]%(k+1)]=C[A[j]%(k+1)]-1;
     }
     free(C);
     return B;
}
