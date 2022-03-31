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

int checkBST(struct node *root){
static struct node* prev = NULL;
if(root!= NULL){
    if(!checkBST(root->left)){
        return 0;
    }
    if(prev != NULL && root->data < prev->data){
        return 0;
    }
        prev = root;
       return checkBST(root->right);
}
else{
    return 1;
}
}

int searchBST(struct node*root, int key){
if(root == NULL){return 0;}
if(root->data==key){ return 1;}
if(root->data > key){ searchBST(root->left,key);}
if(root->data < key){ searchBST(root->right,key);}
}

void insertBST(struct node *root, int key){
struct node *prev = NULL;
while(root!=NULL){
prev = root;
if(key==root->data){printf("Cannot insert %d, already in BST", key);return;       }
else if(key<root->data){root = root->left;}
else{root = root->right;       }
}
struct node* new = createNode(key);
if(key<prev->data){prev->left = new;}
else{prev->right = new;}
}

/*void insertBST(struct node*root, int key){
struct node * prev = NULL;
while(root!= NULL){
        prev = root;
    if(root->data == key) {return;}
    else if(root->data > key){ root = root->left;}
    else if(root->data < key){ root = root->right;}
}
struct node * n = createNode(key);
if(n->data > key){ prev->left= n;}
else if(n->data < key){ prev->right= n;}
}*/

int main()
{
struct node *n1= createNode(5);
struct node *n2= createNode(4);
struct node *n3= createNode(6);
struct node *n4= createNode(3);
struct node *n5= createNode(7);
(*n1).left=n2;
(*n1).right=n3;
n2->left= n4;
n3->right =n5;
preorderTraversal(n1);printf("\n");
postorderTraversal(n1);printf("\n");
inorderTraversal(n1);
printf("\n%d",checkBST(n1));
printf("\n%d\n",searchBST(n1,7));
insertBST(n1,2);
preorderTraversal(n1);
    return 0;
}
