#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int array_length;
void INSERTION_SORT(int[]);
int main(void)
{
    int i, n;
    srand(time(NULL));
    printf("請輸入要排序多少個數字：");
    scanf("%d", &n);
    array_length=n;
    int *array = malloc(n*sizeof(int)); /*動態配置記憶體空間*/
    for(i=0; i<n; i++)
    {
          array[i]=(rand()%1000)+1; /*產生1~1000的隨機變數*/
    }
    printf("插入排序前：");
    for(i=0; i<n; i++)
    {
        printf("%d   ", array[i]);
    }
    printf("\n");
    INSERTION_SORT(array); /*插入排序*/
    printf("插入排序後：");
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
void INSERTION_SORT(int A[])
{
    int i, j, key;
    for(j=(array_length-2); j>-1; j--)
    {
        key = A[j];
        i=j+1;
        while((i<(array_length)) && (A[i]>key))
        {
            A[i-1] = A[i];
            i=i+1;
        }
        A[i-1]=key;
    }
}
