#include<bits/stdc++.h>
using namespace std;

int notes[1000];
int n;
void CoinChange(int val)
{
    sort(notes,notes+n);
    vector<int>ans,res;
    int V = val, cnt = 0, mx = 1000000000;
    for(int j = n-1; j >= 0; j--)
    {
        cnt=0;
        V = val;
        for(int i=j; i>=0; i--)
        {
            while(V >= notes[i])
            {
                V -= notes[i];
                ans.push_back(notes[i]);
                cnt++;
            }
        }
        if(mx>cnt && V==0)
        {
            mx = cnt;
            res = ans;
        }
        ans.clear();
    }
    cout<<"You need total "<<res.size()<<" coin & they are:\n";
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
}
int main()
{
    int x,i;
    cout<<"Enter the number of coins: ";
    cin>>n;
    cout<<"Enter the value of coins: ";
    for(i=0;i<n;i++)
        cin>>notes[i];
    cout<<"Enter the value u want to change: ";
    cin>>x;
    cout<<"Following is minimal number of change for "<<x<<"\n";
    CoinChange(x);
    return 0;
}

