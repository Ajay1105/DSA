#include <iostream>
#include <math.h>
using namespace std;

int grid[4][4] = { {1,0,3,0},
                   {0,0,2,1},
                   {0,1,0,1},
                   {2,4,0,0}
                 };

bool isSafe(int n,int row,int col){
    cout<< row<<" " << col<< "|| ";
for(int i=0;i<row;i++){
    if(grid[i][col] == n || grid[row][i] == n) return false;
}
int s = sqrt(n);
int rs = row - (row%s);
int cs = col - (col%s);
for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
        if(grid[i+rs][j+cs] == n)
            return false;
    }
}
return true;
}

bool sudokoSolver(){
    int i=0,j=0;
for( i ;i<4;i++){
    for(j;j<4;j++){
        if(grid[i][j]== 0){
            break;
            }
    }
}
if(i==4 && j==4){ return true;}

for(int k=1;k<=4;k++){
 if(isSafe(i,j,k)){
    grid[i][j] = k;
    if(sudokoSolver()){ return true;}
    grid[i][j] = 0;
 }
}
return false;
}

void printSudoko(){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        cout << grid[i][j]<< " ";
    }
    cout<<endl;
}
}

int main(){

sudokoSolver()?cout<<"yes"<<endl:cout<<"not possible";
printSudoko();
return 0;
}
