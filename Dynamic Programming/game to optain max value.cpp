#include <iostream>

using namespace std;

// Recursive solutions
int game(int arr[],int i,int j, int sum){
if(j== i+1) return max(arr[i],arr[j]);
 return max(sum - game(arr,i+1,j,sum-arr[i]),sum - game(arr,i,j-1,sum-arr[j]));
}

int game(int arr[],int i,int j){
if( j == i+1) return max(arr[i],arr[j]);
return max(arr[i]+min(game(arr,i+2,j),game(arr,i+1,j-1)),
           arr[j]+min(game(arr,i+1,j-1),game(arr,i,j-2)));
}

// DP solution


int main(){
int arr[] = { 2,5,15,6 };
int sum =0;
for(int i=0;i<4;i++)
    sum =+ arr[i];

cout << game(arr,0,3,sum)<<endl;
cout << game(arr,0,3)<<endl;

return 0;
}
