#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[1010][1010];
int path[1010][1010];
int lcs(int i,int j)
{
    if(i<0 or j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j])
    {
        path[i][j] = 3;
        return dp[i][j] = 1+lcs(i-1,j-1);
    }
    else
    {
        int r1 = lcs(i-1,j);
        int r2 = lcs(i,j-1);
        if(r1>r2) path[i][j] = 2;
        else path[i][j] = 1;
        return dp[i][j] = max(r1,r2);
    }
}
void printpath(int i,int j)
{
    if(i<0 or j<0) return;
    if(path[i][j] == 3)
    {
        printpath(i-1,j-1);
        cout<<s1[i];
    }
    else if (path[i][j]==2)
    {
        printpath(i-1,j);
    }
    else if(path[i][j]==1)
    {
        printpath(i,j-1);
    }
}
int main()
{
    cin>>s1>>s2;
    int sizes1 = s1.size();
    int sizes2 = s2.size();
    memset(dp,-1,sizeof(dp));
    int lcscnt = lcs(sizes1-1,sizes2-1);
    cout<<"LCS Is : "<<lcscnt<<"\n";
    cout<<"LCS Path Is : ";
    printpath(sizes1-1,sizes2-1);
    cout<<endl;
    cout<<"Levenshtein Distance : "<<(sizes1-lcscnt)+(sizes2-lcscnt)<<endl;
    return 0;
}
/*
aeibcd
adeqijb
LCS Is : 4
LCS Path Is : aeib
Levenshtein Distance : 5
*/
