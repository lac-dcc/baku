#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define inf 1000000007
#define llmax LLONG_MAX
#define pi 3.141592653589793238462643383279502884197169399
 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll ncr(int n, int r)
{
    if (n < r) return 0;
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
 
vector <ll> vcreate(int n){
    vector <ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    return v;
}
const int N = 100007;
vector<int> v[N];
vector<bool> visited(N, false);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
 
    ll n, m; cin>>n>>m;
    queue <int> q;
    for(int i = 0; i<m; i++)
    {
        int x, y; cin>>x>>y;
        v[y].push_back(x);
        v[x].push_back(y);
    }
    q.push(1);
    vector<int> dis(n+1, inf);
    dis[1]=1;
    vector<int> pred(n+1);
    pred[1]=0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        visited[x]=true;
        for(auto i : v[x])
        {   
            if(!visited[i])
            {
               
                if( dis[i]>dis[x]+1)
                {
                    dis[i]=dis[x]+1;
                    pred[i]=x;
                     q.push(i);
                }
            }
        }
    }
    if(dis[n]==inf) cout<<"IMPOSSIBLE";
    else
    {
        cout<<dis[n]<<'\n';
        int u = n;
        int k = dis[n];
        vector<int> ans(k+1);
        for(int i = k;i>0;i--)
        {
            ans[i] = u;
            u = pred[u];
        }
        for(int i = 1;i<=k;i++) cout<<ans[i]<<" ";
    }
 
}
