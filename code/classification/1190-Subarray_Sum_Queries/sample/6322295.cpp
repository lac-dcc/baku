#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define I_love_you_Liny ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define sync_clock chrono::steady_clock::now().time_since_epoch().count()
#define int long long int
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(),(x).rend()
 
template<typename T> struct split64_hash { inline static uint64_t splitmix64(uint64_t x){
    x = ((x += 0x9e3779b97f4a7c15) ^ ((x += 0x9e3779b97f4a7c15) >> 30)) * 0xbf58476d1ce4e5b9;
    return ((x ^ (x >> 27)) * 0x94d049bb133111eb) ^ (((x ^ (x >> 27)) * 0x94d049bb133111eb) >> 31);
   } inline size_t operator()(uint64_t x) const{static const uint64_t FIX = sync_clock; return splitmix64(x + FIX);}
};
template <typename T,typename V,typename U = int> using u_map = unordered_map<T, V, split64_hash <U>>;
template <typename T> using orset =  tree<T, null_type, less<T>,  rb_tree_tag,   tree_order_statistics_node_update>;
template <typename T, typename V> using ormap = tree<T, V, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> istream& operator>>(istream& is,  vector<T> &a){for (auto &x : a) is >> x;         return is;}
template <typename T> ostream& operator<<(ostream& os,  vector<T>  a){for (auto &x : a) os << x << ' ';  return os;}
template <typename T> ostream& operator<<(ostream& os,  set<T>  s){for (auto &x : s) os << x << ' ';     return os;}
template <typename T> ostream& operator<<(ostream& os,  multiset<T>  s){for (auto &x : s) os << x << ' ';return os;}
template <typename T, typename V> void operator+=(vector<T>& a, const V value) { for(auto &x : a)x += value; }
template <typename T, typename V> void operator-=(vector<T>& a, const V value) { for(auto &x : a)x -= value; }
template <typename T, typename V> void operator*=(vector<T>& a, const V value) { for(auto &x : a)x *= value; }
template <typename T, typename V> void operator/=(vector<T>& a, const V value) { for(auto &x : a)x /= value; }
template <typename T> void operator++(vector<T>& a) { a += 1; }
template <typename T> void operator--(vector<T>& a) { a -= 1; }
 
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int N = 301000;
const int mod = 1000000007;
 
int n,q;
int a[N];
 
struct node{
     int sum,mxl,mxr,mx;
} st[1<<19];
 
const int neutral = 0;
/*
void app(int i,int x,int x2,int l2,int r2){
   st[i].lz1+=x;
   st[i].lz2+=x2;
   st[i].sum+=(r2-l2+1)*x + x2*((r2+1)*r2/2 - (l2-1)*l2/2);
 
}
 
void psh(int i,int l2,int m2,int r2){
    app(2*i,st[i].lz1,st[i].lz2,l2,m2);
    app(2*i+1,st[i].lz1,st[i].lz2,m2+1,r2);
    st[i].lz1 = 0;
    st[i].lz2 = 0;
}
*/
void upd(int l1,int x,int i=1,int l2=0,int r2=n-1){
    if(l2==r2){
        st[i].sum = x;
        st[i].mx = x;
        st[i].mxl = st[i].mxr = x;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1 <=m2) upd(l1,x,2*i,l2,m2);
    else upd(l1,x,2*i+1,m2+1,r2);
    st[i].sum = st[2*i].sum+st[2*i+1].sum;
    st[i].mx = max({st[2*i].mx,st[2*i+1].mx,st[2*i].mxr + st[2*i+1].mxl});
    st[i].mxl = max(st[2*i].mxl,st[2*i].sum + st[2*i+1].mxl);
    st[i].mxr = max(st[2*i+1].mxr,st[2*i+1].sum + st[2*i].mxr);
}
/*
void upd2(int l1,int r1,int x,int w,int i=1,int l2=0,int r2=n-1){
    if(l1<=l2 && r2<=r1){
        app(i,x,w,l2,r2);
        return;
    }
    int m2 = (l2 + r2)/2;
    psh(i,l2,m2,r2);
    if(l1<=m2) upd2(l1,r1,x,w,2*i,l2,m2);
    if(m2<r1) upd2(l1,r1,x,w,2*i+1,m2+1,r2);
    st[i].sum = st[2*i].sum+st[2*i+1].sum;
}
*/
 
int qry(int l1,int r1,int i=1,int l2=0,int r2=n-1){
    if(l1<=l2 && r2<=r1) return st[i].sum;
    int m2 = (l2+r2)/2;
//    psh(i,l2,m2,r2);
    int left = (l1 <= m2) ? qry(l1,r1,2*i,l2,m2):neutral;
    int right = (m2<r1) ? qry(l1,r1,2*i+1,m2+1,r2):neutral;
    return left+right;
}
 
 
void solution(){
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> a[i], upd(i,a[i]);
    while(q--){
        int k,x;
        cin >> k >> x;
        upd(--k,x);
        cout << max(st[1].mx,0LL) << '\n';
    }
}
 
bool multi_test = 0;
 
int32_t main(){
    I_love_you_Liny;
    int T = 1;
    if(multi_test) cin >> T;
    while(T--) solution();
    return 0;
 
}
 
 
