#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define scanit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cin>>a[indexaa];
#define printit(a,n) for(ll indexaa=0; indexaa<n; indexaa++) cout<<a[indexaa]<<" "; cout<<endl;
#define pb push_back
#define mp make_pair
#define precision(a) cout<<fixed<<setprecision(a)
#define testcase ll t; cin>>t; while(t--)
#define endl "\n"
#define iendl "\n", cout<<flush // FOR INTERACTIVE PROBLEMS
#define getlineinput(a) cin>>ws; getline(cin,a); // CIN>>WS TO CLEAR THE INPUT BUFFER AS GETLINE INCLUDES SPACES FROM JUST THE START
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,b) for(ll i=a; i<b; ++i)
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define PI 3.141592653589793238462
using namespace std;
const ll M = 1000000007;
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}\
ll visited[1001][1001];
char arr[1001][1001];
ll n,m;
void inititalize(ll n, ll m)
{
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            arr[i][j]=0;
        }
    }
}
void dfs(ll i, ll j)
{
    visited[i][j]=1;
    ll dir[2] = {1,-1};
    for(ll k=0; k<2; k++)
    {
        if((i+dir[k])<n && (i+dir[k])>=0 && visited[i+dir[k]][j]==0 && arr[i+dir[k]][j]=='.')
        {
            dfs(i+dir[k],j);
        }
        if(j+dir[k]<m && j+dir[k]>=0 && visited[i][j+dir[k]]==0 && arr[i][j+dir[k]]=='.')
        {
            dfs(i,j+dir[k]);
        }
    }
}
int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n>>m;
    inititalize(n,m);
    forl(i,0,n)
    {
        forl(j,0,m)
        {
            cin>>arr[i][j];
        }
    }
    ll cc = 0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(!visited[i][j] && arr[i][j]=='.')
            {
                dfs(i,j);
                cc++;
            }
        }
    }
    cout<<cc<<endl;
    timetaken;
    return 0;
}


