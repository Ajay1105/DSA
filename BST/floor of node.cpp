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

node * floorOfNode(node * head,int key){
node* res = NULL;
while(head != NULL){
    if(key==head->data) return head;
    else if( key > head->data){
        res = head;
        head = head->right;
    }
    else {
        head = head->left;
    }
}
return res;
}

node * ceilOfNode(node * head,int key){
node* res = NULL;
while(head != NULL){
   if(key==head->data) return head;
    else if( key > head->data){
        head = head->right;
    }
    else {
        res=head;
        head = head->left;
    }
}
return res;
}

int main()
{ node * n1 = new node(50);
  node * n2 = new node(30);
  node * n3 = new node(70);
  node * n4 = new node(20);
  node * n5 = new node(40);
  node * n6 = new node(60);
  node * n7 = new node(80);
  n1->left  = n2;
  n1->right = n3;
  n2->left  = n4;
  n2->right = n5;
  n3->left  = n6;
  n3->right = n7;
  cout << (floorOfNode(n1,25))->data << endl;
  cout << (ceilOfNode(n1,63))->data << endl;
    return 0;
}
