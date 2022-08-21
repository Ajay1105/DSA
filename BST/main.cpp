#include <iostream>

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

node * insert(node * head,int n){
if(head == NULL) return new node (n);
if(n > head->data) head->right = insert(head->right,n);
if(n < head->data) head->left  = insert(head->left,n);
return head;
}

//Below function find the closet lower number that the number which is to be deleted
node* findNextSuccesor(node * head){
node * curr = head->right;
while(curr->left != NULL){
    curr = curr->left;
}
return curr;
}

node* deleteNode(node * head ,int n){
    cout << "Entered in delete function"<<endl;
if(head == NULL) return NULL;
if(n > head->data) head->right = deleteNode(head->right,n);
else if(n < head->data) head->left  = deleteNode(head->left,n);
else{
    if( head->left == NULL){
        node * temp = head->right;
        delete head;
        return temp;
    }else if( head -> right == NULL){
        node * temp = head->left;
        delete head;
        return temp;
    }else{
       node*temp = findNextSuccesor(head);
       head->data = temp->data;
       head->right=deleteNode(head->right,temp->data);
    }
    return head;
}
}

int main()
{ node * n1 = new node(40);
  node * n2 = new node(20);
  node * n3 = new node(30);
  node * n4 = new node(10);
  node * n5 = new node(25);
  node * n6 = new node(28);
  node * n7 = new node(50);
  n1->left  = n2;
  n1->right = n3;
  n2->left  = n4;
  n2->right = n5;
  n3->left  = n6;
  n3->right = n7;
  insert(n1,8);
 inorderTraversal(n1);
  deleteNode(n1,40);
  inorderTraversal(n1);
    return 0;
}
