#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> vec[],int u,int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void BFS(vector<int> vec[],int v,int s)
{
    bool visted[v+1];
    for(int i=0; i<v; i++)
    {
        visted[i]=false;
    }
    queue<int> q;
    visted[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<< u<<" " ;
        for(int v: vec[u])
        {
            if(visted[v] == false)
            {
                visted[v] = true;
                q.push(v);
            }
        }
    }
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
    int n =4;
    vector<int> vec[n];
    addEdge(vec,0,1);
    addEdge(vec,0,2);
    addEdge(vec,1,2);
    addEdge(vec,1,3);
    printEdges(vec,n);
    cout<<endl;
    BFS(vec,n,0);
    return 0;
}
