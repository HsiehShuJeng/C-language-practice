#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<limits.h>
void MERGE_SORT(int[], int, int);
void MERGE(int[], int, int, int);
int main(void)
{
    int i, n;
    srand(time(NULL));
    printf("�п�J�n�ƧǦh�֭ӼƦr�G");
    scanf("%d", &n);
    int *array = malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        array[i]=(rand()%1000)+1;
    }
    printf("�X�ֱƧǫe�G");
    for(i=0; i<n; i++)
    {
        printf("%d   ", array[i]);
    }
    printf("\n");
    MERGE_SORT(array, 0, n-1); /*�X�ֱƧ�*/
    printf("�X�ֱƧǫ�G");
    for(i=0; i<n; i++)
    {
        if(i!=n-1)
            printf("%d > ", array[i]);
        else
            printf("%d", array[i]); 
    }
    printf("\n");
    
    system("PAUSE");
    return 0;
}
void MERGE(int A[], int p, int q, int r)
{
     int i, j, k; /*�j����ܼ�*/
     int number1 = q-p+1, number2 = r-q;
     int L[number1+1], R[number2+1];
     for(i=0; i<number1; i++)
         L[i]=A[p+i]; /*���b����*/
     for(j=0; j<number2; j++)
         R[j]=A[q+j+1]; /*�k�b����*/
     L[number1]=INT_MIN; /*�Mincreasing���*/
     R[number2]=INT_MIN; /*�Mincreasing���*/ 
     i=0;
     j=0;
     for(k=p; k<=r; k++)
     {
         /*�Mincreasing���*/
         if(L[i]>R[j])
         {
             A[k]=L[i];
             i+=1;
         }
         else
         {
             A[k]=R[j];
             j+=1;
         }
     }
}
void MERGE_SORT(int A[], int p, int r)
{
    int q;
    if(p < r)
    {
        q=((p+r)/2);
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q+1, r);
        MERGE(A, p, q, r);
    }
}
