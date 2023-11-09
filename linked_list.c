#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
 struct node* head = NULL;
 struct node* create_node(int data);
 void add_first(int data);
 void add_last(int data);
 void display();
 void add_specific(int data,int pos);
 int count_node();
 void del_first(int data);
 void del_last(int data);



int main()
{
 int data,pos,choice;
 //printf("Enter the data:\n");
 //scanf("%d",&data);
 do{
 printf("\n0.exit\n1.add first\n2.add last\n3.add_specific position\n4.del_first\n5.del_last\n");
 printf("Enter the choice:\n");
 scanf("%d",&choice);
 switch(choice)
 {
    case 0: exit(0);

    case 1:
            printf("\nEnter the data:");
            scanf("%d",&data);
            add_first(data);
            display();
            break;
    case 2:
            printf("\nEnter the data:");
            scanf("%d",&data);
            add_last(data);
            display();
            break;
    case 3: 
            printf("Enter the position:\n");
            scanf("%d",&pos);
            add_specific(data,pos);
            display();
            break;
    case 4:
            printf("Enter the position:\n");
            scanf("%d",&pos);
            del_first(data);
            display();
            break;
    case 5:
            printf("Enter the position:\n");
            scanf("%d",&pos);
            del_last(data);
            display();
            break;
                     
    default:
            printf("Please enter the specific positions only!\n");


}

}while(choice != 0);
}

struct node* create_node(int data)
 {
    //here we created the
    //ptr = new node
struct node* ptr = (struct node*)malloc(sizeof(struct node));
if(ptr == NULL)
    printf("malloc is failed!\n");
else
{
    ptr -> data = data;
    ptr -> next = NULL;
}return ptr;
 }

 void add_first(int data)
 {//1] checked first conditon
 struct node* ptr = create_node(data);

 if(head == NULL)
    {
        head = ptr;
    }
 else
    {
        //2] second condition
        //created new connection with the new node
        ptr -> next = head;
        head = ptr;
    }
 }
 

 void add_last(int data)
 {
struct node* ptr = create_node(data);
//first condition when the head is empty
if(head == NULL)
{
    head = ptr;
}
else
{   struct node* trav = head;
    while(trav->next!= NULL)
    {
    //second condition if list is completed
     trav = trav->next; 
    }trav->next = ptr;
}
 }
 //
void add_specific(int data,int pos)
 {
if(head == NULL)
 {   if(pos==1)
    {
        add_first(data);
    }
    else    
       printf("list is empty!\n");
 }
else if (pos == 1)
{
    add_first(data);
}
else if(pos < 1 || pos > count_node()+1)
{
    printf("Invalid position!\n");
}
else
{
    struct node* ptr= create_node(data);
    struct node *trav = head;
    for(int i=1;i<pos-1;i++)
    {
        trav = trav->next;
    }
    ptr->next = trav->next;
    trav->next = ptr;
}
}
 
 //
 void display()
 {
 if(head == NULL)
    printf("list is empty!\n");
 else
 {
    struct node* trav = head;
    while(trav!=NULL)
    {
        //trav->data = data;
        printf("->%d\n",trav->data);
        trav = trav->next;
    }
 }
 //printf("/n");
 }

int count_node()
{
int count = 0;
if(head == NULL)
{
    printf("list is empty!");
}
else
{
   struct node* trav = head;
    while(trav!=NULL)
    {
     count++;
     trav = trav->next; 
    }
}
return count;
}

void del_first(int data)
{
    if(head == NULL)
    printf("list is empty!");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node* temp = head;
        temp = head;
        head = head->next;
        free(temp);

    }
}

    void del_last(int data)
    {
        if(head == NULL)
            printf("lis is empty!");
        else if(head->next == NULL)
        {
            free(head);
            head = NULL;

        }
        else 
        {
            struct node* temp = head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            if(temp->next->next==NULL)
            {
                free(temp->next);
                temp->next=NULL;
            }

        }
    }




