#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> vec[],int u,int v){
    vec[u].push_back(v);
}

bool visted[6] = {false};
bool restStack[6] = {false};

bool detectCycle(vector<int> vec[],int s){
    visted[s] = true;
    restStack[s]= true;
for(int v : vec[s]){
   if(!visted[v] && detectCycle(vec,v)) return true;
    else if(restStack[v]) return true;
}
restStack[s]=false;
return false;
}

bool dfs(vector<int> vec[],int n){
for(int i=0;i<n;i++){
    if(!visted[n] && detectCycle(vec,i))
        return true;
    return false;
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
    int n =6;
    vector<int> vec[n];
    addEdge(vec,0,1);
    addEdge(vec,1,2);
    addEdge(vec,3,1);
    addEdge(vec,2,3);
    addEdge(vec,2,4);
    printEdges(vec,n);
    dfs(vec,n)?cout<<"yes":cout<< "no";
    return 0;
}
