#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ve vector <ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
 
#define all(x) (x).begin(),(x).end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define print(arr) for (int i = 0; i < arr.size(); ++i){cout<<arr[i]<<" ";}enl
 
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
#define enl cout<<"\n";
#define en "\n"
#define sp cout<<fixed<<setprecision(6)
 
const ll mod = 1000000007;
const ll INF = 1e15;
const ll N = 1e6;
//----------------------------------------------------------
 
// optimization -> binary search 
 
void solve(){
 
ll n,m,out=0;
cin>>n>>m;
 
vector <pll> arr[n+1];
 
for (int i = 0; i < m; ++i)
{
    ll a,b,c;
    cin>>a>>b>>c;
    arr[a].pb(mp(b,c));
}
 
set <pll> s;
s.insert(mp(0,1));
 
ve dis(n+1,INF);
vector <bool> vis(n+1,0);
dis[1]=0;
 
// for (int i = 1; i < n+1; ++i)
// {
//     cout<<i<<"::";
//     for (int j = 0; j < arr[i].size(); ++j)
//     {
//         cout<<"("<<arr[i][j].ff<<"-"<<arr[i][j].ss<<") ";
//     }
//     enl
// }
// return;
 
while(s.size())
{
    ll par=s.begin()->ss;
    s.erase(s.begin());
    
    if(vis[par])
        continue;
    
    vis[par]=1;
    
    for (int i = 0; i < arr[par].size(); ++i)
    {
        ll child=arr[par][i].ff;
        ll cost=arr[par][i].ss;
        
        if(cost+dis[par]<dis[child])
        {
            dis[child]=cost+dis[par];
            s.insert(mp(dis[child],child));
        }
    }
}
 
s.clear();
 
ve dis2(n+1,INF),mx(n+1,0);
vector <bool> vis2(n+1,0);
dis[1]=0;
 
s.insert(mp(0,1));
dis2[1]=0;
 
while(s.size())
{
    ll par=s.begin()->ss;
    s.erase(s.begin());
    
    if(vis2[par])
        continue;
    
    vis2[par]=1;
    
    for (int i = 0; i < arr[par].size(); ++i)
    {
        ll child=arr[par][i].ff;
        ll cost=arr[par][i].ss;
        
        ll d=dis2[par]+cost;
        
        if(cost>mx[par])
        {
            d=dis[par]+cost/2;
        }
        
        if(d<dis2[child])
        {
            dis2[child]=d;
            mx[child]=max(mx[par],cost);
            s.insert(mp(dis2[child],child));
        }
    }
}
// for (int i = 0; i < n; ++i)
// {
//     cout<<dis2[i+1]<<" "<<mx[i+1]<<en;
// }
 
cout<<dis2[n]<<en;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
}
 
//----------------------------------------------------------
 
int main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL); 
   
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
 
#ifdef SIEVE
    sieve();
#endif
 
#ifdef FACTORIAL
    factorial();
#endif
 
ll testcases=1;
// cin>>testcases;
while(testcases--){solve();}
 
 
}
