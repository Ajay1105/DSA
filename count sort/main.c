#include <stdio.h>
#include <stdlib.h>

int maxElement(int *a,int n){
int max = 0;
for(int i=0;i<n;i++){
    if(a[i]>max){
        max = a[i];
    }
}
return max;
}

void countSort(int*a,int n,int m){
int b[m+1];int j =0;
for(int l=0;l<m+1;l++){
    b[l]=0;
}
for(int i =0;i<n;i++){
    b[a[i]] +=1;
}
for(int i =0;i<m+1;i++){
    while(b[i] !=0){
       a[j] = i; j++;
       b[i] -= 1;
    }
}
}

void display(int *a,int n){
for(int i=0;i<n;i++){
    printf("%d ",a[i]);
}printf("\n");
}

int main()
{ int a[]={2,6,8,5,9,3,4};
display(a,7);
int max = maxElement(a,7);
countSort(a,7,max);
display(a,7);
    return 0;
}
