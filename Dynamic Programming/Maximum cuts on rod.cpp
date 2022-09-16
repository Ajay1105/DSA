#include<iostream>

using namespace std;

//Recursive
//int minCoin(int coin[],int n,int val){
//if(val== 0) return 0;
//int res = INT_MAX;
//
//for(int i=0;i<n;i++){
// if(coin[i]<=val){
//    int sub_res = minCoin(coin,n,val-coin[i]);
//    if(sub_res != INT_MAX)
//        res = min(sub_res+1,res);
// }
//}
//
//return res;
//}

//Dynamic Programming
int mem[31];
int minCoin(int coin[],int n,int val){
for(int i=1;i<=val;i++){
    for(int j =0;j<n;j++){
        int res = INT_MAX;
        if(coin[j]<=i){
        res = mem[i-coin[j]] + 1;
        }
        if(res< mem[i]){
            mem[i]=res;
        }
    }
}
return mem[val];
}

int main(){
mem[0] =0;
fill(mem+1,mem+31,INT_MAX);
int coin[] = {25,20,10,5,1};
cout << minCoin(coin,sizeof(coin)/sizeof(int),30) << endl;

return 0;
}
