#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> vec[],int u,int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

bool visited[6] = {false};
void DFS(vector<int> vec[],int n,int s)
{
if(!visited[s]){cout<<s<<" ";visited[s]=true;}
else return;
for(int v : vec[s]){
    if(!visited[v])
    DFS(vec,n,v);
}
return;
}

void printEdges(vector<int> vec[],int u)
{
    for(int i=0; i<u; i ++)
    {
        for(int x : vec[i])
        {
            cout << x << " ";
        }
        cout<<endl;
    }
}

int main()
{
    int n =6;
    vector<int> vec[n];
    addEdge(vec,0,1);
    addEdge(vec,0,2);
    addEdge(vec,1,3);
    addEdge(vec,2,3);
    addEdge(vec,1,4);
    addEdge(vec,4,5);
    printEdges(vec,n);
    cout<<endl;
    DFS(vec,n,0);
    return 0;
}
