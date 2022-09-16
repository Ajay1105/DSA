#include <iostream>
#include <cstring>
using namespace std;


// Memorization
int lcs(string s1,string s2,int m,int n,int memo[4][3]){
if(memo[m][n] != -1) return memo[m][n];
if(m == 0 || n==0) memo[m][n] = 0;
else{
        if(s1[m] == s2[n])
    memo[m][n] = 1 + lcs(s1,s2,m-1,n-1,memo);
else
    memo[m][n] = max(lcs(s1,s2,m-1,n,memo),lcs(s1,s2,m,n-1,memo));
}
return memo[m][n];
}

// Tabulization
int lcs2(string s1,string s2,int m,int n){
int dp[4][3];
for(int i=0;i<=m+1;i++){
    dp[i][0]=0;
}
for(int i=0;i<=n+1;i++){
    dp[0][i]=0;
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
        }else{
        dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
return dp[m][n];
}

int main(){
int memo[4][3] = {-1};
memset(memo, -1, sizeof(memo));
cout << lcs("abz","az",3,2,memo)<<endl;
cout << lcs2("abz","az",3,2)<<endl;
return 0;
}
