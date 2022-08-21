#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Topological sorting using DFS

bool visted[5] = {false};

void addEdge(vector<int> vec[],int u,int v){
    vec[u].push_back(v);
}

stack<int> q;
void topologicalSort(vector<int> vec[],int s){
visted[s]=true;
    for(int v : vec[s]){
        if(!visted[v] )
            topologicalSort(vec,v);
    }
         q.push(s);
}

void printStack(){
for(int i=0;i<10;i++){
    cout << q.top() << " ";
    q.pop();
}
}

void dfs(vector<int> vec[],int n){
for(int i=0;i<n;i++){
    if(!visted[i]  )
    topologicalSort(vec,i);
    }

}

void printEdges(vector<int> vec[],int u){
    for(int i=0; i<u; i ++)
    {
        for(int x : vec[i])
        {
            cout << x << " ";
        }
        cout<<endl;
    }
}

int main(){
    int n =5;
    vector<int> vec[n];
    addEdge(vec,0,3);
    addEdge(vec,0,2);
    addEdge(vec,1,3);
    addEdge(vec,1,4);
    addEdge(vec,2,3);
    cout<<endl;
    printEdges(vec,n);
    dfs(vec,n);
    printStack();
    return 0;
}
