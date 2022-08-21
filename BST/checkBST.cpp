#include <iostream>
#include <cmath>

using namespace std;

class node{
public:
int data;
struct node *left;
struct node *right;
    node(int data){
    this->data= data;
    this->left = NULL;
    this->right = NULL;
    }
};

void inorderTraversal (node *head){
if(head != NULL){
    cout<<head->data<<endl;
    inorderTraversal(head->left);
    inorderTraversal(head->right);
}
}

node* insert(node * head, int k){
if(head== NULL) { return new node (k);}
if(k > head->data){
    head->right = insert(head->right,k);
}else{
head->left = insert(head->left,k);
}
return head;
}

bool checkBST(node * head,int min=INT_MIN, int max=INT_MAX){
if(head == NULL) return true;
if(head->data < min || head->data > max){
    return false;
}
if(checkBST(head->left,min,head->data) && checkBST(head->right,head->data,max)){
    return true;
}
return true;
}

int main()
{ node * n1 = new node(50);
insert(n1,30);
insert(n1,70);
insert(n1,20);
insert(n1,40);
insert(n1,60);
insert(n1,80);
insert(n1,10);
inorderTraversal (n1);
checkBST(n1)?cout<<"yes" : cout<<"no";
    return 0;
}
