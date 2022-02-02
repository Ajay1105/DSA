#include <iostream>

using namespace std;

void print(int * arr, int n){
for (int i =0;i<n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
}

void bubblesort(int * arr, int n){
for(int i=1;i<n;i++){
    int j=i-1,key = arr[i];
    while(j>0 &&arr[j]<key){
       arr[j+1]=arr[j];
       j--;
    }arr[j+1]=key;
}
}

int main()
{ int arr[] = {8,2,3,5};
    cout << "Unsorted array" << endl;
    print(arr,4);
    bubblesort(arr,4);
    print(arr,4);

    return 0;
}
