#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Topological sorting

bool visted[5] = {false};
int indegree[5] = {0,0,0,0,0};

void addEdge(vector<int> vec[],int u,int v){
    vec[u].push_back(v);
    indegree[v] +=1;
}

void kahnAlgo(vector<int> vec[],int n){
queue<int> q;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
while(!q.empty()){
    int u = q.front();
    q.pop();
    cout << u ;
    for(int v : vec[u]){
        indegree[v]--;
        if(indegree[v]==0) q.push(v);
    }
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
    kahnAlgo(vec,n);
    return 0;
}
