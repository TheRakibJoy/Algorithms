/** if the same element are twice or more,print the right most address. if not found print nearly smaller element's address**/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,BEG,END,ITEM,MID,res=-1,temp=-1;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>ITEM;
    BEG=0;
    END=n-1;
    while(BEG<=END)
    {
        MID=BEG+((END-BEG)/2);
        if(ITEM == a[MID])
        {
            res=MID;
            BEG=MID+1;
        }
        else if(ITEM < a[MID])
        {
            END=MID-1;
        }
        else
        {
            temp=MID;
            BEG=MID+1;
        }
    }
    if(res>=0)
        cout<<res+1<<endl;
    else
    {
        if(temp>=0)
            cout<<temp+1;
        else
            cout<<0<<endl;
    }
    return 0;
}
