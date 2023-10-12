#include <stdio.h>

void push(int st[], int val, int *top, int l)
{
    if(*top>=l-1)
    {
        printf("Overflow\n");
    }
    else
    {
        (*top)++;
        st[*top] = val;
    }
}

int pop(int st[], int *top, int l)
{
    int temp = 0;
    if(*top==-1)
    {
        printf("Underflow\n");
        temp = -1;
    }
    else
    {
        temp = st[*top];
        (*top)--;
    }
    return temp;
}

void display(int st[], int top)
{
    while(top!=-1)
    {
        printf("%d\n",st[top]);
        top--;
    }
}

int main()
{
    int st[5];
    int l = 5, top=-1;
    push(st, 5, &top, l);
    push(st, 10, &top, l);
    push(st, 15, &top, l);
    push(st, 20, &top, l);
    push(st, 25, &top, l);
    push(st, 30, &top, l);
    printf("Popped Value: %d\n", pop(st, &top, l));
    printf("Displaying Stack:\n");
    display(st, top);

    return 0;
}
