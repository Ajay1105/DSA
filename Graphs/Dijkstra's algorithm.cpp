#include <bits/stdc++.h>

using namespace std;

// Dijkstra's algorithm is used to find shortest distance form to given node to other nodes
// Time complexity O((N+E)logN) which is equivalent to O(NlogN)

int dis[5] = {0,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
bool visted[5] {false};

void dijkstra(vector<pair<int,int>>vec[]){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
pq.push(make_pair(0,0));
visted[0] =true;
while(!pq.empty()){
 auto u = pq.top();
 pq.pop();
for(auto v : vec[u.first]){
        if(dis[v.first] > v.second + dis[u.first]){
    dis[v.first] = v.second + dis[u.first];
 }
   if(!visted[v.first]){
            pq.push(v);
   visted[v.first] =true;
   }
}
}
for(int i=0;i<5;i++)
    cout << dis[i] << " ";
}

void addEdge(vector<pair<int,int>> vec[],int u,int v,int w){
    vec[u].push_back(make_pair(v,w));
    vec[v].push_back(make_pair(u,w));
}

void printWeight(vector<pair<int,int>> vec[],int n){
for(int i =0;i<n;i++){
    cout << i <<" ->  ";
 for(auto j= vec[i].begin();j !=vec[i].end();j++){
    cout << j->first << " " << j->second << " || ";
 } cout << endl;
}
}

int main(){
    int n =5;
    vector<pair<int,int>> vec[n];
    addEdge(vec,0,3,3);
    addEdge(vec,0,2,1);
    addEdge(vec,0,1,5);
    addEdge(vec,1,3,4);
    addEdge(vec,1,4,5);
    addEdge(vec,2,3,2);
    printWeight(vec,n);
    dijkstra(vec);
    return 0;
}
