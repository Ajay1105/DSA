#include <iostream>

using namespace std;

struct stack{
int size;
int top;
char * arr;};

void push(struct stack *ptr,char e){
ptr->arr[++ptr->top]=e;}

void pop(struct stack *ptr){
ptr->arr[ptr->top--];}

int main(){
struct stack *s = new struct stack;
s->size = 10;
s->top =-1;
s->arr = new char[3];
string b;printf("Enter equation "); getline(cin,b);
for(int i=0;i<b.length();i++){
    if(b.at(i)== '(' ){push(s,b.at(i));}
    else if(b.at(i)== ')' ){pop(s);}
} if(s->top== -1){cout<<"is good\n";}
  else{ cout<< "is bad\n"; }
    return 0;}
