#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
void MAX_HEAPIFY(int[], int);
void BUILD_MAX_HEAP(int[]);
void HEAPSORT(int[]);
int heap_size;
int main(void)
{
     int i, Array[MAX+1]={-1};
     printf("排序前數列：");
     srand(time(NULL));
     for(i=1; i<=MAX; i++)
     {
           Array[i] = rand()%100; /*產生0~99的隨機變數*/
           printf("%d　", Array[i]);
     }
     printf("\n");
     
     printf("最大堆積樹：");
     BUILD_MAX_HEAP(Array);
     for(i=1; i<=MAX; i++)
           printf("%d　", Array[i]);
     printf("\n");
     
     printf("堆積排序後：");
     HEAPSORT(Array);
     for(i=1; i<=MAX; i++)
           printf("%d　", Array[i]);
     printf("\n");
     system("PAUSE");
     return 0;
}
//Run in O(lg(n)) time
//Maintain the max-heap property
void MAX_HEAPIFY(int A[], int i)
{
      int l = 2*i, r = 2*i+1, largest;
      
      if((l<=heap_size) && (A[l]>A[i]))
           largest = l;
      else
           largest = i;
      if((r<=heap_size) && (A[r]>A[largest]))
           largest = r;   
      if(largest!=i)
      {
            SWAP(A[i], A[largest]);
            MAX_HEAPIFY(A, largest);
      }
}
//Run in linear time
//Produce a max-heap from an unordered input array
void BUILD_MAX_HEAP(int A[])
{
      int i;
      heap_size = MAX;
      for(i=MAX/2; i>=1; i--)
           MAX_HEAPIFY(A, i);
}
//Run in O(nlg(n))time
//Sort an array in place
void HEAPSORT(int A[])
{
     BUILD_MAX_HEAP(A);
     int i;
     for(i = MAX; i>=2; i--)
     {
           SWAP(A[1], A[i]);
           heap_size-=1;
           MAX_HEAPIFY(A, 1);
     }
}
