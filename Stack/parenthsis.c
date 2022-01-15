#include <stdio.h>
#include <stdlib.h>


struct stack{
int size;
int top;
char * arr[];};

void push(struct stack *ptr,char e){
ptr->arr[++ptr->top]=e;}

void pop(struct stack *ptr){
ptr->arr[ptr->top--];}

int main(){
struct stack *s = (struct stack*)malloc(sizeof(struct stack));
s->size = 10;
s->top =-1;
s->arr[5] = (char*)malloc(sizeof(char));
s->arr[5]='(','a','+','b','(';
printf("%c\n",s->arr[0]);
for(int i=0;i<4;i++){
    if(s->arr[i]='('){push(s,')');printf("push\n");}
    if(s->arr[i]=')'){pop(s);printf("pop\n");}
}

if(s->top== -1){printf("is good\n");}
  else{ printf( "is bad\n"); }
    return 0;}



