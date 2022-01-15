#include <iostream>

using namespace std;

struct stack
{
    int size;
    int top;
    int * arr;
};

void push(struct stack *ptr,char e)
{
    ptr->arr[++ptr->top]=e;

}

void pop(struct stack *ptr, string b)
{
    char c;
    if (c!=b.at(ptr->top))
    {
        cout<<"is bad ";
        exit(0);
    }
    ptr->arr[ptr->top--];
}

int main()
{
    struct stack *s = new struct stack;
    s->size = 10;
    s->top =-1;
    s->arr = new int[3];
    string b;
    printf("Enter equation ");
    getline(cin,b);
    for(int i=0; i<b.length(); i++)
    {
        if(b.at(i)== '('||b.at(i)=='[' ||b.at(i)=='{')
        {
            push(s,b.at(i));
        }
        else if(b.at(i)== ')'||b.at(i)==']' ||b.at(i)=='}' )
        {
            pop(s,b);

        }
    }
int a= s->top;
     cout <<a;
    if(s->top== -1)
    {
        cout<<"is good\n";
    }
    else
    {
        cout<< "is bad\n";
    }
    return 0;

}
