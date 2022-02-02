#include <iostream>

using namespace std;

struct queue{
int size;
int front =-1;
int rear =-1;
int*arr;
};

int isfull(struct queue*q){
    if((q->rear+1)%q->size == q->front){
         return 1;
    }else{
        return 0;
    }
}

int isempty(struct queue* q){
 if(q->front == q->rear){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue* q, int val){
 if(isfull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->rear = (q->rear +1)%q->size;
        q->arr[q->rear] = val;
        printf("Enqueued element: %d\n", val);
}
}
void dequeue(struct queue* q){
if(isempty(q)){
        printf("This Queue is full\n");
    }
else{
    q->front = ((*q).front +1)%q->size;
    printf("%d is dequeued.\n", q->arr[(*q).front]);
    }
}

void peek(struct queue* q, int e){
cout << q->arr[e+1]<<endl;
}

int main()
{ struct queue* q = new struct queue;
q->size =10;
q->arr = new int[q->size];
if(isempty(q)){cout<< "Queue is empty"<<endl;}
enqueue(q , 9);enqueue(q , 8);enqueue(q , 7);enqueue(q , 6);enqueue(q , 5);enqueue(q , 4);enqueue(q , 3);enqueue(q , 2);enqueue(q , 1);enqueue(q , 0);
if(isfull(q)){cout<< "Queue is full"<<endl;}
dequeue(q);cout<< q->front<<endl;cout<<q->rear<<endl;
enqueue(q, 8);
    return 0;
}
