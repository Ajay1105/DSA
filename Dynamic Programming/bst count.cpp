#include<iostream>

using namespace std;

// recursive solution
int bstCount(int n){
if(n==0) return 1;
if(n==1||n==2) return n;
int res=0;
for(int i= 1;i<=n;i++){
    res +=( bstCount(i-1) * bstCount(n-i) );
}
return res;
}

// DP solution . time complexity 0(n^2)
int bstCountDP(int n){
int dp[n+1];
dp[0] = 1;dp[1]=1;
for(int i=2;i<=n;i++){
    dp[i]=0;
    for(int j=0;j<=i;j++){
        dp[i] += dp[j-1]*dp[i-j];
    }
}
return dp[n];
}

int main(){
cout<< bstCount(5)<<endl;
cout<< bstCountDP(5)<<endl;
}
