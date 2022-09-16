#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node * next;
};

void display(struct Node * ptr){
while(ptr!=NULL){
    printf("display is running %d \n",ptr->data);
    ptr=ptr->next;
}
}

void delete(struct Node * ptr){
ptr->data = ptr->next->data;
ptr->next = ptr->next->next;
free(ptr->next);
}

void main()
{
 struct Node * head = (struct Node*) malloc (sizeof(struct Node));
 struct Node * second = (struct Node*) malloc (sizeof(struct Node));
 struct Node * third = (struct Node*) malloc (sizeof(struct Node));
 struct Node * fourth = (struct Node*) malloc (sizeof(struct Node));
   head -> data = 2;
   head -> next = second;
   second -> data = 3;
   second -> next = third;
   third -> data = 4;
   third -> next = fourth;
   fourth->data = 5;
   fourth->next = NULL;
   display(head);
   delete(third);
   printf("\nAfter delete:\n");
   display(head);
}
