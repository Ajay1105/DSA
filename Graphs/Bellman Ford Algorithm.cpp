#include <bits/stdc++.h>

using namespace std;

//Time complexity = O(n-1)*O(E);

void bellmanFord(vector<pair<int,int>> vec[],vector<int> &dis,int n){
for(int i=0;i<n-1;i++){
 for(auto j : vec[i]){
    if(dis[j.first] > dis[i]+j.second){
        dis[j.first] = dis[i]+j.second;
    }
 }
}
}

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

int main(){
    int n =5;
    vector<pair<int,int>> vec[n];
    vector<int> dis(n,INT_MAX);
    dis[0]=0;
    addEdge(vec,0,3,3);
    addEdge(vec,0,2,1);
    addEdge(vec,0,1,5);
    addEdge(vec,1,3,4);
    addEdge(vec,1,4,5);
    addEdge(vec,2,3,2);
    printWeight(vec,n);
    bellmanFord(vec,dis,n);
    for(int i=0;i<n-1;i++){
        cout << dis[i] << " ";
    }
    return 0;
}
