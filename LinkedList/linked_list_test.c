/*
    Test drive for Linked List implementation
*/

#include <stdio.h>


void Tst_LinkedList(void);

int main(){


    Tst_LinkedList();



    return 0;
}


typedef struct LinkedList_NodeStruct
{
    struct LinkedList_NodeStruct* prev;
    struct LinkedList_NodeStruct* next;
    int val;
}LinkedList_Node;


typedef struct 
{
   LinkedList_Node *head;
}LinkedList;

LinkedList_Node* LL_Search(LinkedList *plist, int k);
void LL_Remove(LinkedList *plist, LinkedList_Node *pnode);
void LL_Insert(LinkedList* plist, LinkedList_Node *pnode);

void LL_Printall(LinkedList* plist);

#define LL_NODE_MAX_NUM 10

void Tst_LinkedList(void)
{
    int i;
    LinkedList_Node node[LL_NODE_MAX_NUM];
    LinkedList list = {NULL};
    for (i = 0; i < LL_NODE_MAX_NUM; ++i)
    {
        node[i].val = i*11;
        LL_Insert (&list, &node[i]);
    }

    LL_Printall(&list);

    {

        LinkedList_Node *pnode_found;
        printf("\n\nTest for LL_Search()\n");
        pnode_found = LL_Search(&list, 33);
        if (pnode_found != NULL)
        {
            printf("Node Found for 33: %d\n", pnode_found->val);
        }
        else
        {
            printf("Node Not Found for 33\n");
            
        }        
        pnode_found = LL_Search(&list, 333);

        if (pnode_found != NULL)
        {
            printf("Node Found for 333: %d\n", pnode_found->val);
        }
        else
        {
            printf("Node Not Found for 333\n");
            
        }
        
        printf("\n***Before node removal\n");
        LL_Printall(&list);

        pnode_found = LL_Search(&list, 44);
        LL_Remove(&list, pnode_found);

        printf("\n***After node removal\n");
        LL_Printall(&list);
    }    

}


/* lesson learned: maintain the prev, next and the list all the time for any modification! */
void LL_Insert(LinkedList* plist, LinkedList_Node *pnode)
{
    if ((pnode != NULL) && (plist != NULL))
    {
        
        pnode->next = plist->head;

        if (plist->head != NULL)
        {
            plist->head->prev = pnode;
        }

        plist->head = pnode;
        pnode->prev = NULL;
    }
}


LinkedList_Node* LL_Search(LinkedList *plist, int k)
{
    LinkedList_Node *pnode;

    if (plist != NULL)
    {
        pnode = plist->head;

        //leason learned: exit condition right at the while loop condition, instead of break at the exit condition inside the loop
        while( (pnode != NULL) && (pnode->val != k) ) 
        {
            pnode = pnode->next;
        }
    }

    return pnode;
}

void LL_Remove(LinkedList *plist, LinkedList_Node *pnode)
{
    if ((pnode != NULL) && (plist != NULL))
    {
        if ( (pnode != plist->head) )
        {
            pnode->prev->next = pnode->next;
        }
        else
        {
            plist->head = pnode->next;
        }

        if (pnode->next != NULL)
        {
            pnode->next->prev = pnode->prev;
        }
    }

}

void LL_Printall(LinkedList* plist)
{
    LinkedList_Node *pnode = plist->head;

    printf("Linked List: \n");
    while( pnode != NULL )
    {
        printf("%d\n", pnode->val);
        pnode = pnode->next;
    }
}
