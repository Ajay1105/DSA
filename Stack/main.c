#include <stdio.h>
#include <stdlib.h>

struct stack{
int size;
int top;
int * arr;};

void push(struct stack *ptr,int e){
printf("%d is pushed in the stack\n",e);
ptr->arr[++ptr->top]=e;}

void pop(struct stack *ptr){
printf("%d is poped out of the stack\n",ptr->arr[ptr->top]);
ptr->arr[ptr->top--];}

void peek(struct stack* ptr, int i){
printf("%d ",ptr->arr[ptr->top-i+1]);}

int main(){
struct stack *s = (struct stack*)malloc(sizeof(struct stack));
s->size = 10;
s->top =-1;
s->arr = (int*)malloc(s->size*sizeof(int));
push(s,2);push(s,3);push(s,4);
pop(s);
push(s,5);push(s,6);push(s,7);push(s,8);push(s,9);
printf("%d\n",s->top);
for(int i=1;i<=s->top+1;i++){
peek(s,i);}
 return 0;
}
