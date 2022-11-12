/*
2.  Design a data structure to maintain a set S of n distinct integers 
    that supports the following two operations:
        a) INSERT(x, S): insert integer x into S
        b) REMOVE(S): remove the smallest n/2 integers from S.
        c) Write a program by using UDFs that give the worse-case time
        complexity of the two operations INSERT(x, S) in O(1) time and
        REMOVE-BOTTOM-HALF(S) in O(n) time.
*/

#include<stdio.h>
#include<stdlib.h>

int n=0;
struct node{
    int val;
    struct node *next;
};

void insert_node(struct node **h, int data)
{
    struct node *curr,*ptr,*prv;
    curr=malloc(sizeof(struct node));
    curr->val=data;
    curr->next=NULL;

    if(*h==NULL || curr->val<((*h)->val)){
        curr->next=*h;
        *h=curr;
    }
    else
    {
        ptr=*h;
        while(ptr->next!=NULL && curr->val>ptr->next->val)
        {
            ptr=ptr->next;
        }
        curr->next=ptr->next;
        ptr->next=curr;
    }
    n++;
}

void remove_nodes(struct node **h)
{
    int i=1;
    struct node *ptr;

    if(*h==NULL)
        printf("EMPTY!\n");
    else
    {
        ptr=*h;
        while(i<(n/2))
        {
            ptr=ptr->next;
            i++;
        }
        *h=ptr->next;
        free(ptr);
    }
}

void display_nodes(struct node *h)
{
    printf("Nodes Created: ");
    while(h->next!=NULL)
    {
        printf(" %d ->",h->val);
        h=h->next;
    }
    printf(" %d",h->val);
    printf("\n");
}


void main()
{
    int val;
    struct node * head = NULL;
    int choice=1;
    while (choice!=0)
    {
        printf("\n 0.To exit\n 1.To Insert Element\n 2.Remove smallest n/2 integers\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                choice=0;
                printf("\n\nExiting...\n");
                break;
            case 1:
                printf("Enter node value: ");
                scanf("%d",&val);
                insert_node(&head,val);
                printf("\nAfter Operation:\n");
                display_nodes(head);
                break;
            case 2:
                display_nodes(head);
                remove_nodes(&head);
                printf("\nAfter Operation:\n");
                display_nodes(head);
                break;
            default:
                printf("Enter valid option !!!");
                break;
        }
    }
}