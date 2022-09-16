#include<iostream>

using namespace std;

// Recursive solution
int maxSum(int arr[],int n){
if(n==1) return arr[0];
if(n==2) return max(arr[0],arr[1]);
return max(maxSum(arr,n-1),arr[n-1]+maxSum(arr,n-2));
}

// DP solution
int maxSumDP(int arr[],int n){
int dp[n+1];
dp[1] = arr[0];
dp[2] = max(arr[0],arr[1]);
for(int i=3;i<=n;i++)
    dp[i] = max(dp[i-2],arr[i-1]+dp[i-2]);
return dp[n];
}

int main(){
int arr[] = {10,5,15,20,2,30};
cout<< maxSum(arr,6)<<endl;
cout<< maxSumDP(arr,6)<<endl;
}
