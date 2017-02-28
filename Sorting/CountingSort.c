#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 1000
int* COUNTING_SORT(int*, int*, int);
int A_length;
int main(void)
{
    srand(time(NULL));
    int i, j, n;
    printf("請輸入元素數目：");
    scanf("%d", &n);
    int* A = (int*)malloc(n*sizeof(int));
    int* B = (int*)malloc(n*sizeof(int));
    A_length=n;
    for(i=0; i<n; i++)
    {
        A[i]=(rand()%MAX_SIZE);
        int additional = rand()%2;
        if(additional==1)
            A[i]+=1;
    }
    printf("計數排序前：");
    for(i=0; i<n; i++)
    {
        if(i!=n-1)
            printf("%d，", A[i]);
        else
            printf("%d", A[i]);
    }
    printf("\n");
    B=COUNTING_SORT(A, B, 1000);
    printf("計數排序後：");
    for(i=0; i<n; i++)
    {
        if(i!=n-1)
            printf("%4d <=", B[i]);
        else
            printf("%4d", B[i]);
    }
    printf("\n");
    free(A);
    free(B);
    system("PAUSE");
    return 0;
}
int* COUNTING_SORT(int* A, int* B, int k)
{
     int i, j, C[k+1];
     for(i=0; i<k+1; i++)
         C[i]=0;
     for(j=0; j<A_length; j++)
         C[A[j]]=C[A[j]]+1;
     /*C[i]裡現在存著值等於i的個數*/
     for(i=1; i<k+1; i++)
         C[i]=C[i]+C[i-1];
     /*C(i)裡現在存著值≦i的個數*/
     for(j=A_length-1; j>-1; j--)
     {
         B[C[A[j]]-1]=A[j]; /*索引值是從0開始的*/
         C[A[j]]=C[A[j]]-1; /*假如所有值都有區別，則此行是不必要的*/
     }                      
     return B;
}
