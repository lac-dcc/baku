#define MoAdel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+6;
int comp[N];// Says the smallest prime for each number.
void modified_sieve()
{
    iota(comp, comp + N, 0);
    comp[0] = comp[1] = -1;
    for (int i = 2; i <= N / i; i++)
        if (comp[i] == i)
            for (int j = i * i; j <= N; j += i)
                if (comp[j] == j)
                    comp[j] = i;
}
 
vector<int> factorize_log(int n)//get the prime factors of n
{
    vector<int> v;
    while(n > 1)
        v.push_back(comp[n]), n /= comp[n];
    return v;
}
 
vector<pair<int, int>> factorize_log2(int n)//get each prime factor of n and it`s count
{
    vector<pair<int, int>> v;
    while(n > 1)
    {
        int cur = comp[n], cnt = 0;
        while(n % cur == 0)
            n /= cur, cnt++;
        v.emplace_back(cur, cnt);
    }
    return v;
}
 
bool isPrime(ll n){
    if(n==1) return false;
    if(n==2||n==3) return true;
    if(n%2==0||n%3==0) return false;
    for(int i=5;i*i<=n;i=i+6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}
 
int countDigit(ll n) {
    return floor(log10(n) + 1);
}
 
ll lcm (ll a,ll b){
    return (a*b)/__gcd(a,b);
}
 
bool isPower(int x,ll y)
{
    if (x == 1)
        return (y == 1);
    ll pow = 1;
    while (pow < y)
        pow *= x;
    return (pow == y);
}
 
ll log_a_to_base_b(ll a, ll b)
{
    return (a > b - 1)? 1 + log_a_to_base_b(a / b, b): 0;
}
 
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
 
vector<pair<ll, ll>> primeFactors(ll n){//sqrt(n)
    //get prime factors of n
    vector<pair<ll, ll>> fact;
    for(ll i=2; i*i<=n; i++){
        int cnt=0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        if(cnt) fact.push_back({i,cnt});
    }
    if(n>1) fact.push_back({n,1});
    return fact;
}
 
bool vis[N];
vector<int> adj[N];
vector<int> val(N);
int n,m;
int t[2]={1,2};
int ans=1;
 
void dfs(int indx,int team){
    if(vis[indx])return;
    vis[indx]=1;
    val[indx]=t[team%2];
    for(auto &i:adj[indx]){
        if(vis[i]){
            if(val[i]==val[indx])ans=0;
            continue;
        }
        dfs(i,team+1);
    }
}
 
void Dola() {
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //if(m-1>n){cout<<"IMPOSSIBLE"<<endl;return;}
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(ans==0)break;
        dfs(i,1);
    }
    if(ans==0){cout<<"IMPOSSIBLE"<<endl;return;}
    for(int i=1;i<=n;i++)cout<<val[i]<<" ";
    cout<<endl;
}
 
int main(){
    MoAdel
    int t=1;
    //cin>>t;
    while(t--){
        Dola();
    }
    return 0;
}
