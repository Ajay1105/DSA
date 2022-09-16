#include<iostream>

using namespace std;

//recursive solution time complexity O(2^n)
//int knapsack(int val[],int weight[],int w,int n){
//if (w==0 || n==0) return 0;
//if(weight[n-1] > w) return knapsack(val,weight,w,n-1);
//else{
//   return max(knapsack(val,weight,w,n-1),val[n-1]+knapsack(val,weight,w-weight[n-1],n-1));
//}
//}

//dp solution time complexity theta (n*w) (pseudo polynomial time complexity solution)
int knapsack(int val[],int weight[],int w,int n){
int dp[n+1][w+1];
for(int i=0;i<=w;i++) dp[0][i] = 0;
for(int i=0;i<=n;i++) dp[i][0] = 0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=w;j++){
        if(weight[i-1]>j) dp[i][j] = dp[i-1][j];
        else
            dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-weight[i-1]]);
        }
}
return dp[n][w];
}

int main(){
int val[] = {10,40,30,50};
int weight[] = {5,4,6,3};

cout << knapsack(val,weight,10,4);

return 0;
}
