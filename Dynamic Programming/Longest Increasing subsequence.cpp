#include<iostream>

using namespace std;


// DP solution time complexity O(n^2)
int findLis(int arr[],int n){

int lis[n];
fill(lis,lis+n,1);

for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
        if(arr[j]<arr[i])
            lis[i] = max(lis[i],lis[j]+1);

int res = lis[0];

for(int i=0;i<n;i++)
    if(res<lis[i])
        res=lis[i];

return res;
}

// Optimized solution using binary search time complexity O(nlogn)

int findIndex(int lis[],int key, int n){
int high = n;
int low =0;
while(low<high){
int mid = (high + low)/2;
   if(lis[mid]>=key) high = mid;
   else{
     low = mid+1;
   }
}
return high;
}

int findLis2(int arr[],int n){
int lis[n];
lis[0] = arr[0];
int temp =1;
for(int i=1;i<n;i++){
    if(arr[i] > lis[temp])
        lis[++temp] = arr[i];
    else{
        int c = findIndex(lis,0,temp);
        lis[c]=arr[i];
    }
}
return temp;
}




int main(){

int arr[] = {3,4,2,8,13,1};

cout<< findLis(arr,sizeof(arr)/sizeof(int)) <<endl;

cout<< findLis2(arr,sizeof(arr)/sizeof(int)) <<endl;

return 0;
}
