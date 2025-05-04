#include<bits/stdc++.h>
#define fort(i,a,b) for(long i=a;i<=b;i++)
#define forn(i,a,b) for(long i=a;i>=b;i--)
#define x first
#define y second
#define MP make_pair
#define pb push_back
#define ii pair<long ,long >
#define MT make_tuple
#define tp tuple
bool getbit(long x,long y)
{
    return (x>>y)&1;
}
using namespace std;
 
int main()
{
    //freopen("swmr.inp","r",stdin);
    //freopen("swmr.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,sum=0,rs=-1e9;cin>>n;
    fort(i,1,n)
    {
        int x;
        cin>>x;
        sum+=x;
        rs=max(rs,sum);
        sum=max(sum,0ll);
    }
    cout<<rs<<'\n';
}
