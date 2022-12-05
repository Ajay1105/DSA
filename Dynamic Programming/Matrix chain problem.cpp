#include <iostream>

using namespace std;

int matrix(int arr[],int s,int n){
if(s+1==n) return 0;
int res = INT_MAX;
for(int i=s+1;i<n;i++){
 res = min(res,matrix(arr,s,i)+matrix(arr,i,n)+(arr[s]*arr[i]*arr[n]));
}
return res;
}

int main(){
int arr[] = {20,10,30,40};
cout<< matrix(arr,0,4) <<endl;
return 0;
}
