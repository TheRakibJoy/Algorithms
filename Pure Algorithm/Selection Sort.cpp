#include<bits/stdc++.h>

using namespace std;

int Min(int arr[],int lb,int ub)
{
    int Min=lb;
    while(lb<ub)
    {
        if(arr[lb] < arr[Min])
            Min=lb;
        lb++;
    }
    return Min;
}
void selection(int arr[],int n)
{
    int i=0,loc=0,temp=0;
    for(i=0;i<n;i++)
    {
        loc=Min(arr,i,n);
        temp=arr[loc];
        arr[loc]=arr[i];
        arr[i]=temp;
    }
}
int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array after sort:\n";
    selection(arr,n);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

