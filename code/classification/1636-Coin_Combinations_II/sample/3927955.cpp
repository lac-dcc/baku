#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define pb push_back
#define mp make_pair
#define lli long long int
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define mii map<lli,lli>
#define msi map<string,lli>
#define pii pair<lli,lli> 
#define vi vector<lli> 
#define vii vector<pair<lli,lli>> 
#define vvi vector< vector<lli> >
#define sz(x) (lli)x.size()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX1 998244353
#define MAX2 1000000007
 
// Policy based data structure 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> Ordered_set;
// Ordered_set s;
// *s.find_by_order(a);
// s.order_of_key(a);
// s.erase(s.find_by_order( s.order_of_key(v[i-k]) ));
 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define input(data,n,command) for(lli i=0;i<n;i++){lli tmp;cin>>tmp;data.pb(tmp);command}
#define sort_asc(a) sort(a.begin(),a.end());
//#define sort_desc(a) sort(a.begin(),a.end(),greater<lli>());
#define display(a) for(lli i = 0 ;i<a.size();i++){cout<<a[i]<<" ";} cout<<endl;
#define rep(i,a,b) for(lli i = a;i < b;i++)
#define endl "\n"
#define INF 1000000000000000000
#define MAXN 100010
 
//Written By MUDIT BHARDWAJ...
/*--------------------------------------------------------------------*/
//vector<pair<lli,lli>>adj[300010];
 
lli solve()
{
    //auto start = chrono::steady_clock::now();
 
    //start from here
    lli n,x;
    cin>>n>>x;
    vector<lli> v;
    rep(i,0,n)
    {
        lli z;
        cin>>z;
        v.pb(z);
    }
    sort(all(v));
    lli dp[x+1];
    rep(i,0,x+1)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(auto z : v)
    {
        for(lli i = 1;i<=x;i++)
        {
            if(i - z >= 0)
            {
                dp[i] += dp[i-z];
                dp[i] %= MAX2;
            }
        }
    }
    cout<<dp[x];
    
 
    //auto end = chrono::steady_clock::now();
    //cout << "Elapsed time in milliseconds : "<< chrono::duration_cast<chrono::milliseconds>(end - start).count()<< " ms" << endl;
    return 0;
}
 
int main()
{
    ios
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli T=1;
    //cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
/*-----------------------------------------------------------------------*/
