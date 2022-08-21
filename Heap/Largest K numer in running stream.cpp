#include <iostream>
#include <vector>
#include <queue>
#include <functional>

// running stream -- lot of number are being inputed we don't know end to input.

using namespace std;

void print(priority_queue<int,vector<int>,greater<int>> pq){
while(pq.size()){
    cout<<pq.top()<<" ";
    pq.pop();
}
}

int main(){
priority_queue <int, vector<int>, greater<int>> pq;
int n;
int ne=0,k=3;
while(cin>>n){
    if(n==-1){
        break;
//the below code limits the heap to have fix members
    }else if(ne-k){
        pq.push(n);
        ne++;
    }else{
        pq.pop();
        pq.push(n);
    }
}
cout<<endl<<endl;
print(pq);

return 0;
}
