#include <iostream>
using namespace std;

void print (int * arr, int n){
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
}

selectionsort(int *arr, int n){
for(int i =0;i<n-1;i++){
    for(int j= i+1;j<n;j++){
        if(arr[i]>arr[j]){
            int temp = arr [i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}
}

int main()
{int arr[]={9,8,7,6,5,4,3,2,1,0};
int n =sizeof(arr)/sizeof(int);
cout<<"Unsorted array : ";
print(arr,n);
selectionsort(arr,n);
cout<<"Sorted array :   ";
print (arr,n);
    return 0;
}
