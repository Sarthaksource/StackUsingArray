#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node node;

void enqueue(node** front, node** rear, int val)
{
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Overflow\n");
    }
    temp->info = val;
    if(*front == NULL)
    {
        temp->next = NULL;
        *front = temp;
        *rear = temp;
    }
    else
    {
        (*rear)->next = temp;
        *rear = temp;
        temp->next = NULL;
    }
}

void dequeue(node** front, node** rear)
{
    int val;
    if(*front == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        if((*front)->next == NULL)
        {
            val = (*front)->info;
            *front = NULL;
            *rear = NULL;
        }
        else
        {
            val = (*front)->info;
            node* temp = *front;
            *front = (*front)->next;
            temp->next = NULL;
            free(temp);
        }
        printf("Popped Value: %d\n",val);
    }
}

void display(node* front, node* rear)
{
    while(front!= rear)
    {
        printf("%d ",front->info);
        front = front->next;
    }
    printf("%d\n",front->info);
}

int main()
{
    node* front = NULL, *rear = NULL;
    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 15);
    enqueue(&front, &rear, 25);
    enqueue(&front, &rear, 35);
    enqueue(&front, &rear, 45);
    dequeue(&front, &rear);
    printf("Displaying Stack:\n");
    display(front, rear);
}
