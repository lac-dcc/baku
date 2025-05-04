#include<bits/stdc++.h>
#define INF 1e9
#define m 1000000007
using namespace std;
 
int main()
{
    int n,x;
    cin>>n>>x;
    int c[n];
    //int a[x+1]={1};
    vector<int> a(x + 1, 1); 
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<=x;i++)
            if(i+c[j]<=x)
        {
            a[i+c[j]]+=a[i];
            a[i+c[j]]%=m;
        }
 
    }
    cout<<a[x];
}
