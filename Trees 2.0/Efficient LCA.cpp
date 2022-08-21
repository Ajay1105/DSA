#include <iostream>
#include <vector>

// time complexity - O(n ), as code goes for one traversal of tree.

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

node* lca(node * root,int n1,int n2){
if(root == NULL) return NULL;
if((root->data) == n1 || (root->data) == n2) return root;
node * lca1 = lca(root->left,n1,n2);
node * lca2 = lca(root->right,n1,n2);
if(lca1 != NULL && lca2 != NULL){
    return root;
}
if(lca1 != NULL) return lca1;
else return lca2;
}

int main()
{
  // making a tree
  node * n1 = new node(10);
  node * n2 = new node(20);
  node * n3 = new node(30);
  n1-> left = n2;
  n1->right = n3;
  node * n4 = new node(40);
  node * n5 = new node(50);
  n3-> left = n4;
  n3->right = n5;
  node * n6 = new node(60);
  node * n7 = new node(70);
  node * n8 = new node(80);
  node * n9 = new node(90);
  node * n10 = new node(100);
  node * n11 = new node(110);
  n5->left = n9;
  n9->left = n10;
  n10->right = n11;
  n5->right = n6;
  n6->left = n7;
  n6->right = n8;

 inorderTraversal(n1);
 cout<< (lca(n1,40,50))->data <<endl;
    return 0;
}
