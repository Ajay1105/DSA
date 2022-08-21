#include <bits/stdc++.h>

using namespace std;

//DAG means Directed Acyclic graph
//Time complexity = O(v+e);

void addEdge(vector<pair<int,int>> vec[],int u,int v,int w){
    vec[u].push_back(make_pair(v,w));
}

void printWeight(vector<pair<int,int>> vec[],int n){
for(int i =0;i<n;i++){
    cout << i <<" ->  ";
 for(auto j= vec[i].begin();j !=vec[i].end();j++){
    cout << j->first << " " << j->second << " || ";
 } cout << endl;
}
}

void printDis(int dis[]){
for(int i=0;i<5;i++){
    cout << dis[i] << " || ";
}
}

void shortestPath(vector<pair<int,int>> vec[],int s,bool visted[],int dis[]){
 for(auto u: vec[s]){
    if(dis[u.first] > u.second + dis[s]){
        dis[u.first] = u.second + dis[s];
    }
 }
}

void dfsRec(vector<pair<int,int>> vec[],int n,bool visted[],int dis[]){
  for(int i=0;i<n;i++){
    if(!visted[n]) shortestPath(vec,i,visted,dis);
  }
  printDis(dis);
}

int main(){
    int n =5;
    bool visted[5] {false};
    int dis[5] = {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    vector<pair<int,int>> vec[n];
    addEdge(vec,0,3,3);
    addEdge(vec,0,2,1);
    addEdge(vec,0,1,5);
    addEdge(vec,1,3,4);
    addEdge(vec,1,4,5);
    addEdge(vec,2,3,2);
    printDis(dis);
    cout<<endl<<endl<<endl;
    printWeight(vec,n);
    dfsRec(vec,n,visted,dis);
    return 0;
}
