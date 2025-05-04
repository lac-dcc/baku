/*    Immediate gratification is a dream killer   */
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void make_unique(vector<T>& vec) {
  sort(vec.begin(),vec.end());
  vec.erase(unique(vec.begin(),vec.end()), vec.end());
}
void __print(long long x) {cerr << x;}
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
#define ll long long
#define ld long double
#define endl '\n'
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,n) for(i=1;i<=n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end() 
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(i, begin, end) for(i=begin;i<=end;i++)
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
bool isprime(ll n){ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    return true; 
}
const ll mod = 1000000007;
const ld PI = 3.141592653589793;
const ll inf = 1e15;
const int cons=100001;
ll N,M;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll n=0,m=0,i=0,j=0,k=0,cnt=0,ans=0,sum=0,flag=0,pos=0,ind=0,mn=0,mx=0,res=0;
    cin>>n>>m>>k;
    vl v(n);
    multiset<ll> s;
    fo(i,n){
        cin>>v[i];
        v[i]-=k;
    }
    fo(i,m){
        cin>>j;
        s.insert(j);
    }
    sort(all(v));
    fo(i,n){
        if(s.lower_bound(v[i])!=s.end())
        {
            ll x=*(s.lower_bound(v[i]));
            if(abs(x-v[i])<=2*k){
                cnt++;
                s.erase(s.lower_bound(v[i]));
            }
        }
    }
    cout<<cnt<<endl;
 
    return 0;
}
