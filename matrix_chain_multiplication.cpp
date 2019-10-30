#include<bits/stdc++.h>
using namespace std;
int main(){
    int p[5] = {5, 4, 6, 2, 7};
    int mat[4]={0,1,2,3};
    int n=5,min_,j;
    int m[5][5],s[5][5];
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){
            j = i+d;
            min_ = 99999;
            for(int k=i;k<j;k++){
                int q = m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<min_){
                    min_ = q;
                    s[i][j]=k;
                }
            }
            m[i][j] = min_;
        }
    }
    printf("%d\n",m[1][n-1]);///raw 1 r last upadan
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            cout<<s[i][j]<<" ";
        }cout<<endl;
    }
}
