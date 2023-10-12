#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node node;

node* push(node* head, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->info = val;
    if(head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    
    return head;
}

node* pop(node* head)
{
    if(head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Popped Value: %d\n",head->info);
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    return head;
}

void display(node* head)
{
    while(head)
    {
        printf("%d ",head->info);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node* head = NULL;
    head = push(head, 5);
    head = push(head, 15);
    head = push(head, 25);
    head = push(head, 35);
    head = push(head, 45);
    head = pop(head);
    printf("Displaying Stack:\n");
    display(head);
}
