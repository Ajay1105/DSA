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

int sizeOfTree(node * root){
 int left =0, right =0;
 node * curr = root;
 while(curr->left != NULL){
    left++;
    curr = curr->left;
 } curr = root;
  while(curr->right != NULL){
    right++;
    curr = curr->right;
 }
 if(left==right) return pow(2,left);
 else return 1+ sizeOfTree(root->left) + sizeOfTree(root->right);
}

int main()
{
  // making a tree
  node * n1 = new node(10);
  node * n2 = new node(20);
  node * n3 = new node(30);
  node * n4 = new node(40);
  node * n5 = new node(50);
  node * n6 = new node(60);
  node * n7 = new node(70);
  node * n8 = new node(80);
  node * n9 = new node(90);
  node * n10 = new node(100);
  node * n11 = new node(110);

  n1-> left = n2;
  n1->right = n3;
  n2-> left = n4;
  n2->right = n5;
  n3->right = n6;
  n3->left = n7;
  n4->right = n8;
  n4->left = n9;
  n5->left = n10;
  n5->right = n11;

 inorderTraversal(n1);
 cout<<endl<<endl<< sizeOfTree(n1);
    return 0;
}
