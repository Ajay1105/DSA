#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> vec[],int u,int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

bool visted[6] = {false};

bool detectCycle(vector<int> vec[],int s,int parent)
{
    visted[s] = true;
for(int v : vec[s]){
   if(!visted[v]){
    if(detectCycle(vec,v,s)) return true;
   }
    else if(v != parent) return true;
}
return false;
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
    addEdge(vec,1,2);
    addEdge(vec,1,3);
    addEdge(vec,2,3);
    addEdge(vec,2,4);
    printEdges(vec,n);
    cout<<endl;
    detectCycle(vec,0,-1)?cout<<"yes":cout<< "no";
    return 0;
}
