#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;
node *create_node(int data);
void display();
int mid();
void add_first(int data);

int main()
{
int data,result;
// create_node(11);
//create_node(22);
//create_node(33);
// printf("Enter the data:");
// scanf("%d",&data);
add_first(10);
add_first(20);
add_first(30);
add_first(40);
add_first(50);
display();
result = mid();
printf("mid element is = %d",result);
return 0;

}

node *create_node(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("malloc is failed!\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
    }
    return ptr;
}

void display()
{
    node *trav = head;
    if(head == NULL)
    {
        printf("list is empty!");
    }
    while(trav!=NULL)
    {
        printf("%4d",trav->data);
        trav = trav->next;
    }
}
int mid()
{
    // node* ptr = create_node(data);
    node *slow = head;
    node *fast = head;
    
    while(fast!= NULL && fast->next->next!= head)
    {
        slow = slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

void add_first(int data)
{
    node *ptr = create_node(data);
    if (head==NULL)
    {
       // ptr = head;
        head = ptr;
    }
    else
    {
       // node* ptr = create_node(data);
        //node* temp = head;
        node *trav=head;
        while(trav->next!=NULL)
        {
            trav = trav->next;
        }
        ptr->next = head;
        head=ptr;
    }
    
}
