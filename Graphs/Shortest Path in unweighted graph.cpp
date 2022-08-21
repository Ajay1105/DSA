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
int dis[6] = {0,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};

void printdis(){
for(int i =0;i<6;i++){
    cout << i<<" " <<dis[i] << " || ";
}
}

void findShortestPath(vector<int> vec[],int n,int s)
{
queue<int> q;
q.push(s);
visited[s]=true;
while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v : vec[u]){
        if(!visited[v]){
            dis[v]=dis[u]+1;
            visited[v] = true;
            q.push(v);
        }
    }
}
printdis();
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
    addEdge(vec,2,4);
    addEdge(vec,3,5);
    addEdge(vec,4,5);
    printEdges(vec,n);
    cout<<endl;
    findShortestPath(vec,n,0);
    return 0;
}
