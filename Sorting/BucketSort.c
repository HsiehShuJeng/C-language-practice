#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void BUCKET_SORT(double* A);
typedef struct bucket
{
    double storage;
    struct bucket* next;
}BUCKET;
BUCKET** B; //An auxiliary array of linked list.
int total_number;
int LENGTH(BUCKET*);
int main(void)
{
    srand(time(NULL));
    int i, n;
    printf("請輸入個數：");
    scanf("%d", &n);
    total_number = n; //Let a global variable receive the size of the array.
    double* array=(double*)malloc(n*sizeof(double));
    for(i=0; i<n; i++)
        array[i]=(rand()%100)/100;
    BUCKET_SORT(array);
    BUCKET* tmp;
    for(tmp = B[0]; tmp; tmp=tmp->next)
    {
        printf("%lf\n", tmp->storage);
    }
    system("PAUSE");
    return 0;
}
void BUCKET_SORT(double* A)
{
    B = (BUCKET**)malloc(total_number*sizeof(BUCKET*));
    int i=0; //A for-loop variable
    for(i=0; i<=total_number-1; i++)
        B[i] = NULL;
    for(i=0; i<=total_number-1; i++)
    {//Insert A[i] into list B[n*A[i]]
        BUCKET* tmp;
        BUCKET* addition;
        addition = (BUCKET*)malloc(sizeof(*addition));
        addition->storage = A[i];
        addition->next = NULL;
        if(B[(int)(total_number*A[i])]!=NULL)
        {
            tmp = B[(int)(total_number*A[i])];
            /*To find a position in which its pointer to next position
              is empty (null).*/
            for(;tmp!=NULL; )
                tmp = tmp->next;
            tmp->next = addition;
        }
        else
        {
            tmp = B[((int)total_number*A[i])];
            tmp->next = addition;
        }        
    }
    for(i=0; i<=total_number-1; i++)
    {/*Sort list B[i] with insertion sort*/
        int length = LENGTH(B[i]);
        int j, k, l=1; //A for-loop variable
        BUCKET* temp, record;
        temp = B[i];
        for(j=2; j<=length; j++)
        {
            for(l; l<j; l++)
                temp=temp->next;
            double key = temp->storage;
            k = j-1;
            temp = B[i];
            for(l=1; l<k; l++)
                temp=temp->next;
            while(k>0 && temp->storage > key)
            {
                /*A[i+1] = A[i](Insertion Sort)*/
                record = temp;
                temp = temp->next;
                temp->storage = record->storage;
                /*i = i -1(Insertion Sort)*/
                k-=1;
            }
            temp = B[i];
            for(l=1; l<k; l++)
                temp=temp->next;
            temp->storage = key;     
        }
    }
    /*Concatenate the list B[0], B[1],..., B[n-1] together in order.*/
    BUCKET* for_concatenation
    int m = 0; //A variable represents the index of an array B of linked list
    if(m!=total_number)
    {
        B[m++]= for_concatenation;
        for(;for_concatenation!=null;)
            for_concatenation = for_concatenation->next;
        for_concatenation = B[m];
    }
}
int LENGTH(BUCKET* ptr)
{
    BUCKET* tmp;
    int size;
    size = 0;
    for(temp = ptr; temp; temp = temp->next)
        size++;
    return size;
}
