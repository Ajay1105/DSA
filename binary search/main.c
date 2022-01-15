#include <stdio.h>
#include <stdlib.h>

void bs(int arr[], int size,int e){
int low=0,mid,high=size-1;

while(low<=high){
mid = (low+high)/2;
if (arr[mid]==e){
    printf("%d",mid+1);
    exit(0);
}
if(e<arr[mid]){
    high = mid-1;
}if(e>arr[mid]){
    low = mid+1;
}
}
}
// this is nothing
int main()
{
int arr[]= {0,1,2,4,5,6,7,8,9};
int size = (sizeof(arr)/sizeof(int));
int element;
printf("Enter the element you want to find in array ");
scanf("%d",&element);
bs(arr,size,element);
    return 0;
}
