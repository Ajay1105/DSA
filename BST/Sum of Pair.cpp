#include <iostream>
#include <unordered_set>

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

bool isPair(node * head, unordered_set <int> &s, int key){
if(head == NULL) return false;
if(isPair(head->left,s,key) == true) return true;
if( s.find(key - head->data) != s.end() ) return true;
if(isPair(head->right,s,key) == true) return true;
s.insert(head->data);
return false;
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

 unordered_set<int> s;
 isPair(n1,s,30)?cout << "yes" : cout << "no";
    return 0;
}
