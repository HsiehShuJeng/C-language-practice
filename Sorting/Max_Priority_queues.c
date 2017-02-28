#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
int heapsize;
int HeapMaximum(int[]);
int HeapExtractMax(int[]);
void HeapIncreaseKey(int[], int, int);
void MaxHeapInsert(int[], int);
/*The functions for a heap sort.*/
void MaxHeapify(int[], int);
void BuildMaxHeap(int[]);
int main(void)
{
    srand(time(NULL));
    int i; //A variable for for-loops.
    int number, selection;
    printf("Please type the numbers u wanna see in the array¡G");
    scanf("%d", &number);
    heapsize = number;
    int A[number+1];
    for(i=1; i<=number; i++)
        A[i] = rand()%100;
    BuildMaxHeap(A);
    printf("Please choose the option¡G\n");
    do
    {
        printf("(1)Extract (2)Increase the value of a key\n");
        printf("(3)Show (4)Insert (5)Exit¡G");
        scanf("%d", &selection);
        switch(selection)
        {
            int deleted_value, position, increasing_value;
            case 1:
                 deleted_value = HeapExtractMax(A);
                 printf("%d has been deleted¡I\n", deleted_value);
                 break;
            case 2:
                 printf("¡@Type the position¡G");
                 scanf("%d", &position);
                 printf("¡@Type the value(key)¡G");
                 scanf("%d", &increasing_value);
                 HeapIncreaseKey(A, position-1, increasing_value);
                 break;
            case 3:
                 for(i=1; i<=number; i++)
                 {
                     if(i!=number)
                         printf("%d¡B", A[i]);
                     else
                         printf("%d", A[i]);
                 }
                 printf("\n");
                 break;
            case 4:
                 break;
            case 5:
                 break;
        }
    }while(selection!=-1);
    system("PAUSE");
    return 0;
}
int HeapMaximum(int A[])
{
    return A[1];
}
int HeapExtractMax(int A[])
{
    //The running time of HeapExtractMax is O(lg(n)).
    if(heapsize < 1)
        printf("Heap underflow.\n");
    int max;
    max = A[1];
    A[1] = A[heapsize-1];
    MaxHeapify(A, 1);
    return max;
}
void HeapIncreaseKey(int A[], int i, int key)
{
     if(key < A[i])
         printf("The new key is smaller than current key.\n");
     A[i] = key;
     while((i > 1) && (A[i/2] < A[i]))
     {
         SWAP(A[i], A[i/2]);
         i = i/2;
     }
}
void MaxHeapInsert(int A[], int key)
{
    heapsize += 1;
    A[heapsize] = INT_MIN; //A[A.heap-size]= -¡Û
    HeapIncreaseKey(A, heapsize, key);
}
//Run in O(lg(n)) time
//Maintain the max-heap property
void MaxHeapify(int A[], int i)
{
      int l = 2*i, r = 2*i+1, largest;
      
      if((l<=heapsize) && (A[l]>A[i]))
           largest = l;
      else
           largest = i;
      if((r<=heapsize) && (A[r]>A[largest]))
           largest = r;   
      if(largest!=i)
      {
            SWAP(A[i], A[largest]);
            MaxHeapify(A, largest);
      }
}
void BuildMaxHeap(int A[])
{
      //Run in linear time
      //Produce a max-heap from an unordered input array
      int i;
      for(i=heapsize/2; i>=1; i--)
           MaxHeapify(A, i);
}
