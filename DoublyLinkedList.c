#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

typedef struct node node;

void insertx(node** head, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->info = val;
    if(*head==NULL)
    {
        *head = temp;
        (*head)->prev = NULL;
        (*head)->next = NULL;
    }
    else
    {
        (*head)->prev = temp;
        temp->next = *head;
        *head = temp;
        temp->prev = NULL;
    }
}

void deletex(node** head)
{
    if(*head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        node* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        (*head)->prev = NULL;  
        printf("Deleted Value: %d\n", temp->info);
        free(temp);
    }
}

void display(node* head)
{
    while(head)
    {
        printf("%d ",head->info);
        head = head->next;
    }
}

int main()
{
    node* head = NULL;
    insertx(&head, 5);
    insertx(&head, 15);
    insertx(&head, 25);
    insertx(&head, 35);
    insertx(&head, 45);
    deletex(&head);
    printf("Displaying Values:\n");
    display(head);
    
    return 0;
}
