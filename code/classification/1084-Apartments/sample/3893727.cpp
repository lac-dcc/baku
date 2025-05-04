#include<bits/stdc++.h>
 
using namespace std;
 
 #ifndef ONLINE_JUDGE 
#include<D:\Coding_and_Web\debug.cpp>
 
#else// online submission 
 
#endif 
 
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
 
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end()) 
#define sz(x) (int)((x).size())
 #define ll long long
 #define eps 1e-6
#define mod 1000000007
#define pi (3.141592653589)
#define ull uint64_t 
#define cmp [] (const auto &l, const auto &r) {return l > r;}
#define fi first
#define se second
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem1(a) memset(a,-1,sizeof(a) )
#define mem0(a) memset(a,0,sizeof(a) ) 
#define rrep(i,n) for(int i=n-1;i>=0;i--)
 
#define pb push_back
#define vi vector<int>
 
#define int int64_t
 
 
 
 
 
 
void solve()
{
 
    int n,m,k;
    cin>>n>>m>>k;
    multiset<int> v;
    vector<int> a(m);
    rep(i,0,n)
    {
        int x;
        cin>>x;
        v.insert(x);
    }
    rep(i,0,m)
    {
        cin>>a[i];
    }
    int ans=0;
    // debug(v);
    sort(all(a));
    for(int i=0;i<m;i++)
    {
        
        auto it=v.lower_bound((a[i]-k));
        // cout<<*it<<endl;
        if(it!=v.end() and *it>=a[i]-k and *it<=a[i]+k)
        {
            v.erase(v.find(*it));
            ans++;
        }
 
    }
    // for(auto x:v)cout<<x<<" "<<endl;
    cout<<ans<<endl;
    
 
}
 
 
 
signed  main ()
 
{
 IOS
 uint32_t test_case=1;
#ifndef ONLINE_JUDGE
 //freopen( "input.txt"  , "r"  , stdin);
 //freopen("output.txt","w",stdout);
#endif
 
 while(test_case --){
 
solve();
}  
return 0;
}
