///****In the name of ALLAH, most Gracious, most Compassionate****//
#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define all(a)                  (a.begin()),(a.end())
#define UNIQUE(X)               (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)          (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
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
#define intlimit                2147483690
#define longlimit               9223372036854775800
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<'\n';
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

using namespace std;

#define sz 200009
int n,q,numBlock,blocksz,ara[sz],tree[sz];
ll blocksum[320][7];
vi v;
map<int , int>idx;

///BIT Part
void updateBIT(int id,int val)
{
    while(id <= n){
        tree[id] += val;
        id += (id & (-id));
    }
}

int queryBIT(int id)
{
    int sum = 0;
    while(id > 0){
        sum += tree[id];
        id -= (id & (-id));
    }
    return sum;
}

///MO's algo
struct info
{
    int qtype,value;    ///0 means sum ; 1 means add ; -1 means delete
    info(){}
    info(int _qtype,int _value)
    {
        qtype = _qtype;
        value = _value;
    }
}qry[sz];

void addUpdate(int value)
{
    int id = idx[value];
    updateBIT(id , 1);

    int blockId = (id+blocksz-1)/blocksz;
    int st = ((blockId-1)*blocksz)+1;
    int ed = (blockId*blocksz);

    ///Update Current Block
    for(int i=0 ; i<5 ; i++)
        blocksum[blockId][i] = 0;

    int modnow = queryBIT(st-1)%5;
    for(int i=st ; i<=ed ; i++){
        if(queryBIT(i)%5 != modnow){
            modnow = queryBIT(i)%5;
            blocksum[blockId][modnow] += ara[i];
        }
    }

    ///Update all the blocks situated in right side of the current block
    for(int i=blockId+1 ; i<=numBlock ; i++){
        ll temp = blocksum[i][4];
        for(int j=4 ; j>=1 ; j--)
            blocksum[i][j] = blocksum[i][j-1];
        blocksum[i][0] = temp;
    }
}

void removeUpdate(int value)
{
    int id = idx[value];
    updateBIT(id , -1);

    int blockId = (id+blocksz-1)/blocksz;
    int st = ((blockId-1)*blocksz)+1;
    int ed = (blockId*blocksz);

    ///Update Current Block
    for(int i=0 ; i<5 ; i++)
        blocksum[blockId][i] = 0;

    int modnow = queryBIT(st-1)%5;
    for(int i=st ; i<=ed ; i++){
        if(queryBIT(i)%5 != modnow){
            modnow = queryBIT(i)%5;
            blocksum[blockId][modnow] += ara[i];
        }
    }

    ///Update all the blocks situated in right side of the current block
    for(int i=blockId+1 ; i<=numBlock ; i++){
        ll temp = blocksum[i][0];
        for(int j=0 ; j<=3 ; j++)
            blocksum[i][j] = blocksum[i][j+1];
        blocksum[i][4] = temp;
    }
}

ll sumQuery()
{
    ll sum = 0;
    for(int i=1 ; i<=numBlock ; i++)
        sum += blocksum[i][3];
    return sum;
}

void Solve(int t)
{
    string cmd;
    int x;
    cin>>q;
    for(int i=1 ; i<=q ; i++){
        cin>>cmd;
        if(cmd == "sum"){
            qry[i] = info(0 , 0);
        }
        else if(cmd == "add"){
            cin>>x;
            qry[i] = info(1 , x);
            v.pb(x);
        }
        else{
            cin>>x;
            qry[i] = info(-1 , x);
            v.pb(x);
        }
    }
    SORT_UNIQUE(v);

    n = 0;
    for(int it : v){
        idx[it] = ++n;
        ara[n] = it;
    }

    numBlock = (int)sqrt(n*1.0)+1;
    blocksz = numBlock;

    for(int i=1 ; i<=q ; i++){
        if(qry[i].qtype == 0)
            cout<<sumQuery()<<endl;
        else if(qry[i].qtype == 1)
            addUpdate(qry[i].value);
        else
            removeUpdate(qry[i].value);
    }
}

int main()
{
    CIN;
    Solve(1);
    return 0;
}
