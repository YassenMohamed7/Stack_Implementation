#include <iostream>

using namespace std;


typedef int stackEntry;
struct stackNode
{
    stackEntry entry;
    struct stackNode *next;
};
struct stack
{
    stackNode *top;
    int Size;
};
void createStack(stack *ps);
void push(stackEntry e, stack *ps);
stackEntry pop(stack *ps);
int stackFull(stack *ps);
int stackEmpty(stack *ps);
void clearStack(stack *ps);
int stackSize(stack *ps);
void displayStack(stack *ps);
stackEntry stackTop(stack *ps);


int main()
{
    stack s;
    createStack(&s);
    for(int i = 1; i <= 10; i++)
    {
        push(i,&s);
    }
    displayStack(&s);   
    cout << endl;
    cout<<"Stack size = "<<stackSize(&s)<<endl;
    cout<<"top element of the stack = "<<stackTop(&s)<<endl;
    if(stackFull(&s))
        cout << "stack is full\n";
        else
        cout << "stack is not full\n";
    if(stackEmpty(&s))
    cout << "stack is empty\n";
    else
    cout << "stack is not empty\n";
    cout << endl;
    for(int i = 1 ; i <= 10 ; i++)
    {
        cout<<pop(&s)<<endl ; 
    }
    cout<<"Stack size = "<<stackSize(&s)<<endl;
    return 0;
}

void createStack(stack *ps)
{
    ps->top = NULL;
    ps->Size = 0;
}
void push(stackEntry e , stack *ps)
{
    stackNode *pn = new stackNode;
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->Size++;
}
stackEntry pop(stack *ps)
{
    stackNode *pn;
    stackEntry data;
    data = ps->top->entry;
    pn = ps->top;
    ps->top = ps->top->next;
    ps->Size--;
    delete pn;
    return data;
}
int stackEmpty(stack *ps)
{
    return ps->top == NULL;
}
int stackFull(stack *ps)
{
    return 0;    // stack is always not full
}
void clearStack(stack *ps)
{
    stackNode *pn;
    pn = ps->top;
    while(pn)
    {
        pn = pn ->next;
        delete ps->top;
        ps->top = pn;
    }
    ps->Size = 0;
}
int stackSize(stack *ps)
{
    return ps->Size;
}
void displayStack(stack *ps)
{
    stackNode *pn;
    pn = ps->top;
    while(pn)
    {
        cout << pn->entry << endl;
        pn = pn->next;
    }
}
stackEntry stackTop(stack *ps)
{
    if(ps->top)
    return ps->top->entry;
    else
      cout << "Stack is empty";
}

