#include<bits/stdc++.h>

using namespace std;
vector<int>v;
int n;
int bin(int ITEM)
{
    int BEG=0;
    int END=n-1;
    int MID,res=0;
    MID=(BEG+END)/2;
    while(BEG<=END)
    {
        if(ITEM == v[MID])
        {
            res=MID;
            END=MID-1;
        }
        else if(ITEM < v[MID])
        {
            END=MID-1;
        }
        else
            BEG=MID+1;
        MID=(BEG+END)/2;
    }
    return res;
}
int main()
{
    int q,i,j=0,item,co,temp;
    while(1)
    {
        j++;
        v.clear();
        scanf("%d %d",&n,&q);
        if(n==0 && q==0)
            break;
        else
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&temp);
                v.push_back(temp);
            }
            sort(v.begin(),v.end());
            printf("CASE# %d:\n",j);
            for(i=0;i<q;i++)
            {
                scanf("%d",&item);
                co=bin(item);
                if(v[co] == item)
                    printf("%d found at %d\n",item,co+1);
                else
                    printf("%d not found\n",item);
            }
        }
    }
    return 0;
}
