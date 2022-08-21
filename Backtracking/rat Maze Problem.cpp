#include <iostream>

using namespace std;

int path[3][3] = {0};

bool isSafe(int arr[3][3],int i,int j)
{
    return(i<3 && j<3 && arr[i][j] == 1);
}

void printPath(){
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout << path[3][3]<< " ";
    }
    cout<<endl;
}
}

bool mazePath(int n,int arr[3][3],int i,int j)
{
    if(i==n-1 && j==n-1 && arr[i][j] == 1)
    {
        cout<<path[i][j]<<endl;
        return true;
    }
    if(isSafe(arr,i,j))
    {
        path[i][j]=1;
        if(mazePath(n,arr,i+1,j)) return true;
        else if(mazePath(n,arr,i,j+1)) return true;
        path[i][j] =0;
    }

    return false;
}

int main()
{
    int arr[3][3]=
      { {1,0,1},
        {1,1,0},
        {0,1,1}
    };

    mazePath(3,arr,0,0)?cout<<"yes"<<endl:cout<<"No"<<endl;
    printPath();
    return 0;
}
