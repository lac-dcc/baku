#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long double ld;
typedef vector<double> vd;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set<int> si;
typedef set<ll> sl;
 
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define fr(i,a,n) for( int i=a;i<n;i++)
#define frev(i,a,n) for( int i=a;i>=n;i--)
#define inp(ve) for(int i=0;i<ve.size();i++) cin>>ve[i];
#define PB push_back
#define F first
#define S second
#define cont continue
#define br break
#define MP make_pair
#define nl cout<<"\n"
#define M 1000000007
 
const ll INF = 1e17;
const ll NINF = -1e17;
 
int lindieq (int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = lindieq(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
ll gcd (ll c, ll d) {
    ll a = max(c,d);
    ll b = min(c,d);
    while (b) {
        a %= b;
        ll temp = a;
        a=b;
        b=temp;
    }
    return a;
}
 
ll bexp(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b%2) res = res*a;
        a*=a;
        b/=2;
    }
    return res;
}
 
vb isprime(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
 
ll bexpm(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b%2) res = (res*a)%M;
        a = (a*a)%M;
        b/=2;
    }
    return res;
}
 
vi num;
vvi adj;
 
void dfs(int v){
    for(int i : adj[v]){
       dfs(i);
       num[v]+=num[i]+1;
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        num.assign(n+1,0);
        adj.resize(n+1);
        int a;
        fr(i,2,n+1){
            cin>>a;
            adj[a].push_back(i);
        }
        dfs(1);
        fr(i,1,n+1){
            cout<<num[i]<<" ";
        }
    }
    return 0;
}
