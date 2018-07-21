#include<bits/stdc++.h>

using namespace std;
void Swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int arr[],int lo,int hi)
{
    int pivot=arr[hi];
    int i=lo-1;
    for(int j=lo;j<=hi-1;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            Swap(&arr[i],&arr[j]);
        }
    }
    Swap(&arr[i+1],&arr[hi]);
    return (i+1);
}
void QuickSort(int arr[],int lo,int hi)
{
    if(lo < hi)
    {
        int pi=Partition(arr,lo,hi);
        QuickSort(arr,lo,pi-1);
        QuickSort(arr,pi+1,hi);
    }
}
int main()
{
    int n,i;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    QuickSort(arr,0,n-1);
    cout<<"Sorted array: \n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}

