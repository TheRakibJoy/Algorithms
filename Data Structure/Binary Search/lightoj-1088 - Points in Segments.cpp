#include<bits/stdc++.h>

using namespace std;
int n,cnt,a[100005];
int bin(int ITEM)
{
    int BEG,END,MID,res=-1;
    BEG=1;
    END=n;
    cnt=-1;
    while(BEG<=END)
    {
        MID=((END+BEG)/2);
        if(a[MID] == ITEM)
        {
            cnt=0;
            res=MID;
            break;
        }
        else if(ITEM<a[MID])
        {
            res = MID ;
            END=MID-1;
        }
        else{
            BEG=MID+1;
        }
    }
    if(res>=0)
        return res;
    else
        return n+1;
}
int main()
{
    int i,j,k,T,q,l,r,lb,ub,sum,co,ll,bb;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&q);
        for(j=1;j<=n;j++)
            scanf("%d",&a[j]);
        printf("Case %d:\n",i);
        for(j=0;j<q;j++)
        {
            sum=0;
            scanf("%d %d",&l,&r);
            lb=bin(l);
            ll=cnt;
            if(cnt<0)
                lb-=1;
            ub=bin(r);
            bb=cnt;
            if(cnt<0)
                ub-=1;
            if(ll==0 && bb==0)
                co=ub-lb+1;
            else if(ll==0 && bb<0)
                co=ub-lb+1;
            else
                co=ub-lb;
            //cout<<"ub = "<<ub<<" lb= "<<lb<<endl;
            printf("%d\n",co);
        }
    }
    return 0;
}

