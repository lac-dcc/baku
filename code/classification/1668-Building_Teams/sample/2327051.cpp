// AUTHOR:- Saumya Rangani
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<pair<int,int>>
#define fr first
#define sc second
#define all(c) c.begin(), c.end()
#define it(a) for(auto &i:a)
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define read(v) for(auto &i:v)cin>>i;
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define in cin>>
#define out cout<<
#define default(a,n,b) for(int i=0;i<n;i++)a[i]=b;
#define YNans(poss) cout << (poss ? "YES" : "NO" ) << endl;
#define inarray(a,n) for(int i=0;i<n;i++)cin>>a[i];
#define fast ios_base :: sync_with_stdio(false),cin.tie(NULL);
#define MAXN 100005
 
 
int gcd(int a, int b){return (b?gcd(b,a%b):a);}
bool isPrime(int n){if(n==1) return false;if(n==2) return true;for(int i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}
int power(long long x, unsigned int y, int p=mod){int res = 1;x = x % p; if (x == 0) return 0;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1;x = (x*x) % p;}return res;}
int digit(int n){int ans=0;while(n){ans++;n/=10;}return ans;}
int lcm(int a,int b){return a*b/gcd(a,b);}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
 
vector<vi> grp(MAXN);
vi col(MAXN,-1);
 
bool bfs(int node){
    queue<int> q;
    q.push(node);
    col[node]=1;
    while(!q.empty()){
        auto pp=q.front();
        q.pop();
        for(auto i:grp[pp]){
            if(col[i]==-1){
                col[i]=3-col[pp];
                q.push(i);
            }
            if(col[i]!=3-col[pp])return 0;
        }
    }
    return 1;
}
 
void solve(){
    int n;in n;int m;in m;
    for(int i=0;i<m;i++){
        int x,y;in x>>y;
        grp[x].pb(y),grp[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            if(!bfs(i)){
                cout<<"IMPOSSIBLE"<<endl;return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<col[i]<<" ";
    }
    cout<<endl;
}
 
int32_t main(){
    fast
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
