#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SWAP(x,y){int t; t=x; x=y; y=t;}
void QUICKSORT(int[], int, int);
int PARTITION(int[], int, int);
int main(void)
{
    int i, n; /*n���x�s�ϥΪ̿�J�Ʀr�Ϊ��ܼ�*/
    srand(time(NULL));
    printf("�п�J�n�ƧǦh�֭ӼƦr�G");
    scanf("%d", &n);
    int *array = malloc(n*sizeof(int)); /*�ʺA�t�m�O����Ŷ�*/
    for(i=0; i<n; i++)
          array[i] = (rand() % 1000)+1 ; /*����1~1000���H���ܼ�*/          
    printf("�ֳt�Ƨǫe�G");
    for(i=0; i<n; i++)
    {
          printf("%d�@", array[i]);
    }
    printf("\n");
    QUICKSORT(array, 0, n-1); /*�ֳt�Ƨ�*/
    printf("�ֳt�Ƨǫ�G");
    for(i=0; i<n; i++)
    {
          if(i!=n-1)
               printf("%d < ", array[i]);
          else
               printf("%d", array[i]);
    }
    printf("\n");
    free(array);
    system("PAUSE");
    return 0;
}

void QUICKSORT(int A[], int p, int r)
{
     int q;
     if(p<r)
     {
           q = PARTITION(A, p, r);
           QUICKSORT(A, p, q-1);
           QUICKSORT(A, q+1, r);
     }
}
int PARTITION(int A[], int p, int r)
{
     int j, x = A[r], i = p-1;
     for( j=p; j<r; j++)
     { 
           if( A[j]<=x )
           {               
                 i+=1;
                 SWAP(A[i], A[j]);
           }
     }
     SWAP(A[i+1], A[r]);
     return i+1;
}
