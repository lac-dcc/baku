#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define INF (int)1e18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define int long long
#define sort_BT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define rep(i,s,e) for(int i = s; i<e; i++)
#define test(t) int t;cin>>t;while(t--)
#define rrep(i,s,e) for(int i = s;i>=e;i--)
#define yes "YES"
#define no "NO" 
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;
 
 
int binpow(int a, int b, int m = MOD) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.second==b.second){
        return a.first<b.first;
    }
    return (a.second < b.second);
} 
bool isPrime(int n) {
 
  if (n == 1) {
    return false;
  }
   
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
 
  return true;
}
 
bool compare_float(float x, float y, float epsilon = 0.01f){
   if(fabs(x - y) < epsilon)
      return true;
      return false; 
}
 
int n;
vi a;
vector<pii> seg;
 
pii combine(pii p1,pii p2){
    return {p1.first+p2.first,max(p1.second,p1.first+p2.second)};
}
 
void build(int id = 1,int l = 0,int r = n){
    if(r-l==1){
        seg[id].first = a[l];
        seg[id].second = max(a[l],0ll);
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid,r);
    seg[id] = combine(seg[id*2],seg[id*2+1]);
}
 
pii query(int x,int y,int id = 1,int l = 0,int r = n){
    if(l>=y || r<=x){
        return {0,0};
    }
    if(l>=x && r<=y){
        return seg[id];
    }
    int mid =  l+ (r-l)/2;
    return combine(query(x,y,2*id,l,mid),query(x,y,2*id+1,mid,r));
} 
 
void modify(int pos,int val,int id = 1,int l =0,int r = n){
    
    if(r-l==1){
        seg[id].first = val;
        seg[id].second = max(val,0ll);
        a[l] = val;
        return ;
    }
    int mid = (l+r)/2;
    if(pos>=mid){
        modify(pos,val,2*id+1,mid,r);
    }
    else{
        modify(pos,val,2*id,l,mid);
    }
    seg[id] = combine(seg[2*id],seg[2*id+1]);
}
 
int32_t main(){
 
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    sort_BT
 
    int q;
    cin >> n >> q;
    seg.resize(4*n+1);
    a.resize(n);
    rep(i,0,n){
        cin >> a[i];
    }
    build();
    while (q--)
    {
        int c;
        cin >> c;
        if(c==1){
            int k,u;
            cin >> k >> u;
            modify(k-1,u);
        }
        else{
            int a1,a2;
            cin >> a1 >> a2;
            cout << query(a1-1,a2).second<<'\n';
        }
        
    }
    
}
