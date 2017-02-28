#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SWAP(x,y){int t; t=x; x=y; y=t;}
void QUICKSORT(int[], int, int);
int PARTITION(int[], int, int);
int main(void)
{
    int i, n; /*n為儲存使用者輸入數字用的變數*/
    srand(time(NULL));
    printf("請輸入要排序多少個數字：");
    scanf("%d", &n);
    int *array = malloc(n*sizeof(int)); /*動態配置記憶體空間*/
    for(i=0; i<n; i++)
          array[i] = (rand() % 1000)+1 ; /*產生1~1000的隨機變數*/          
    printf("快速排序前：");
    for(i=0; i<n; i++)
    {
          printf("%d　", array[i]);
    }
    printf("\n");
    QUICKSORT(array, 0, n-1); /*快速排序*/
    printf("快速排序後：");
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
