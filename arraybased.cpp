#include <iostream>

using namespace std;

typedef enum
{
     TOP_INIT = -1,
     EMPTY = 0 ,
     FULL  = 100
}StackStatus;
typedef int stackEntry ;
struct stack
{
    int top = TOP_INIT;
    stackEntry entry[FULL] = {0} ;
};
void createStack(stack *ps);
int stackFull(stack *ps);
void push(stackEntry element, stack *ps);
int stackEmpty(stack *ps);
stackEntry pop(stack *ps);
stackEntry stackTop(stack *ps);
int stackSize(stack *ps);
void clearStack(stack *ps);
void displayStack(stack *ps) ;

int main()
{
    stack s;
    createStack(&s);
    for(int i = 1 ; i <= 10 ; i++)
    {
        push(i,&s) ;
    }
    displayStack(&s);    
    cout<< endl;
    cout<<"Stack size = "<<stackSize(&s)<<endl ;
    cout<<"top element of the stack = "<<stackTop(&s)<<endl ;
    if(stackFull(&s))
        cout << "stack is full\n";
        else
        cout << "stack is not full\n";
    if(stackEmpty(&s))
    cout << "stack is empty\n";
    else
    cout << "stack is not empty\n";
    cout<< endl;
    for(int i = 1 ; i <= 10 ; i++)
    {
        cout<<pop(&s)<<endl ;
    }
    cout<<"\n###########################\n";
    cout<<"Stack size = "<<stackSize(&s)<<endl ;
    cout<<"top element of the stack = "<<stackTop(&s)<<endl;
    if(stackFull(&s))
        cout << "stack is full\n";
        else
        cout << "stack is not full\n";
    if(stackEmpty(&s))
    cout << "stack is empty\n";
    else
    cout << "stack is not empty\n";
    return 0;
}


void createStack(stack *ps)
{
    ps->top = TOP_INIT;
}
int stackFull(stack *ps)
{
    return (ps->top >=FULL);

}
void push(stackEntry element, stack *ps)
{
    if(!(stackFull(ps)))
        (ps->entry[++(ps->top)] = element);
}
int stackEmpty(stack *ps)
{
    return (ps->top == TOP_INIT);
}
stackEntry pop(stack *ps)
{

    if(!(stackEmpty(ps)))
        return (ps->entry[(ps->top)--]);
    else
        cout<<"Stack is empty\n" ;

/** pop function delete the element from the stack
    virtually but it is still stored in the array **/
}
stackEntry stackTop(stack *ps)
{
    return (ps->entry[ps->top]);
}

int stackSize(stack *ps)
{
    return (ps->top + 1);
}


void clearStack(stack *ps)
{
    ps->top = TOP_INIT;
}

void displayStack(stack *ps)
{

    for(int i = ps->top ; i > -1 ; --i )
        cout<<ps->entry[i]<<endl;
    return ;
}

