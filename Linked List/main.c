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
printf("%d is inserted at the start of linked list\n",e);
return insert;
}

void search(struct Node*head,int e){
struct Node * temp = head;
 while(temp->data != e ){
  temp = temp->next;
  if(temp == NULL) break;
 }
 if(temp == NULL) printf("element not found!\n");
 else printf("element found\n");
}


struct Node* Insert_end(struct Node*ptr,int e){
struct Node * insert = (struct Node*) malloc(sizeof(struct Node));
insert->data =e;
insert->next = NULL;
insert->back = ptr;
ptr->next = insert;
printf("%d is inserted at the end of linked list\n",e);
return insert;
}

void Insert_in_between(struct Node * ptr,struct Node * ptr2,int e){
struct Node * insert = (struct Node*) malloc(sizeof(struct Node));
insert->data =e;
ptr->next =insert;
insert->next = ptr2;
insert->back = ptr;
printf("%d is inserted in between %d and %d in linked list\n",e,ptr->data,ptr2->data);
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
  int k;
  printf("Enter element to be searched: ");
  scanf("%d",&k);
search(head,k);

   return 0;
}
