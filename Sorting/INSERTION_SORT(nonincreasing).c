#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int array_length;
void INSERTION_SORT(int[]);
int main(void)
{
    int i, n;
    srand(time(NULL));
    printf("�п�J�n�ƧǦh�֭ӼƦr�G");
    scanf("%d", &n);
    array_length=n;
    int *array = malloc(n*sizeof(int)); /*�ʺA�t�m�O����Ŷ�*/
    for(i=0; i<n; i++)
    {
          array[i]=(rand()%1000)+1; /*����1~1000���H���ܼ�*/
    }
    printf("���J�Ƨǫe�G");
    for(i=0; i<n; i++)
    {
        printf("%d   ", array[i]);
    }
    printf("\n");
    INSERTION_SORT(array); /*���J�Ƨ�*/
    printf("���J�Ƨǫ�G");
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
