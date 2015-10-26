#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}node;

node* insert(node*,int);
node* delNode(node*);
void display(node*);

void main()
{
    node *head;
    head=NULL;
    int ch,op,num;
    do
    {
        printf("Menu\n1 INSERT\n2 DELETE nth NODE\n3 DISPLAY\n4 EXIT\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number to be inserted: ");
                    scanf("%d",&num);
                    head=insert(head,num);
                    break;
            case 2: head=delNode(head);
                    break;
            case 3: display(head);
                    break;
            case 4: exit(1);
                    break;
            default: printf("Wrong choice");
        }
        printf("\nPress 0 to continue: ");
        scanf("%d",&op);
    }
    while(op==0);
}

node* insert(node *head, int num)
{
    node *p,*temp;
    p=(node*)malloc(sizeof(node));
    p->info=num;
    p->next=NULL;
    if(head==NULL)
        head=p;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
    }
    return(head);
}

node* delNode(node* head)
{
    int n,i;
    node *temp,*p;
    temp=head;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d",&n);
    if(n!=1)
    {
        for(i=1;i<n-1;i++)
        {
            temp=temp->next;
            if(temp->next==NULL)
            {
                printf("Not enough nodes inserted.");
                return(head);
            }
        }
    p=temp->next;
    if(p->next==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        temp->next=p->next;
    }
    free(p);
    }
    else if(n==1)
    {
        head=head->next;
        free(temp);
    }
    return(head);
}

void display(node* head)
{
    while(head!=NULL)
    {
        printf("%2d",head->info);
        head=head->next;
    }
}
