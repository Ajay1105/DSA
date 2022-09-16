#include<iostream>

using namespace std;

// recurssive solution
int eggDropRecursion(int e,int f)
{
    if(e==1) return f;
    if(f==1 || f==0) return f;
    int res=INT_MAX,min;
    for(int i=1; i<=f; i++)
    {
        min = max(eggDropRecursion(e-1,i-1),eggDropRecursion(e,f-i));
        if(res>min) res = min;
    }
    return res+1;
}

// dp solution
int eggDropDp(int f, int e){
int dp[f+1][e+1];
for(int i=0;i<=e;i++) dp[0][i] = 0;
for(int i=0;i<=e;i++) dp[1][i] = 1;
for(int i=0;i<=f;i++) dp[i][1] = i;

for(int i=2;i<=f;i++){
    for(int j=2;j<=e;j++){
        dp[i][j] = INT_MAX;
        for(int x=1;x<=i;x++){
            dp[i][j] = min(dp[i][j],1+max(dp[i-x][j],dp[x-1][j-1]));
        }
    }
}
return dp[f][e];
}

int main()
{
    cout<< eggDropRecursion(2,10)<<endl;
    cout<< eggDropDp(10,2)<<endl;
}
