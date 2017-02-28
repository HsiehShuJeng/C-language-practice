/*singly linked list*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MALLOC(p, s)\
    if(!((p)=malloc(s)))\
    {\
        fprintf(stderr, "Insufficient memory¡I\n");\
        exit(EXIT_FAILURE);\
    }
typedef struct listNode* listPointer;
typedef struct listNode{
        int key;
        listPointer next;
        }singlylinkedlist;
listPointer first = NULL;
int delete_selection = 0;
listPointer CREATE(void);
void INSERT(listPointer*, listPointer, int);
void DELETE(listPointer*, listPointer);
void PRINTLIST(listPointer);
int LENGTH(listPointer);
listPointer Invert(listPointer);
int main(void)
{
    srand(time(NULL));
    int selection;
    do
    {
        printf(" (1)Create the first node\n");
        printf(" (2)Delete the node u want\n");
        printf(" (3)Insert the node u wish\n");
        printf(" (4)Show all of the values in the linked list\n");
        printf(" (5)Invert\n");
        printf(" (6)Exit\n");
        printf("Please select your chose¡G");
        scanf("%d", &selection);
        int i; //A variable for for-loop.
        int determinant = 0; //A variable for the function of inserting
        int insert_selection, insert_num, invert_selection;
        listPointer tmp, tmp2;
        switch(selection)
        {
            tmp = NULL; //For the process of deleting
            case 1:
                 if(!first)
                 {
                     first = CREATE();
                     printf("Create the node in which the value");
                     printf(" is %d\n", first->key);
                 }
                 else
                     printf("The node has existed¡I\n");
                 break;
            case 2:
                 printf("Which one?");
                 scanf("%d", &delete_selection);
                 for(i=1; i<delete_selection-1; i++)
                 {   /*Find out the node which precede the node 
                       that the user wanna delete.*/
                     tmp = first;
                     tmp = tmp->next;
                 }
                 tmp = first; //For the value of an option which is 1 or 2.
                 if(tmp) //If the node expected to be deleted exists.
                     DELETE(&first, tmp);
                 else //Not exit.
                 {
                     printf("The node u wanna exterminate doesn't exist.\n");
                     printf("Please choose with correctness.\n");
                 }
                 break;
            case 3:
                 do
                 {
                     if(determinant!=0)
                         printf("Enter the proper position¡I\n");
                     printf("Which position¡H");
                     scanf("%d", &insert_selection);
                     determinant++;
                 }while(insert_selection > LENGTH(first));
                 tmp = first;
                 for(i=1; i<insert_selection; i++)
                     tmp = tmp->next;
                 printf("The value¡G");
                 scanf("%d", &insert_num);
                 INSERT(&first, tmp, insert_num);
                 break;
            case 4:
                 PRINTLIST(first);
                 break;
            case 5:
                 printf("Enter the position¡G");
                 scanf("%d", &invert_selection);
                 tmp = first;
                 for(i=0; i<invert_selection; i++)
                     tmp = tmp->next;
                 printf("%d\n", tmp->key);
                 tmp2 = Invert(tmp);
                 printf("%d\n", tmp2->key);
                 break;
            case 6:
                 break;
            default:
                 printf("Please type the proper figure.\n");
                 break;
        }
    }while(selection!=-1);
    system("PAUSE");
    return 0;
}
listPointer CREATE()
{
    listPointer first;
    MALLOC(first, sizeof(*first));
    first->key = rand()%100;
    first->next = NULL;
    return first;
}
void INSERT(listPointer* first, listPointer x, int num)
{
     listPointer tmp;
     listPointer addition;
     MALLOC(addition, sizeof(*addition));
     addition->key = num;
     if((*first)!=NULL)
     {
         tmp = x->next;
         x->next = addition;
         addition->next = tmp;
     }
     else
     {
         addition->next = NULL;
         *first = addition;
     }
}
void DELETE(listPointer* first, listPointer trail)
{
    listPointer target;
    if((*first)==trail && delete_selection == 1)
        *first = (*first)->next;
    else
    {
        target = trail->next;
        trail->next = trail->next->next;
    }
    free(target);
}
void PRINTLIST(listPointer first)
{
    printf("The list contains¡G");
    for(; first; first = first->next)
        printf("%4d", first->key);
    printf("\n");
}
int LENGTH(listPointer ptr)
{/* Find the length of the list */
    listPointer temp;
    int size;
    size = 0;
    for (temp=ptr; temp; temp = temp->next)
        size++;
    return size;
}
listPointer Invert(listPointer lead)
{
    listPointer middle, trail;
    middle = NULL;
    while(lead)
    {
        trail = middle;
        middle = lead;
        lead = lead->next;
        middle->next = trail;
    }
    return middle;
}
