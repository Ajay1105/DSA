#include <iostream>
#include <vector>
// to include priority_queue STL
#include <queue>
// to use priority_queue in inbuilt comparator (here convert max heap into min heap)
#include <functional>

using namespace std;

int main(){
//Syntax to declare a max heap. It automatically arranges element in max heap:
//priority_queue<int> pqMax;

//Syntax to declare a heap using a comparator. to make a min heap:
priority_queue<int,vector<int>,greater<int>> pq;

int a[6]={5,6,17,18,11,9};

for(int i=0;i<6;i++){
    pq.push(a[i]);
}
// pq.empty() return a bool to check whether heap is empty
while(!pq.empty()){
        //pq.top() returns top element
    cout<<pq.top()<<endl;
    pq.pop();
}

return 0;
}
