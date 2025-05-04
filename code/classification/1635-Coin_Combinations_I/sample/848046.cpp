#include<bits/stdc++.h>
#define ll long long int
#define vpii vector< pair<int,int> >
#define vpll vector< pair<ll,ll> >
#define mp(a,b) make_pair(a,b)
#define mpii map<int,int>
#define mpll map<ll,ll>
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define s(v) v.size()
#define test ll t;cin>>t;while(t--)
#define vec vector<ll>
#define  pb(a) push_back(a)
#define read0(v,n) for(int i=0;i<n;i++)cin>>v[i];
#define read1(v,n) for(int i=1;i<=n;i++)cin>>v[i];
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    vec v(x+1);
    vec coins(n);read0(coins,n);
   // sort(all(coins));
    v[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int j:coins)
        {
            if(i-j>=0) v[i]=(v[i]+v[i-j])%MOD;
        }
    }
    cout<<v[x];
}
