#include <bits/stdc++.h>

using namespace std;

// Kosaraju's algorithm is used to find SCC (strongly connected component)
// Time complexity O(N+E)

bool visted[5] {false};

stack<int> st;

void dfs(vector<int>vec[],int n,int s){
visted[s] = true;
for(int v : vec[s]){
    if(!visted[v]){
      dfs(vec,n,v);
    }
}
st.push(s);
}

void printSCC(vector<int>vecIn[],int i){
cout<<i<<" ";
    visted[i] = false;
for(int u : vecIn[i]){
 if(visted[u]){
    printSCC(vecIn,u);
 }
}
}


void vecInv(vector<int> vecIn[],int u,int v){
vecIn[v].push_back(u);
}

void kosaraju(vector<int>vec[],vector<int>vecIn[],int n,int s){
dfs(vec,n,s);
while(!st.empty()){
    int u = st.top();
    st.pop();
    if(visted){
        printSCC(vecIn,u);
    }
    cout <<endl;
}
}

void addEdge(vector<int> vec[],int u,int v){
    vec[u].push_back(v);
}

void printWeight(vector<int> vec[],int n){
for(int i =0;i<n;i++){
    cout << i <<" ->  ";
 for(auto j= vec[i].begin();j !=vec[i].end();j++){
    cout << *j << " || ";
 } cout << endl;
}
}

int main(){
    int n =5;
    vector<int> vec[n];
    vector<int> vecIn[n];

    addEdge(vec,0,2);
    addEdge(vec,0,1);
    addEdge(vec,1,4);
    addEdge(vec,2,3);
    addEdge(vec,3,0);

    vecInv(vecIn,0,2);
    vecInv(vecIn,0,1);
    vecInv(vecIn,1,4);
    vecInv(vecIn,2,3);
    vecInv(vecIn,3,0);

    printWeight(vecIn,n);
    kosaraju(vec,vecIn,n,0);
    return 0;
}
