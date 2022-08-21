#include <iostream>
#include <queue>
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

void levelOrderTraversal (node *head){
queue <node *> q;
q.push(head);
while(!q.empty()){
    node * curr = q.front();
    cout<< curr->data<<endl;
    q.pop();
    q.push(curr->left);
    q.push(curr->right);
}
}

node* insert(node * head, int k,int p=0){
if(head== NULL) { return new node (k);}
if(k > head->data){
    head->right = insert(head->right,k);
}else{
head->left = insert(head->left,k);
}
return head;
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
levelOrderTraversal (n1);

    return 0;
}
