#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node * next;
struct Node * back;
};

struct Node* Insert(struct Node*ptr,int e){
struct Node * insert = (struct Node*) malloc(sizeof(struct Node));
insert->data =e;
insert->next = ptr;
insert->back = NULL;
ptr->back = insert;
return insert;
};

struct Node* Insert_end(struct Node*ptr,int e){
struct Node * insert = (struct Node*) malloc(sizeof(struct Node));
insert->data =e;
insert->next = NULL;
insert->back = ptr;
ptr->next = insert;
return insert;
};

void Insert_in_between(struct Node * ptr,struct Node * ptr2,int e){
struct Node * insert = (struct Node*) malloc(sizeof(struct Node));
insert->data =e;
ptr->next =insert;
insert->next = ptr2;
insert->back = ptr;
}

void display(struct Node * ptr){
while(ptr!=NULL){
    printf("display is running %d \n",ptr->data);
    ptr=ptr->next;
}
}

int main()
{struct Node * head = (struct Node*) malloc (sizeof(struct Node));
 struct Node * second = (struct Node*) malloc (sizeof(struct Node));
 struct Node * third = (struct Node*) malloc (sizeof(struct Node));
   head -> data = 2;
   head -> next = second;
   head -> back = NULL;
   second -> data = 3;
   second -> next = third;
   second ->  back = head;
   third -> data = 4;
   third -> next = NULL;
   third -> back = second;
   display(head);
   Insert_in_between(head,second,5);
   printf("display is called again\n");
   display(head);
   Insert_in_between(second,third,6);
   printf("display is called again\n");
   display(head);
   head = Insert(head,0);
   printf("display is called again\n");
   display(head);
   third = Insert_end(third,9);
   printf("display is called again\n");
   display(head);
   return 0;
}