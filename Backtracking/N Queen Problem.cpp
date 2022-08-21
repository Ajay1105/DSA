#include <iostream>

using namespace std;

int board[5][5];

bool isSafe(int row,int col){

for(int i=0;i<col;i++){
    if(board[row][i]) return false;
}

for(int i= row,j= col;i>=0 && j>=0; i--,j--){
    if(board[i][j]) return false;
}

for(int i= row,j= col;i<5 && j>=0; i++,j--){
    if(board[i][j]) return false;
}
return true;
}

bool placeQueen(int col,int n){
if (col == n) return true;
for(int i=0;i<n;i++){
    if(isSafe(i,col)){
    board[i][col]=1;
    if(placeQueen(col+1,n)) return true;
    board[i][col] =0;
    }
}
return false;
}

void printBoard(){
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        cout << board[i][j] << " ";
    }
    cout<<endl;
}
}

int main()
{
placeQueen(0,5)?cout<<"yes"<<endl:cout<<"no"<<endl;
printBoard();
    return 0;
}
