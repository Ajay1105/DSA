#include <iostream>

using namespace std;

void pr(int* arr,int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleshort(int * arr, int n)
{
    bool shorted =false;
    for (int i=0; i<n; i++)
    {
        shorted = true;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] =arr[j];
                arr[j] = temp;
                shorted = false;
            }


        } if(shorted)
            {
                return;
            }
    }
}

int main()
{
    int arr[]= {9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Unsorted array"<<endl;
    pr(arr,n);
    cout<<"Sorted array"<<endl;
    bubbleshort(arr,n);
    pr(arr,n);
    return 0;
}
