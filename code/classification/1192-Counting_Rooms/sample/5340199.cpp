#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FORb(i,n) for(int i=n;i>=0;i--)
#define vi vector<int>
#define pb push_back
#define print_array(array, length) \
for(int i = 0; i < length; i++) \
    cout<<( array[i])<<" ";
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
const long long mod = 1e9+7;
const long long inf = 1e18;
#define MP make_pair
#define REP(i,a,b) for( int i=(int)a;i<(int)b;i++)
#define el cout<<endl;
#define comp greater<int>()
#define sz(x) (int)(x).size()
#define vec_sort(a) sort(a.begin(),a.end())
#define vec_rev(a) reverse(a.begin(),a.end())
vector<vector<ll>>vis;
//ll val = 0;
ll dfs(vector<vector<char>>&Map,ll i,ll j,ll n,ll m)
{
//    val++;
    if(i>=n || j>=m || i<0 || j<0) return 0;
    if(Map[i][j]=='#') return 0;
    if(vis[i][j]==1) return 0;
//    cout<<"i = "<<i<<"j = "<<j<<endl;
    vis[i][j]=1;
    dfs(Map,i-1,j,n,m);
    dfs(Map,i+1,j,n,m);
    dfs(Map,i,j+1,n,m);
    dfs(Map,i,j-1,n,m);
    return 0;
}
 
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
//start
//ODD EVEN CONCEPT IS VERY IMPORTANT
ll n,m; cin>>n>>m;
vector<vector<char>>Map(n,vector<char>(m));
vis.resize(n,vector<ll>(m,0));
FOR(i,n)
{
    FOR(j,m)
    {
        cin>>Map[i][j];
    }
}
ll cnt=0;
FOR(i,n)
{
    FOR(j,m)
    {
        if(Map[i][j]=='.')
        {
            if(vis[i][j]==0)
            cnt++;
            dfs(Map,i,j,n,m);
        }
    }
}
cout<<cnt<<endl;
//cout<<"val : "<<val<<endl;
 
//END
}
