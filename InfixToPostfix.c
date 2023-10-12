#include <stdio.h>

void push(char st[], char val, int *top, int l)
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

char pop(char st[], int *top, int l)
{
    char temp;
    if(*top==-1)
    {
        printf("Underflow\n");
        temp = '0';
    }
    else
    {
        temp = st[*top];
        (*top)--;
    }
    return temp;
}

void display(char st[], int top)
{
    while(top!=-1)
    {
        printf("%d\n",st[top]);
        top--;
    }
}

int isEmpty(int top)
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

int prec(char val)
{
    switch(val)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
    }
}

int main()
{
    char s[7] = "a+b*c-d";
    char ans[10];
    char sym[10];
    int l = 10, top=-1, i=0, j=0;
    while(i<7)
    {
        if(s[i]=='(')
        {
            push(sym, s[i], &top, l);
        }
        if(s[i]>='a' && s[i]<='z')
        {
            ans[j++] = s[i];
        }
        else
        {
            if(isEmpty(top))
            {
                push(sym, s[i], &top, l);
            }
            else
            {
                while(!(isEmpty(top)) && prec(s[i])<=prec(sym[top]))
                {
                    ans[j++] = pop(sym, &top, l);
                }
                push(sym, s[i], &top, l);
            }
        }
        i++;
    }
    while(!(isEmpty(top)))
    {
        ans[j++] = pop(sym, &top, l);
    }
    ans[j] = '\0';
    
    printf("%s\n", ans);
    return 0;
}
