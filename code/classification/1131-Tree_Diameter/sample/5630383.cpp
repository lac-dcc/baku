#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vll vector<pll>
#define vvl vector<vector<long long>>
#define loop(x,n) for(int x = 0; x < n; ++x)
#define rep(i,a,b)for(int i=a;i<=b;i++)
#define repr(i,a,b)for(int i=b;i>=a;i--)
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const ll MOD = 1e9 + 7;
#define endl "\n"
void vin(vi &v){int n=v.size();loop(i,n)cin>>v[i];}
void vout(vi &v){int n=v.size();loop(i,n)cout<<v[i]<<" "; cout<<endl;}
void vin(vl &v){int n=v.size();loop(i,n)cin>>v[i];}
void vin(vii &v){int n=v.size(); loop(i,n){cin>>v[i].first>>v[i].second;}}
void vin(vll &v){int n=v.size(); loop(i,n){cin>>v[i].first>>v[i].second;}}
void vout(vl &v){int n=v.size();loop(i,n)cout<<v[i]<<" "; cout<<endl;}
ll doit(vvi& v,ll n,ll source,ll &ans,ll par)
{ll max1=0,max2=0;
for(auto it:v[source])
{if(it==par)continue;
    ll res=doit(v,n,it,ans,source);
if(res>max1){max2=max1; max1=res;}
else if(res>max2)max2=res;}
ans=max(ans,1+max1+max2);
return 1+max(max1,max2);
}
void solve() {
    ll n;cin>>n; vvi v(n);
    loop(i,n-1)
    {ll x; cin>>x; x--; ll y; cin>>y; y--;
    v[x].push_back(y);
    v[y].push_back(x);}
    ll ans=0;
    ll x=doit(v,n,0,ans,-1);
    cout<<ans-1<<endl;
 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //factMaker(100005,MOD);
    //TxtIO;
    int tc = 1;
    //  cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
