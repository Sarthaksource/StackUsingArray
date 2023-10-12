#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
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
        temp->next = *head;
        *last = temp;
    }
    else
    {
        (*last)->next = temp;
        temp->next = *head;
        *last = temp;
    }
}

void deletex(node** head, node** last)
{
    node* temp = *head;
    while(temp->next!=*last)
    {
        temp = temp->next;
    }
    temp->next = (*last)->next;
    (*last)->next = NULL;
    printf("Deleted Value: %d\n",(*last)->info);
    free(*last);
    *last = temp;
}

void display(node *head, node* last)
{
    while(head!=last)
    {
        printf("%d ",head->info);
        head = head->next;
    }
    printf("%d ",head->info);
}

int main()
{
    node* head = NULL;
    node* last = NULL;
    insertx(&head, &last, 5);
    insertx(&head, &last, 15);
    insertx(&head, &last, 25);
    insertx(&head, &last, 35);
    insertx(&head, &last, 45);
    deletex(&head, &last);
    printf("Displaying Values: \n");
    display(head, last);
    
    return 0;
}
