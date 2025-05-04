#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define    common(a,b)      SORT(a), SORT(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define    uncommon(a,b)    SORT(a), SORT(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
#define    minv(v)         *min_element(all(v))
#define    maxv(v)         *max_element(all(v))
#define    SORT(v)          sort(all(v))
#define    REV(x)           reverse(x.begin(),x.end())
#define    all(x)           x.begin(), x.end()
#define    rev(v)           reverse(all(v))
#define    unq(v)           sort(all(v)),v.erase(unique(all(v)),v.end())
#define    fr(i,x,n)        for(int i=x;i<n;i++)
#define    trav(a,x)        for (auto &a: x)
#define    sz(x)            (ll)(x).size()
#define    ll               long long int
#define    pb               push_back
#define    in               insert
#define    gcd(a, b)        __gcd(a, b)
#define    lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define    w(t)              cin>>t;while(t--)
const ll mod = 1000000007;
const double pi = acos(-1.0);
string str[]= {"YES","NO"};
int dx[]= {-1,0,1,0};
int dy[]= {0,-1,0,1};
/*bool check(int i,int j,int r,int c)
{
    if(i>=0 and i<r and j>=0 and j<c and vis[i][j]==false)return true;
    return false;
}*/
/*typedef tuple<ll,ll>ii;
typedef set<ii>stt;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>order_set;
order_set tt;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
pref_trie base;
*/
int main()
{
    _ios
    ll z;
    //w(z)
    //{
    ll n,m,a,b,c,d,e,x,y,mul=1,cn=0,cn1=0,cn2=0,sm=0,sm1=0,sm2=0,mx=-1e18,mx1=-1e8,mn=1e18,mn1=1e18,i,j,k,temp;
    string s,ss,st1,st2;
    char ch;
    set<ll>st;
    map<ll,ll>mp,mp1;
    bool f=true,ff=true;
    cin>>a;
    array<ll,3>ar[a];
    fr(i,0,a)cin>>ar[i][1]>>ar[i][0]>>ar[i][2];
    sort(ar,ar+a);set<array<ll,2>>dp;dp.in({0,0});
    fr(i,0,a)
    {
        auto it=dp.lower_bound({ar[i][1]});
        it--;mx=max((*it)[1]+ar[i][2],mx);
        dp.in({ar[i][0],mx});
    }
    cout<<mx<<endl;
    return 0;
}