#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

typedef struct node node;

void insertx(node** head, node** last, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->info = val;
    if(*head==NULL)
    {
        *head = temp;
        *last = temp;
        (*head)->prev = temp;
        (*head)->next = temp;
    }
    else
    {
        (*last)->next = temp;
        temp->prev = *last;
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

void deletex(node** head, node** last)
{
    if(*head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        node* temp = *head;
        *head = (*head)->next;
        (*last)->next = *head;
        (*head)->prev = *last;
        temp->next = NULL;
        temp->prev = NULL;
        printf("Deleted Value: %d\n", temp->info);
        free(temp);
    }
}

void display(node* head, node* last)
{
    while(head!=last)
    {
        printf("%d ",head->info);
        head = head->next;
    }
    printf("%d\n",head->info);
}

int main()
{
    node* head = NULL, *last = NULL;
    insertx(&head, &last, 5);
    insertx(&head, &last, 15);
    insertx(&head, &last, 25);
    insertx(&head, &last, 35);
    insertx(&head, &last, 45);
    deletex(&head, &last);
    printf("Displaying Values:\n");
    display(head, last);
    
    return 0;
}
