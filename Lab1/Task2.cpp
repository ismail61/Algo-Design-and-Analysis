#include<bits/stdc++.h>
using namespace std;
long long m = 100000000;
long long Hash(string s, int radix, long long m)
{
        int r = s.length();
        int hash = 0;
        int i, j;
        for(i=r-1; i>=0; --i)
        {
                int ans = s[i];
                for(j=r-i-1; j>0; --j)
                {
                        ans *= radix;
                        ans %= m;
                }
                hash += ans;
                hash %= m;
        }
        return hash;
}
int main()
{

    int radix;
    string s;
    cin>>radix;
    set<int>v;
    int i=0;
    while(i!=5){
            cin>>s;
            long long hi = Hash(s,radix,m);
            //cout<<hi<<endl;
            v.insert(hi);
            i++;
    }
    cout<<v.size();

}
