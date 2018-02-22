/**Binary search,if found twice or more same element,print the address of first element**/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,BEG,END,MID,res=-1,ITEM,temp=-1;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>ITEM;
    BEG=0;
    END=n-1;
    while(BEG<=END)
    {
        MID=BEG+((END-BEG)/2);
        if(ITEM == a[MID])
        {
            res=MID;
            END=MID-1;
        }
        else if(ITEM < a[MID])
        {
            temp=MID;
            END=MID-1;
        }
        else
            BEG=MID+1;
    }
    if(res >= 0)
        cout<<res+1<<endl;
    else
    {
        if(temp==-1)
            cout<<n+1<<endl;
        else
            cout<<temp+1<<endl;
    }
    return 0;
}
