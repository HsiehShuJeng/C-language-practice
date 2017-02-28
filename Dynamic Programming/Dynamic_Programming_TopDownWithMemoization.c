#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int MEMOIZED_CUT_ROD(int*, int);
int main()
{
    int result, choice = INT_MAX;
    int price[10]={1,5,8,9,10,17,17,20,24,30};
    do
    {
        if(choice==INT_MAX || (choice>=0 && choice<=10))
        {
            if(choice==INT_MAX)
            {
                printf("Enter the length of the rod¡G");
                scanf("%d", &choice);
            }
            else
            {
                result = CUT_ROD(price, choice);
                printf("The optimal revenue is %d\n", result);
                printf("Enter the length of the rod¡G");
                scanf("%d", &choice);
            }
        }
        else
        {
            if(choice<=0)
            {
                printf("No length of a rod is smaller than 0\nPlease re-enter¡G");
                scanf("%d", &choice);
            }
            else
            {
                printf("The length should be smaller than or equals to 10\nPlease re-enter¡G");
                scanf("%d", &choice);
            }
        }
    }while((choice<0 || choice>10)|| choice!=0);
    system("PAUSE");
    return 0;
}
int MEMOIZED_CUT_ROD(int* p, int n)
{
    int i, q, tmp, *r;
    if(n==0)
        return 0;
    q = INT_MIN;
    for(i=0; i<n; i++)
    {
        
        tmp = p[i]+CUT_ROD(p, n-i-1);
        if(q>=tmp)
            q=q;
        else
            q=tmp;
    }
    return q;
}
