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
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;
/**     toint, tostring, BigMod, Power , sieve, Primefactorize ,frequency in n!     **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
//ll Power(ll a,ll n){ll ret=1;for(ll i=1 ; i<=n ; i++)ret = ((ret%MOD)*(a%MOD))%MOD;return ret;}
//vector<ll>Prime;
//bool mark[10000003];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}
/**     Order Set       **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(0)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/** Doubly Linked List + Floyd's cycle finding algorithm Template **/
typedef struct node Node;
struct node{
    int data;
    Node *next;
    Node *prev;
};
Node *head,*tail;
Node *CreateNode(int item , Node *prev , Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error! Could not create a new node\n");
        exit(1);
    }
    newNode->data = item;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
}
void RemoveNode(Node *root,Node *last,Node *node)
{
    if(node == root){           /** IF root node is the desired node to delete **/
        head = node->next;
        free(node);
    }
    else{
        Node *currNode = node;
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        if(nextNode != NULL)
            nextNode->prev = prevNode;
        free(currNode);
    }
}
void Prepend(Node *root,Node *last,int item)    /** Add node as starting node **/
{
    Node *newNode = CreateNode(item , NULL , root);
    root->prev = newNode;
    head = newNode;
    if(root == NULL)
        tail = newNode;
}
void Append(Node *root,Node *last,int item)   /** Add node as ending node **/
{
    Node *newNode;
    if(root == NULL){   /** IF the list is empty,then the new node will be the head & tail **/
        newNode = CreateNode(item , NULL , NULL);
        head = newNode;
        tail = newNode;
    }
    else{
        newNode = CreateNode(item , last , NULL);
        last->next = newNode;
        tail = newNode;
    }
}
void Insert(Node *node,int item)
{
    Node *newNode = CreateNode(item , node , node->next);
    node->next->prev = newNode;
    node->next = newNode;
}
void ForwardPrint(Node *root)
{
    printf("Printing the list forward:\n");
    Node *currNode = root;
    while(currNode != NULL){
        cout<<currNode->data<<endl;
        currNode = currNode->next;
    }
}
void BackwardPrint(Node *last)
{
    printf("Printing the list backward:\n");
    Node *currNode = last;
    while(currNode != NULL){
        cout<<currNode->data<<endl;
        currNode = currNode->prev;
    }
}
Node *FloydsCycleFindAlgo(Node *start)  /** Find cycle in O(n) **/
{
    if(start->next == NULL)return NULL;

    Node *tortoise = start;
    Node *hare = start;

    ///check if there is a cycle
    while(hare){
        if(hare->next!=NULL && hare->next->next!=NULL)
            hare = hare->next->next;
        else
            return NULL;    ///no cycle
        tortoise = tortoise->next;
        if(hare == tortoise)
            break;      ///Cycle exist
    }
    Node *tortoise2 = start;
    while(tortoise2 != tortoise){
        tortoise2 = tortoise2->next;
        tortoise = tortoise->next;
    }
    return tortoise;
}
void PrintCycle(Node *start)
{
    Node *currNode = start->next;
    printf("\nDesired Cycle: \n%d ",start->data);
    while(currNode != start){
        printf("%d ",currNode->data);
        currNode = currNode->next;
    }
    pf("\n");
}

int main()
{
    int i,j,k,n,val;
    printf("Enter the number of node: ");
    scin(n);
    for(i=1 ; i<=n ; i++){
        scin(val);
        Append(head , tail , val);
    }
    tail->next = head->next->next->next;

    Node *start = FloydsCycleFindAlgo(head);
    printf("Cycle starts from %d\n",start->data);
    PrintCycle(start);
    return 0;
}
/**
10
20 45 12 42 90 67 15 28 64 85
**/
