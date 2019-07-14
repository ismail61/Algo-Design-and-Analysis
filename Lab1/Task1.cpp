
#include<bits/stdc++.h>
using namespace std;
long long m = 100000000;
long long Hash(string s, int radix, long long m)
{
        long long hash = 0;
        for(int i=0; i<s.length(); ++i) {

                hash = (hash * radix + s[i]) % m;
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
    while(i!=10){
            cin>>s;
            long long hi = Hash(s,radix,m);
            //cout<<hi<<endl;
            v.insert(hi);
            i++;
    }
    cout<<v.size();

}
