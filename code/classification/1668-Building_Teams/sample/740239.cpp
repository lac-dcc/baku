#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define FOD(i,a,b) for(ll i=(a);i>=(b);--i)
#define name "a"
#define pb push_back
typedef pair < ll , ll > ii;
const ll maxn=1e6+7,oo=1e18,mod=1e9+7;
ll n,m,x,y,ok[maxn],res[maxn],d[maxn];
vector < ll > a[maxn];
void dfs(int i)
{
    ok[i]=1;
    for(int j:a[i])
    {
        if(!ok[j])
        {
            d[j]=d[i]+1;
            if(d[j]%2==0)
                res[j]=1;
            else res[j]=2;
            dfs(j);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    #endif // ONLINE_JUDGE
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    FOR(i,1,n)
    {
        if(!ok[i])
        {
            d[i]=0;
            res[i]=1;
            dfs(i);
        }
    }
    FOR(i,1,n)
    {
        for(int j:a[i])
            if(res[i]==res[j])
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
    }
    FOR(i,1,n)
        cout<<res[i]<<" ";
}
