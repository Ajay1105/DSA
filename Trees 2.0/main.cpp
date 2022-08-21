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

int main()
{ node * n1 = new node(10);
  node * n2 = new node(20);
  node * n3 = new node(30);
  n1->left = n2;
  n2->right = n3;
 inorderTraversal(n1);

    return 0;
}
