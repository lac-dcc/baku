#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
 
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fo(i, n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define int long long int
#define gap " "
#define br "\n"
#define ins insert
#define PI 2 * acos(0.0)
#define isSet(n, i) bool(n & (1LL << i))
#define setBit(n, i) (n | (1LL << i))
#define unsetBit(n, i) (n & !(1LL << i))
#define print(x) cout<< #x <<" = "<< x<<endl;
#define double long double
#define allzero(x) memset(x,0,sizeof(x))
#define even(x) !(x&1)
#define odd(x) x&1
 
 
typedef pair<int, int> pii;
 
const int inf = 1e18;
const int MAXN = 2e5+5;
const int mod = 1e9+7;
const double pi = atan2(0, -1);
const double eps = 1e-7;
 
void debug(int n)
{
    cout<<"Okay "<<n<<endl;
}
 
int ceil2(int a, int b) {
    return (a + b - 1) / b;
}
 
int floor2(int a, int b) {
    return floor((double)a/(double)b);
}
 
int is_power_of_two(int x)
{
    if(!(x&(x-1)))
        return 1;
    return 0;
}
 
int Log(int n, int r)    // returns r base log n
{
    return (n > r - 1) ? 1 +
       Log(n / r, r) : 0;
}
 
struct pt{
 
    int x,y;
 
    pt(int a=0, int b=0)
    {
        x = a;
        y = b;
    }
 
    pt operator + (pt b)
    {
        pt c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }
 
    pt operator - (pt b)
    {
        pt c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }
    bool operator ==(pt b)
    {
        return (x==b.x && y==b.y);
    }
    bool operator !=(pt b)
    {
        return (!(x==b.x && y==b.y));
    }
 
    bool operator < (pt b)
    {
        if(x==b.x)
            return (y<b.y);
        return (x<b.x);
    }
 
    void show()
    {
        cout<<"x = "<<x<<" y = "<<y<<br;
    }
};
 
pt gridMoves[4] = {pt(1,0),pt(-1,0),pt(0,1),pt(0,-1)};
 
bool boundCheck(pt p, int n, int m)
{
    if(p.x>=0 && p.y>=0 && p.x<n && p.y<m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
/*
 
    cout<<fixed<<setprecision(6)<<value;
 
*/
 
/*
 
    cin>>n>>m;
 
    vector<int>d(n+5,inf);
    vector<int>parent(n+5,-1);
    vector<bool>vis(n+5,0);
    vector<int>adj[n+5];
 
    fo(i,m)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
*/
 
/*
 
    vector<int>a;
 
    a.clear();
 
    cin>>n;
 
    fo(i,n)
    {
        cin>>p;
        a.pb(p);
    }
 
*/
 
/*
 
    cout << (ans ? "YES" : "NO") << "\n";
 
*/
 
void solve(int tc)
{
    //global initializations like "vector clear", "sum = 0"
    int m,n,p,q,maxm,minm,u,v,w,ans=0,k;
 
    vector<int>a;
 
    a.clear();
 
    cin>>n>>k;
 
    fo(i,k)
    {
        cin>>p;
        a.pb(p);
    }
 
    for(int i=1;i<(1<<k);i++)
    {
        //q = __builtin_popcount(i);
        //print(q);
        int c = 0,m=1,cc = 0;
        int j = i;
        while(i>0)
        {
            if(i&1)
            {
                if(m>n/a[c])
                {
                    m = n+1;
                    break;
                }
                m *= a[c];
                cc++;
            }
            i/=2;
            c++;
        }
        //print(m);
        q = cc;
        u = n/m;
        if(odd(q))
        {
            ans += u;
        }
        else
        {
            ans -= u;
        }
        i = j;
    }
 
    cout<<ans<<br;
}
 
int32_t main() {
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bool multi = false;
    int t,tc=1;
    if(multi)
    {
        cin>>t;
        while(t--)
        {
            solve(tc);
            tc++;
        }
    }
    else
    {
        solve(tc);
    }
}
 
