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

/** BinarySearchTree Template **/
typedef struct tree
{
    int number;
    struct tree *leftChild;
    struct tree *rightChild;
}node;

node *root = NULL;

void insertNode(int value)
{
    node *tempNode;
    node *currentNode;
    node *parentNode;

    tempNode = (node *)malloc(sizeof(node));
    tempNode->number = value;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if(root == NULL)     ///For the very first call
        root = tempNode;
    else{
        currentNode = root;
        parentNode = NULL;
        while(1){
            parentNode = currentNode;

            if(value <= parentNode->number){    /** If value <= parentNode->number , then it will be inserted under leftChild of this node , under rightChild otherwise **/
                currentNode = currentNode->leftChild;

                if(currentNode == NULL){
                    parentNode->leftChild = tempNode;
                    return;
                }
            }
            else{
                currentNode = currentNode->rightChild;

                if(currentNode == NULL){
                    parentNode->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}
void searchOnTree(int value)
{
    node *currentNode = root;
    int fg = 0;
    while(1){
        if(value == currentNode->number){
            fg = 1;
            break;
        }
        else if(value <= currentNode->number)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
        if(currentNode == NULL)
            break;
    }
    if(fg)
        pf("\n%d is found on tree.\n",currentNode->number);
    else
        pf("\n%d is not found on tree.\n",value);
}
void preOrderPrint(node *rootNode)  /// Node - leftSubTree - rightSubTree
{
    if(rootNode == NULL)
        return;
    printf("%d ",rootNode->number);
    preOrderPrint(rootNode->leftChild);
    preOrderPrint(rootNode->rightChild);
}
void inOrderPrint(node *rootNode)   /// leftSubTree - Node - rightSubTree
{
    if(rootNode == NULL)
        return;
    inOrderPrint(rootNode->leftChild);
    printf("%d ",rootNode->number);
    inOrderPrint(rootNode->rightChild);
}
void postOrderPrint(node *rootNode) /// leftSubTree - rightSubTree - Node
{
    if(rootNode == NULL)
        return;
    postOrderPrint(rootNode->leftChild);
    postOrderPrint(rootNode->rightChild);
    printf("%d ",rootNode->number);
}
node* findMaxRecursive(node *rootNode)  /// Find maximum value of BST
{
    if(rootNode->rightChild == NULL)
        return rootNode;    /// number of rootNode is the maximum value
    return findMaxRecursive(rootNode->rightChild);
}
node* findMinRecursive(node *rootNode)  /// Find minimum value of BST
{
    if(rootNode->leftChild == NULL)
        return rootNode;    /// number of rootNode is the minimum value
    return findMinRecursive(rootNode->leftChild);
}
node* deleteNode(node *currentNode,int value)
{
    if(currentNode == NULL)     /// If it is an empty tree
        return NULL;
    else if(value < currentNode->number)    /// value is less than node's number. so go to left subtree
        currentNode->leftChild = deleteNode(currentNode->leftChild , value);
    else if(value > currentNode->number)    /// value is greater than node's number. so go to right subtree
        currentNode->rightChild = deleteNode(currentNode->rightChild , value);
    else{   /// node found. Let's delete it!
        if(currentNode->leftChild==NULL && currentNode->rightChild==NULL)   /// IF node has no child
            currentNode = NULL;
        else if(currentNode->leftChild == NULL)     /// IF node has only right child
        {
            currentNode = currentNode->rightChild;
        }
        else if(currentNode->rightChild == NULL)    /// IF node has only left child
        {
            currentNode = currentNode->leftChild;
        }
        else{   /// IF node has both two children.
            node *tempNode = findMinRecursive(currentNode->rightChild);
            currentNode->number = tempNode->number;         /** Minimum value of right subtree will be the current node to maintain the property of BST **/
            currentNode->rightChild = deleteNode(currentNode->rightChild , tempNode->number);   /** Original minimum value of right subtree have to be deleted **/
        }
    }
    return currentNode;
}
/**
    Check IF a Binary Tree is BST or NOT?
    Logic: Every node has an upper limit & a lower limit. For root node it is [-infinity , infinity]
    1. Lower limit of rightChild of a parent is the value of parent. And upper limit of rightChild of a parent is the upper limit of that parent.
    2. Lower limit of leftChild of a parent is the lower limit of that parent. And upper limit of leftChild of a parent is the value of parent.
    IF value of every node is within the range [lowerLimit , upperLimit] , then it will be a BST.
**/
int isBST(node *rootNode,int mn,int mx) /// Initially, mn = -infinity ; mx = infinity
{
    if(rootNode == NULL)return 1;

    if((rootNode->number>=mn && rootNode->number<mx) && isBST(rootNode->leftChild,mn,rootNode->number) && isBST(rootNode->rightChild,rootNode->number,mx))
        return 1;
    return 0;
}

int main()
{
    int i,j,k,x,n;
    printf("Enter number of node in BST: ");
    scin(n);
    /// Test Insert Function
    rep(i,1,n)
    {
        scin(x);
        insertNode(x);
    }

    /// Test Traverse Function
    pf("Preorder Traversal: ");
    preOrderPrint(root);    cout<<endl;
    pf("Inorder Traversal: ");
    inOrderPrint(root);     cout<<endl;
    pf("Postorder Traversal: ");
    postOrderPrint(root);   cout<<endl<<endl;

    /// Test Maximum,Minimum Value
    node *mxnode = findMaxRecursive(root);
    pf("Max value of %d rooted subtree: %d\n",root->number,mxnode->number);
    node *mnnode = findMinRecursive(root);
    pf("Min value of %d rooted subtree: %d\n",root->number,mnnode->number);

    /// Test Delete & Search Function
    node *tempNode = deleteNode(root , 30);
    searchOnTree(30);

    /// Test isBST Function
    if(isBST(root,-infinity,infinity))
        pf("It is a BST.\n");
    else
        pf("It is not a BST.\n");
    return 0;
}
/**
11
45 54 40 49 38 70 30 39 41 45 44
14
47 40 54 38 43 49 39 45 44 30 41 70 46 59
**/
