/** * * * * * * * * * * * * * **\
 *                             *
 *   Author: Haidara Nassour   *
 * Coded in: YYYY\M\D HH:MM:SS *
 *          Lang: C++          *
 *                             *
\** * * * * * * * * * * * * * **/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define rep(i,x,n) for(int i=(x);i<(n);i++)
#define FOR(i,n) rep(i,0,n)
#define per(i,x,n) for(int i=(x);i>(n);i--)
#define ROF(i,x) for(int i=x;i>=0;i--)
#define v(i) vector< i >
#define p(i,j) pair< i , j >
#define pii pair<int,int>
#define m(i,j) map< i , j >
#define um(i,j) unordered_map< i , j >
#define max_heap(i) priority_queue< i >
#define min_heap(i) priority_queue< i , vector< i > ,greater< i > >
#define ff first
#define all(x) x.begin(),x.end()
#define ss second
#define pp push_back
#define mini(x,y) x=min(x,y);
#define maxi(x,y) x=max(x,y);
#define debug(x) cout<<#x<<" = "<<x<<" : ";
using namespace std;
using namespace __gnu_pbds;
void SIO(string name="")
{
    if(name!="")
    {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}
template <class T> using o_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///order_of_key = find index of element x ( returned val is integer )
///find_by_order = find value at index x ( returned val is pointer )
const int inf=1LL<<62LL;
const int mod=1e9+7;
const int maxn=2000200;
v(int)dp(maxn);
signed main()
{
    SIO("");
    int n,k;
    cin>>n>>k;
    v(int)a(n);
    FOR(i,n)
    cin>>a[i];
    dp[0]=1;
    FOR(i,maxn)
    {
        for(auto j:a)
        {
            if(i+j>=maxn)
                continue;
            dp[i+j]+=dp[i];
            dp[i+j]%=mod;
        }
    }
    cout<<dp[k];
}