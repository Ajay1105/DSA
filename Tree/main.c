#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *left;
struct node *right;
};

struct node * createNode(int data){
struct node * p =(struct node*)malloc(sizeof(struct node));
p->data= data;
p->left = NULL;
p->right = NULL;
return p;
}

void preorderTraversal(struct node * n){
if(n != NULL){
    printf("%d ",n->data);
    preorderTraversal(n->left);
    preorderTraversal(n->right);
}
}
void postorderTraversal(struct node * n){
if(n != NULL){
    postorderTraversal(n->left);
    postorderTraversal(n->right);
    printf("%d ",n->data);
}
}
void inorderTraversal(struct node * n){
if(n != NULL){
    inorderTraversal(n->left);
    printf("%d ",n->data);
    inorderTraversal(n->right);
}
}

int main()
{
struct node *n1= createNode(3);
struct node *n2= createNode(4);
struct node *n3= createNode(5);
struct node *n4= createNode(6);
struct node *n5= createNode(7);
(*n1).left=n2;
(*n1).right=n3;
n2->left= n4;
n3->right =n5;
preorderTraversal(n1);printf("\n");
postorderTraversal(n1);printf("\n");
inorderTraversal(n1);
    return 0;
}
