#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }

}

void mergeSort(int A[], int low, int high){
    int mid;
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}





/*#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int m,int l,int h)
{
    int i = l;
    int j = m+1;
    int b[h+1];
    int k=l;
    while(i<=l && j<=h)
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<=m)
    {
        b[k]=a[i];
        k++;i++;
    }
    while(j<=h)
    {
        b[k]=b[j];
        k++;j++;
    }
    for(int z=l; z<h+1; z++)
    {
        a[z]=b[z];
    }
}

void mergeSort(int a[],int l,int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,m,l,h);
    }
}

void display(int* a,int s)
{
    for(int i=0; i<s; i++)
    {
        printf("%d ",a[i]);
    }printf("\n");
}

int main()
{
    int a[6] = {7,3,8,5,9,2};
    display(a,5);
    mergeSort(a,0,5);
    display(a,5);
    return 0;
}*/
