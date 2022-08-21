#include <iostream>
#include <vector>

// Lowest common ancestor stand for lowest ancestor (height wise)
// time complexity - O(n ^ 2), as code goes for two traversal of tree.

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

//to find path through which given node can be reached and storing all the ancestor element in vector
bool findPath(vector<node *> &arr, node * head, int key){
if(head == NULL) return false;
arr.push_back(head);
if(head->data == key) return true;
if( findPath( arr, (head->left), key) || findPath(arr, (head->right), key) )
    return true;
arr.pop_back();
return false;
}

void printPath(vector<node *> &arr){
    cout<< "path"<<endl;
for(int i=0;i<arr.size();i++){
   cout<< (arr.at(i))->data <<endl;
}
}

int lca(vector<node *> &arr, vector<node *> &arr2){
    int lca;
    for(int i=0; i< arr.size() && i< arr2.size(); i++){
// Ancestors will common after LCA
    if(arr2[i] == arr[i]){
        lca = arr2[i]->data;
    }
}
 return lca;
}

int main()
{
  vector<node *> arr,arr2;
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
 findPath(arr, n1,70);
 findPath(arr2, n1,100);
 printPath(arr);
 printPath(arr2);
 cout<< "LCA is: "<<lca(arr,arr2);
    return 0;
}
