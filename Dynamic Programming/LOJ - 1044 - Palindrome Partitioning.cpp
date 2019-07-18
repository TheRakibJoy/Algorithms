/** Palindrome Partitioning **/
/** Count minimum possible number of substrings in a palindrome partition of a string **/
/** Concept of longest palindromic substring + DP **/
int minPalPartition(char str[])
{
    int n=strlen(str),i,j,k,L;
    bool isPal[n][n];   /** isPal[i][j]=true if str[i..j] is a palindrome **/
    int dp[n];       /** Minimum number of cuts needed for palindrome partitioning of substring str[0..i] **/
    for(i=0 ; i<n ; i++)
        isPal[i][i]=1; /** Every one length substring is a palindrome **/
    for(L=2 ; L<=n ; L++)   /** Build solution for L size substring **/
    {
        for(i=0 ; i<n-L+1 ; i++)    /** From index i,take a L length substring **/
        {
            j=i+L-1;    /** Here j is the ending index **/
            if(L == 2)
                isPal[i][j] = (str[i]==str[j]); /** If two character matched,then its a palindrome **/
            else
                isPal[i][j] = (str[i]==str[j]) && isPal[i+1][j-1];  /** IF str[i+1...j-1] is a palindrome and str[i]==str[j] **/
        }
    }
    for(i=0 ; i<n ; i++)
    {
        if(isPal[0][i] == true)
            dp[i]=0;
        else
        {
            dp[i] = infinity;
            for(j=0 ; j<i ; j++)
            {
                /** If str[j+1...i] is a palindrome & min cut of str[0..j]+1 < min cut of str[0..i] then update min cut of str[0..i] **/
                if(isPal[j+1][i]==true && 1+dp[j]<dp[i])
                    dp[i] = 1+dp[j];
            }
        }
    }
    return 1+dp[n-1]; /** Return the min cut value for complete string **/
}
int main()
{
    int t,T,ans;
    scin(T);
    RUN_CASE(t,T)
    {
        char s1[1005];
        sc("%s",s1);
        ans = minPalPartition(s1);
        pf("Case %d: %d\n",t,ans);
    }
    return 0;
}

