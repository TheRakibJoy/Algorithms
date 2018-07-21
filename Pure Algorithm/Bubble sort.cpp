#include<bits/stdc++.h>
using namespace std;
void Bubble(int ara[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(ara[j+1]>ara[j])
            {
                int temp=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=temp;
            }
        }
    }
}
int main()
{
    int i,n;
    cout<<"Enter the number of array element: ";
    cin>>n;
    int ara[n];
    cout<<"Enter the array: ";
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    Bubble(ara,n);
    cout<<"The sorted array is: \n";
    for(i=0;i<n;i++)
        cout<<ara[i]<<"\t";
    cout<<endl;
    return 0;
}

