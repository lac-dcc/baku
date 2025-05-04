#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ve vector<ll>
#define ve_pa vector<pair<ll,ll> >
#define pb push_back
#define mod (ll)1000000007
#define INF (ll)5e18+7
#define ld long double 
#define pll pair<ll,ll>
#define fi first
#define se second
#define mll map<ll,ll>
#define m_ve map<ll,ve>
#define min3(x,y,z) min(x,min(y,z))
#define max3(x,y,z) max(x,max(y,z))
#define W(x) while(x--)
#define ld long double
#define all(x) x.begin(),x.end()
#define popcount(x) __builtin_popcountll(x)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//int dx[]={0,1,-1,0,0,1,-1,-1,1},dy[]={0,0,0,1,-1,1,-1,1,-1};	
const int N=5000005;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL); 
cout.tie(NULL);
int t;//cin>>t;
t=1;
while(t--)
{
ll n;cin>>n;
pll a[n];
for(int i=0;i<n;i++)
cin>>a[i].fi>>a[i].se;
 
sort(a,a+n);
ordered_set<ll>s;
ll ans=0;
for(int i=0;i<n;i++)
{
	ll x=s.order_of_key(a[i].fi);
	ans=max(ans,(ll)s.size()-x+1);
	s.insert(a[i].se);
} 
cout<<ans<<"\n";
 
 
}
 
 
 
}
