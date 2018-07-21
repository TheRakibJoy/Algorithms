#include<bits/stdc++.h>

using namespace std;
void insertion(int arr[],int n)
{
    int i=0,j=0,temp;
    for(i=0;i<n;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(arr[j] > temp)
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    insertion(arr,n);
    cout<<"Array after sorting:\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

