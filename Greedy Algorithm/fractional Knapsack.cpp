#include <bits/stdc++.h>

using namespace std;

bool myCmp(pair <int,int> a, pair <int,int> b){
return ((a.second)/(a.first) > (b.second)/(b.first));
}

void knapsackAlgo(pair <int,int> arr[],int capacity,int n){
sort(arr,arr+n,myCmp);

int i=0,value=0;
while(capacity){

if(capacity < arr[i].first){
    value += (arr[i].second * capacity)/arr[i].first;
    break;
}
 capacity -=arr[i].first;
 value += arr[i].second;
 i++;
}
cout << value;
}

int main(){
pair<int,int> arr[3];
arr[0]= make_pair(50,600);
arr[1]= make_pair(20,500);
arr[2]= make_pair(30,400);
int capacity = 70;

knapsackAlgo(arr,capacity,3);

return 0;
}
