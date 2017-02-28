#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
int heapsize;
int HeapMinimum(int[]);
int HeapExtractMin(int[]);
void HeapDecreaseKey(int[], int, int);
/*The functions for a heap sort.*/
void MinHeapify(int[], int);
void BuildMinHeap(int[]);
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
    BuildMinHeap(A);
    printf("Please choose the option¡G\n");
    do
    {
        printf("(1)Extract (2)Decrease the value of a key (3)Show (4)Exit¡G");
        scanf("%d", &selection);
        switch(selection)
        {
            int deleted_value, position, increasing_value;
            case 1:
                 deleted_value = HeapExtractMin(A);
                 printf("%d has been deleted¡I\n", deleted_value);
                 break;
            case 2:
                 printf("¡@Type the position¡G");
                 scanf("%d", &position);
                 printf("¡@Type the value(key)¡G");
                 scanf("%d", &increasing_value);
                 HeapDecreaseKey(A, position-1, increasing_value);
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
        }
    }while(selection!=-1);
    system("PAUSE");
    return 0;
}
int HeapMinimum(int A[])
{
    return A[1];
}
int HeapExtractMin(int A[])
{
    //The running time of HeapExtractMax is O(lg(n)).
    if(heapsize < 1)
        printf("Heap underflow.\n");
    int min;
    min = A[1];
    A[1] = A[heapsize-1];
    MinHeapify(A, 1);
    return min;
}
void HeapDecreaseKey(int A[], int i, int key)
{
     if(key > A[i])
         printf("The new key is larger than current key.\n");
     A[i] = key;
     while((i > 1) && (A[i/2] > A[i]))
     {
         SWAP(A[i], A[i/2]);
         i = i/2;
     }
}
//Run in O(lg(n)) time
//Maintain the max-heap property
void MinHeapify(int A[], int i)
{
      int l = 2*i, r = 2*i+1, smallest;
      if((l<=heapsize) && (A[l]<A[i]))
           smallest = l;
      else
           smallest = i;
      if((r<=heapsize) && (A[r]<A[smallest]))
           smallest = r;
      if(smallest!=i)
      {
            SWAP(A[i], A[smallest]);
            MinHeapify(A, smallest);
      }
}
void BuildMinHeap(int A[])
{
      //Run in linear time
      //Produce a max-heap from an unordered input array
      int i;
      for(i=heapsize/2; i>=1; i--)
           MinHeapify(A, i);
}
