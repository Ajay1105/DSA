#include <iostream>

using namespace std;

class node{
public:
int data;
int lcount;
struct node *left;
struct node *right;
    node(int data){
    this->data= data;
    this->left = NULL;
    this->right = NULL;
    lcount = 1;
    }
};

void inorderTraversal (node *head){
if(head != NULL){
    cout<<head->data<< " " << head->lcount<<endl;
    inorderTraversal(head->left);
    inorderTraversal(head->right);
}
}

node* insert(node * head, int k){
if(head== NULL) { return new node (k);}
if(k > head->data){
    head->right = insert(head->right,k);
}else{
    head->lcount +=1;
head->left = insert(head->left,k);
}
return head;
}

node * KthLargestTerm(node * head, int term){
if(term == head->lcount) return head;
else if(term < head->lcount){
    return KthLargestTerm(head->left,term);
}else{
    term -= head->lcount;
    return KthLargestTerm(head->right,term);
}
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
cout<< (KthLargestTerm(n1,7))->data<<endl;
    return 0;
}
