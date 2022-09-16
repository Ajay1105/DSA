#include<iostream>

using namespace std;

//Recursive solution
int findJump(int jump[],int n){
    if(n==1) return 0;
    int res = INT_MAX;
    for(int i=n-2;i>=0;i--){
        if(i+jump[i]>=n-1){
            int sub_res = findJump(jump,i+1);
            if(sub_res != INT_MAX){
                res = min(res,sub_res+1);
            }
        }
    }
return res;
}

//DP solution
int findJump2(int jump[],int n){
int dp[n];
dp[0]=0;
fill(dp+1,dp+n,INT_MAX);
for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
        if(jump[j]+j >= i)
            if(dp[j] != INT_MAX)
                dp[i] = min(dp[i],dp[j]+1);

for(int i=0;i<n;i++) cout <<dp[i] << " ";cout<<endl;

return dp[n-1];
}

int main(){
int jump[] = {3,4,2,1,2,1};
cout << findJump(jump,sizeof(jump)/sizeof(int))<<endl;
cout << findJump2(jump,sizeof(jump)/sizeof(int))<<endl;

return 0;
}
