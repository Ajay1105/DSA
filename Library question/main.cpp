#include <iostream>

using namespace std;

int main()
{
    int nbooks[100]= {0};
    int arr[100][100];
    int n,x,y;
    int a=0,b=0;
    for(int i=0; i<5; i++)
    {
        cin>>n;
        if(n==1)
        {
            cin>>x>>y;
            arr[x][nbooks[x]]= y;
            nbooks[x]=nbooks[x]+1;
        }
        else if(n==2)
        {
            cin>>x>>y;
            cout<<arr[x][y]<<endl;
        }
        else if(n==3)
        {
            cin>>x;
            cout<<nbooks[x]<<endl;
        }
    }
    return 0;
}
