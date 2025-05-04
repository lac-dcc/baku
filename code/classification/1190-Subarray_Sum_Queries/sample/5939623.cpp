#define TASK "test"
#include<bits/stdc++.h>
using namespace std; 
 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
struct bg{
	ll sum,l,r,res;
};
const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=16;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA
ll n,m,a[N];
bg st[4*N];
bg combine(bg x,bg y){
	ll s=x.sum+y.sum;
	ll mar=max(y.r,y.sum+x.r);
	ll mal=max(x.l,x.sum+y.l);
	ll res=max({x.res,y.res,x.r+y.l});
	return {s,mal,mar,res};
}
void update(ll id,ll l,ll r,ll u,ll val){
	if(u<l || u>r) return;
	if(l==r){
		st[id]={val,val,val,val};
		return;
	}
	ll mid=(l+r)/2;
	update(id*2,l,mid,u,val);
	update(id*2+1,mid+1,r,u,val);
	st[id]=combine(st[id*2],st[id*2+1]);
}
 
// bg get(ll id,ll l,ll r,ll u,ll v){
// 	if(v<l || u>r) return {-inf,inf,};
// 	if(u<=l && r<=v) return st[id];
// 	ll mid=(l+r)/2;
// 	return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
// }
 
void read()
{
	cin>>n>>m;
	f(i,1,n) cin>>a[i];
	//f(i,1,n) s[i]=s[i-1]+a[i];
}
 
 
void solve()
{
	f(i,1,n) update(1,1,n,i,a[i]);
	while(m--){
		ll w,u,v;
		cin>>u>>v;
		update(1,1,n,u,v);
		cout<<max(st[1].res,(ll)0)<<el;
	}
}
signed main()	
{
	if (fopen(TASK".INP", "r"))
	{
		freopen(TASK".INP", "r", stdin);
		freopen(TASK".OUT", "w", stdout);
	}
	fast;
    int test =1; 
  //  cin>>test;
   while(test--)
    {
        read(); 
        solve();
    }
    cerr << "\nTime: " << clock() << "ms\n";
}	
