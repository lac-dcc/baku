#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef unordered_map<int,int> umii;
typedef unordered_set<int> usi;
 
typedef unordered_map<ll, ll> umll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef unsigned long long int ull;
typedef long double lld;
 
#define      fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define      F first
#define      S second
#define      f(i,n) for (int i = 0; i < n; i++)
#define      fr(i,n) for(int i=(int)n-1;i>=0;--i)
#define      fo(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define      pb push_back
#define      pob pop_back
#define      mp make_pair
#define      maxheap priority_queue<ll>
#define      minheap  priority_queue<ll, vector<ll>, greater<ll> >
#define      fix(x) fixed<<setprecision(x)
#define      mod    1000000007
 
#define      display(v) for(int i =0;i<(int)v.size();++i)cout << v[i] << " "
#define      all(v) v.begin(),v.end()
#define      rall(v) v.rbegin(),v.rend()
 
 
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define inf 1e9
 
/* starts from here */
 
void solve()
{
    int n,sum;
    cin>>n>>sum;
 
    vll a(n),dp(sum+1,inf);
 
    for(int i=0;i<n;i++)
        cin>>a[i];
    dp[0]=0;
 
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=a[j])
                dp[i]=min(dp[i],1+dp[i-a[j]]);
        }
    }
 
    if(dp[sum]==inf)
        cout<<"-1"<<endl;
    else
        cout<<dp[sum]<<endl;
 
 
 
 
}
 
 
 
int main() 
{
fast;
#ifndef ONLINE_JUDGE
  freopen("Error1.txt", "w", stderr);
#endif
 
 
  solve();
 
 
}
 