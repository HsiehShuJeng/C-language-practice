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
    printf("�п�J�����ƥءG");
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
    printf("�p�ƱƧǫe�G");
    for(i=0; i<n; i++)
    {
        if(i!=n-1)
            printf("%d�A", A[i]);
        else
            printf("%d", A[i]);
    }
    printf("\n");
    B=COUNTING_SORT(A, B, 1000);
    printf("�p�ƱƧǫ�G");
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
     /*C[i]�̲{�b�s�ۭȵ���i���Ӽ�*/
     for(i=1; i<k+1; i++)
         C[i]=C[i]+C[i-1];
     /*C(i)�̲{�b�s�ۭȡ�i���Ӽ�*/
     for(j=A_length-1; j>-1; j--)
     {
         B[C[A[j]]-1]=A[j]; /*���ޭȬO�q0�}�l��*/
         C[A[j]]=C[A[j]]-1; /*���p�Ҧ��ȳ����ϧO�A�h����O�����n��*/
     }                      
     return B;
}
