#include <iostream>
#include <map>
using namespace std;

// Use Hash Map to solve this problem.

// lcount below keeps track horizontal position of nodes. head node is at horizontal position zero if we move left horizontal position reduces by 1
// if we move in right horizontal position increases by one.
class node{
public:
int data;
int lcount;
struct node *left;
struct node *right;
    node(int data,int lcount){
    this->data= data;
    this->left = NULL;
    this->right = NULL;
    this->lcount = lcount;
    }
};

// While traversing, we take lcount as key add key sum at that value as value.
void inorderTraversal (node *head, map<int, int> &m){
if(head != NULL){
    cout<<head->data<< " " << head->lcount<<endl;
    m[head->lcount] += head->data;
    inorderTraversal(head->left,m);
    inorderTraversal(head->right,m);
}
}

node* insert(node * head, int k,int p=0){
if(head== NULL) { return new node (k,p);}
if(k > head->data){
    head->right = insert(head->right,k,++p);
}else{
head->left = insert(head->left,k,--p);
}
return head;
}

void printMap(map <int,int> &m){
auto it = m.begin();
while(it != m.end()){
    cout<< it->first << " " << it->second<<endl;
    it++;
}
}

int main()
{ node * n1 = new node(50,0);
insert(n1,30);
insert(n1,70);
insert(n1,20);
insert(n1,40);
insert(n1,60);
insert(n1,80);
insert(n1,10);
map <int,int> m;
inorderTraversal (n1,m);
printMap(m);
    return 0;
}
