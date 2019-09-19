#include<bits/stdc++.h>
using namespace std;
void Find_(int coin1[],int n,int tk)
{
    int mat[n+1][tk+1];
    int coin[n+1];
    mat[0][0] =0;

    for(int j=0; j<n; j++)
    {
        coin[j+1]=coin1[j];
    }coin[0]=99999;
    for(int i=1; i<=tk; i++)
    {
        mat[0][i] = 9999999;//INF
    }
    for(int i=1; i<=n; i++)
    {
        mat[i][0] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=tk; j++)
        {
            if((j-coin[i])<0)
            {
                //cout<<j-coin[i]<<"hi"<<endl;
                mat[i][j] = mat[i-1][j];
            }
            else
            {
                //cout<<"bye"<<endl;
                mat[i][j] = min(mat[i-1][j],mat[i][j-coin[i]]+1);
            }
        }//cout<<endl;
        //cout<<"LOOP Close"<<endl;

    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=tk; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Value is "<<mat[n][tk]<<endl;

}
int main()
{
    int coin[] = {2,3};
    int tk = 6;
    int n = sizeof(coin)/sizeof(coin[0]);
    Find_(coin,n,tk);
}
