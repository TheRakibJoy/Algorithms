#include<bits/stdc++.h>

using namespace std;

vector<int>a;
int binr(int ITEM)
{
    int BEG,END,MID,res=-1;
    BEG=0;
    END=a.size()-1;
    while(BEG<=END)
    {
        MID=((END+BEG)/2);
        if(a[MID] == ITEM)
        {
            res=MID;
            BEG=MID+1;
        }
        else if(ITEM<a[MID])
        {
            res = MID ;
            END=MID-1;
        }
        else
        {
            BEG=MID+1;
        }
    }
    return res;
}
int binl(int ITEM)
{
    int BEG,END,MID,res=-1;
    BEG=0;
    END=a.size()-1;
    while(BEG<=END)
    {
        MID=((END+BEG)/2);
        if(a[MID] == ITEM)
        {
            res=MID;
            END=MID-1;
        }
        else if(ITEM<a[MID])
        {
            END=MID-1;
        }
        else
        {
            res = MID ;
            BEG=MID+1;
        }
    }
    return res;
}
int main()
{
    int i,j,k=1,n,q,x,y,temp;
    scanf("%d",&n);
    scanf("%d",&temp);
    a.push_back(temp);
    for(i=1;i<n;i++)
    {
        scanf("%d",&temp);
        if(a[k-1] != temp)
        {
            a.push_back(temp);
            k++;
        }

    }
    scanf("%d",&q);
    int b[q];
    for(i=0;i<q;i++)
        scanf("%d",&b[i]);
    for(i=0;i<q;i++)
    {
        x = binl(b[i]);
        y = binr(b[i]);
        //cout<<x<<" "<<y<<endl;
        if(n == 1)
            printf("X X\n");
        else
        {
            if(a[x] == b[i])
                x-=1;
            if(a[y] == b[i])
                y+=1;
            if(x>=0 && x<=(a.size()-1))
                printf("%ld ",a[x]);
            else
                printf("X ");
            if(y>=0 && y<=(a.size()-1))
                printf("%ld\n",a[y]);
            else
                printf("X\n");
        }
    }
    return 0;
}
