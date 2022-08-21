#include <bits/stdc++.h>

using namespace std;

//DAG means Directed Acyclic graph
//Time complexity = O(n^2);
//it can be optimized to O(nlogn) by using head
//just replace for loop(which find minimum key with a heap data structure

void primMST(vector<pair<int,int>> vec[],int n){

bool mst[n] {false};
int key[n] {0,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
//fill(key+1,key+(n-1),INT_MAX);
int parent[n] {-1};

for(int i=0;i<n;i++){
    int minKey = INT_MAX,index;
    for(int j=0;j<n;j++){
        if(!mst[j] && minKey > key[j]){
            minKey = key[j];
            index = j;
        }
    }

mst[index]= true;

for(auto k: vec[index]){
    int v = k.first;
    int weight = k.second;
    if(!mst[v] && weight < key [v]){
        parent[v] = index;
        key[v] = weight;
    }
}

}

for (int l=0;l<n;l++){
    cout << l << " -> " << parent[l] << " __ "<< key[l]<< " \n ";
}
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
    primMST(vec,n);
    return 0;
}
