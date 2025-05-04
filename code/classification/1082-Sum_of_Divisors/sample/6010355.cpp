// back to old days lads!!
// 3 problems and thats it
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define fr(i,a,b) for(int i = a; i <= b; i++)
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll mod=1e9+7;
ld pi=3.14159265359;
ld eps=0.000000001;
ll c_xor(ll a,ll b){
 
    return (a^b);
}
ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
vector<vector<int>>prime_factorization(int n){
    vector<vector<int>>ans;
    for(int i=2;i*i<=n;i++){
            int co=0;
        if(n%i==0){
            while(n%i==0){
                co++;
                n/=i;
            }
        }
        else{continue;}
        ans.pb({i,co});
    }
    if(n!=1){
        ans.pb({n,1});
    }
    return ans;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    res%=mod;
    if (b % 2)
        return (((res*res)%mod)*a)%mod;
    else
        return (res * res)%mod;
}
ll divide(ll a,ll b)
{
    return (a%mod)*binpow(b,mod-2)%mod;
}
 
ll fact[2000000+1];
 
ll fast_mod_exp(ll a, ll b, ll m) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % m;
 
		a = (a * a) % m;
		b = b >> 1;
	}
 
	return res;
}
 
ll mod_inverse(ll a, ll m) {
	// m is prime
	return fast_mod_exp(a, m - 2, m);
}
 
ll ncr(ll n, ll r) {
	if (r == 0)
		return 1;
 
	// ll ans = 1;
	// for (ll i = 0; i <= r - 1; i++) {
	// 	ans = (ans * (n - i)) % p;
	// }
 
	return ((fact[n] * mod_inverse(fact[n - r], mod)) % mod * mod_inverse(fact[r], mod)) % mod;
}
string decimalToBinary(ll n)
{
    //finding the binary form of the number and
    //converting it to string.
    string s = bitset<9> (n).to_string();
    return s;
 
    //Finding the first occurrence of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');
 
    if(loc1 != string::npos)
        return s.substr(loc1);
 
    return "0";
}
 
vector<int>sv(int n)
{
 
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
vector<int>prime;
for(int i=1;i<=n;i++){
    if(is_prime[i]){prime.pb(i);}
}
return prime;
}
 
const int  N=3e6+2;
ll a[N],tree[4*N];
ll fn(ll n1,ll n2){return 0;}
void build(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    // the main part--->
    tree[node]=fn(tree[2*node],tree[2*node+1]);
 
}
ll query(int node,int st,int en,int left,int right){
    if(en<left||right<st){return       0;}
    if(left<=st&&en<=right){return tree[node];}
    // the main part----->
    int mid=(st+en)/2;
 
    return (query(2*node,st,mid,left,right)+query(2*node+1,mid+1,en,left,right));
 
}
void update(int node,int st,int en,int idx,ll val){
    if(st==en){
        a[st]=val;
        tree[node]=val;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
 
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
    }
    // main part----->
    tree[node]=(tree[2*node]+tree[2*node+1]);
}
 
 
 
 
 
ll cross(ll n1,ll n2)
{
    return ( (n1%mod)*(n2%mod) )%mod;
}
 
 
int parent[1000000+1];
void make_dsu(int n) {
    for(int i=1;i<=n;i++){parent[i]=i;}
}
 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
 
 
 
 
ll gsum(ll n1,ll n2)
{
    ll res=cross(n2,n2)+n2-cross(n1,n1)+n1;
    if(res<0){res+=mod;}
    return res%mod;
}
 
 
void f()
{
 
    ll n;cin>>n;
    ll i=n;
    ll sum=0;
    while(i>=1)
    {
        ll t1=(n/i);
        ll t2=(n/(t1+1));
    //    cout<<t2<<"\n";
        sum+=((t1%mod)*gsum(t2+1,i))%mod;
        sum%=mod;
        i=t2;
    }
    sum=divide(sum,2);
    cout<<sum<<"\n";
 
 
}
 
 
/// for some segment to be included we check
 
int main() {
 
 
 
 
   fast_io;
   fact[0] = fact[1] = 1;
	for (ll i = 1; i <= 2000000; i++) {
		fact[i] = (fact[i - 1] * i ) % mod;
	}
 
 
	int  t=1;
	while(t--)
    {
 
        f();
        cout<<"\n";
 
 
    }
 
 
//    int t;cin>>t;
//	for(int i=1;i<=t;i++){
//        cout<<"Case #"<<i<<": ";
//        f();
//        cout<<"\n";
//	}
 
 
 
 
 
 
 
}
 
 