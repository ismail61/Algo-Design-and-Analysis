#include<bits/stdc++.h>
using namespace std;
int Lis_ALternative_odd_even_Sequence(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i] && (arr[i]+arr[j])%2!=0)
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index = 0;

    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    //cout<<maxx<<" "<<index<<endl;
    int lis = maxx;
    vector<int>v;
    for(int i=index; i>=0; i--)
    {
        cout<<i<<" "<<maxx<<endl;
        if(lis_arr[i]==maxx && (lis_arr[i-1]+1)==lis_arr[i] && arr[i]>arr[i-1] )
        {
            cout<<"ji"<<endl;
            if(arr[i]<=arr[index])
            {
                v.push_back(arr[i]);
                v.push_back(arr[i-1]);
            }
            cout<<arr[i]<<" "<<arr[i-1]<<endl;
            maxx--;

        }


    }
    for(int i=v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return lis;
}
int Lis_Even_Sequence(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i] && arr[i]%2==0)
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index = 0;

    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    int lis = maxx;
    vector<int>v;
    for(int i=index; i>=0; i--)
    {
        if(lis_arr[i]==maxx&& arr[index]%2==0)
        {
            v.push_back(arr[i]);
            maxx--;
        }
    }
    for(int i=v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return lis;
}
int Lis_Odd_Sequence(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i] && arr[i]%2!=0)
            {
                lis_arr[i] = lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index = 0;

    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    int lis = maxx;
    vector<int>v;
    for(int i=index; i>=0; i--)
    {
        if(lis_arr[i]==maxx&& arr[index]%2!=0)
        {
            v.push_back(arr[i]);
            maxx--;
        }
    }
    for(int i=v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return lis;
}
int Lis_normal(int arr[],int n)
{
    int lis_arr[n+1];
    for(int k=0; k<n; k++)
    {
        lis_arr[k]=1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis_arr[j]+1>lis_arr[i])
            {
                lis_arr[i]=lis_arr[j]+1;
            }
        }
        cout<<"For elements "<<arr[i]<<" Lis(array) is : ";
        for(int k=0; k<n; k++)
        {
            cout<<lis_arr[k]<< " ";
        }
        cout<<endl;
    }
    int maxx = 0,index=0;
    for(int k=0; k<n; k++)
    {
        if(maxx<lis_arr[k])
        {
            maxx = lis_arr[k];
            index = k;
        }
    }
    int lis = maxx;
    vector<int>v;
    for(int i=index; i>=0; i--)
    {
        if(lis_arr[i]==maxx)
        {
            v.push_back(arr[i]);
            maxx--;
        }
    }
    for(int k=v.size()-1; k>=0; k--)
    {
        cout<<v[k]<< " ";
    }
    cout<<endl;
    return lis;
    //cout<<maxx<<" "<<index<<" "<<arr[index];
    //return *max_element(lis_arr,lis_arr+n);
}
int main()
{
    int arr[] = {10,22,9,11,33};
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout<<"LIS is : "<<Lis_normal(arr,n)<<endl;
    //cout<<"Lis Odd Sequence is : "<<Lis_Odd_Sequence(arr,n)<<endl;
    //cout<<"Lis Even Sequence is : "<<Lis_Even_Sequence(arr,n)<<endl;
    cout<<"Lis ALternative odd/even Sequence is : "<<Lis_ALternative_odd_even_Sequence(arr,n)<<endl;
}
