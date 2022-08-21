#include <iostream>
#include <vector>
using namespace std;
// Graphs have two representation adjacency matrix and adjacency list
// It is code for adjacency list which is more efficient

void addEdge(vector<int> vec[],int u,int v){
vec[u].push_back(v);
vec[v].push_back(u);
}

void printEdges(vector<int> vec[],int u){
for(int i=0;i<u;i ++){
    for(int x : vec[i]){
        cout << x << " ";
    } cout<<endl;
}
}

int main()
{ int n =4;
vector<int> vec[n];
addEdge(vec,0,1);
addEdge(vec,0,2);
addEdge(vec,1,2);
addEdge(vec,1,3);
printEdges(vec,n);
    return 0;
}
