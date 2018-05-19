    /**
    Bismillahir Rahmanir Rahim
    MD. Iqbal Hossain Bappy
    Dept. of CSE, CoU
    **/

#include<bits/stdc++.h>

#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define mp                      make_pair
#define db                      double
#define EPS                     10E-10
#define ff                      first
#define ss                      second
#define sqr(x)                  (x)*(x)
#define vi                      vector<int>
#define vl                      vector<ll>
#define vii                     vector<vector<int> >
#define vll                     vector<vector<ll> >
#define DBG                     pf("HI\n")
#define MOD                     1000000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                2147483647;
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mx                      123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///------------------Graph Moves-------------------
/// const int fx[] = {+1,-1,+0,+0};
/// const int fy[] = {+0,+0,+1,-1};
/// const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
/// const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

struct Data
{
    int val,pos;
    bool operator < (Data A)
    {
        if(val != A.val)
        {
            return val<A.val;
        }
        else if(pos != A.pos)
        {
            return pos<A.pos;
        }
        return 0;
    }
};
int n;
int Bin(Data ara[],int item)
{
    int lo=0,hi=n-1,mid,res=-1;
    while(lo<=hi)
    {
         mid=(lo+hi)/2;
         if(ara[mid].val == item)
         {
             res=ara[mid].pos;
             hi=mid-1;
         }
         else if(item < ara[mid].val)
         {
             hi=mid-1;
         }
         else
         {
             lo=mid+1;
         }
    }
    return res;
}
int main()
{
    int i,j,item;
    cout<<"Enter the size of array: ";
    cin>>n;
    Data ara[n];
    cout<<"Enter the array element: ";
    for(i=0;i<n;i++)
    {
        scin(ara[i].val);
        ara[i].pos=i+1;
    }
    sort(ara,ara+n);
//    cout<<"Array after sort:\n";
//    for(i=0;i<n;i++)
//        cout<<ara[i].val<<"\t";
    cout<<"Enter the item to be searched: ";
    cin>>item;
    cout<<"Index of expected value is: "<<Bin(ara,item);
    return 0;
}

