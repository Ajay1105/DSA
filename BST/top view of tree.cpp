#include <iostream>
#include <map>
#include <queue>
using namespace std;

// hd (horizontal distance) below keeps track horizontal position of nodes. head node is at horizontal position zero if we move left horizontal position reduces by 1
// if we move in right horizontal position increases by one.

// Same code with one line change can be used for bottom view of tree
// Just uncomment line 53 and comment line 51
class node{
public:
int data;
int hd;
struct node *left;
struct node *right;
    node(int data,int hd){
    this->data= data;
    this->left = NULL;
    this->right = NULL;
    this->hd = hd;
    }
};

node* insert(node * head, int k,int p=0){
if(head== NULL) { return new node (k,p);}
if(k > head->data){
    head->right = insert(head->right,k,++p);
}else{
head->left = insert(head->left,k,--p);
}
return head;
}

void verticalTraversal(node * head, map<int,vector<node*>> &m){
queue <node *> q;
q.push(head);
while(!q.empty()){
    node * curr = q.front();
    m[curr->hd].push_back(curr);
    q.pop();
    if(curr->left != NULL) q.push(curr->left);
    if(curr->right != NULL) q.push(curr->right);
}
}



void printMap(map<int,vector<node*>> &m){
for(auto it=m.begin(); it != m.end() ;it++){
        cout << ((it->second)[0])->data << " ";
        // for bottom view print below line
        //cout << ((it->second)[(it->second).size() -1])->data << " ";
     cout<<endl;
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
map <int, vector <node*>> m;
verticalTraversal(n1,m);
printMap(m);
    return 0;
}
