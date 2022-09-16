#include<iostream>

using namespace std;

int subsetSum(int arr[],int n,int sum){
if(n==0)
    return (sum==0)? 1:0;
return subsetSum(arr,n-1,sum) + subsetSum(arr,n-1,sum - arr[n-1]);
}

int main(){
int arr[5] = {10,5,2,3,6};
cout<<subsetSum(arr,5,8)<<endl;
return 0;
}
