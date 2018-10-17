#include<stdio.h>
#include<conio.h>
struct node
{
    int info;
    struct node *next;
};

struct node* start=NULL;
struct node* createnode()
{
    struct node * ptr=malloc(sizeof(struct node));
    ptr->next=NULL;
    return ptr;
}
// Add at last
void push(int data)
{
    struct node * previous_pointer,*next_pointer;
    struct node* ptr=createnode();
    ptr->info=data;
    if(start==NULL)
    {
        start=ptr;
        return;
    }
    next_pointer=start;
    while(next_pointer!=NULL)
    {
        previous_pointer=next_pointer;
        next_pointer=next_pointer->next;
    }
    previous_pointer->next=ptr;
}
void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        return;
    }
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->info);
        ptr=ptr->next;
    }
}

void pop()
{
    struct node* ptr;
    int d;
    if(start==NULL)
    {
        printf("Queue is empty\n");
        getchar();
        return;
    }
    ptr=start;
    d=start->info;
    start=start->next;
    free(ptr);
    printf("popped Element is\n%d",d);
    getchar();
}
void choice()
{
    int choice,data;
    while(1)
    {
        clrscr();
        printf("1.push\n2.pop\n3.display\n4.exit\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data\n");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            pop();
            getchar();
            break;
            case 3:
            display();
            getch();
            break;
            case 4: 
            exit(0);
            default:
            printf("Wrong choice\n");
        }
    }
}
int main()
{
    choice();
    getch();
    return 0;
}
