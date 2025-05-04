#include <bits/stdc++.h>
using namespace std;
 
#define IOS              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sortt(a)         sort(a.begin(),a.end())
#define stp(x)           fixed<<setprecision(x)
#define int              long long int
#define pb               push_back
#define PQ               priority_queue
#define F                first
#define S                second
#define mod              1000000007
#define endl             "\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
 
void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
long long dp[200004];
 
vector<int>start;
 
int find_next(vector<vector<int>>&intervals,int i)
{
    int idx = upper_bound(start.begin()+i+1,start.end(),intervals[i][1]) - start.begin();
    return idx;
}
 
long long func(vector<vector<int>>& intervals,int i)
{
    if(i>=intervals.size())     return 0;
 
    if(dp[i]!=-1)   return dp[i];
    int next = find_next(intervals,i);
 
    long long take = intervals[i][2] + func(intervals,next);
    long long not_take = func(intervals,i+1);
 
    return dp[i] = max(take,not_take);
}
 
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    
    sort(rides.begin(),rides.end());
    
    start.clear();
    for(auto i:rides)
    {
        start.push_back(i[0]);
    }
 
    for(int i=0;i<rides.size();i++)
    {
        dp[i] = -1;
    }
    return func(rides,0);
    
}
void solve()
{    
    int n; cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        int a,b,p; cin>>a>>b>>p;
 
        v.push_back({a,b,p});
    }
 
    int ans = maxTaxiEarnings(n,v);
 
    cout<<ans<<endl;
 
 
    
}
 
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
 
   int t=1; 
//    cin>>t;
   for(int i=0;i<t;i++)
   {
       solve();
   }
}
