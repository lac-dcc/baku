#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
#define PRECISION(x) cout << fixed << setprecision(x);
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a-1; i >= b; i--)
#define deb1(x) cout << "[DEBUG] " << #x << ": " << x << endl
#define deb2(x,y) cout << "[DEBUG] " << #x << ": " << x << ", " << #y << ": " << y << endl
#define deb3(x,y,z) cout << "[DEBUG] " << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl
#define deb4(x,y,z,p) cout << "[DEBUG] " << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << ", " << #p << ": " << p << endl
typedef long long ll; const double PI=acos(-1); const int MOD = 1000000007; const int MOD2 = 998244353; const double eps = 1e-9; using pii = array<int, 2>; using pll = array<ll, 2>;
template<typename T> using vec = vector<T>; template<typename T> using vvec = vector< vector<T> >; template<typename T> using vvvec = vector< vector< vector<T> > >;
template<typename T> struct comparator { bool operator()(T const& p1, T const& p2) { for(auto a: p1) for(auto b: p2) return a < b; } };
template<typename T> ostream& operator<< (ostream& out, const array<T, 2>& v) { out << "{" << v[0] << "," << v[1] << "}"; return out; } template<typename T> ostream& operator<< (ostream& out, const array<T, 3>& v) { out << "{" << v[0] << "," << v[1] << "," << v[2] << "}"; return out; } template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){return os << "(" << V.first << "," << V.second << ")";}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){os << "[ "; for(auto v  : V) os << "(" << v.first << ":" << v.second << ")"; return os << "]\n";}
template<class T> ostream& operator<<(ostream &os, set<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]\n";} template<class T> ostream& operator<<(ostream &os, multiset<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]\n";}
template<class T> ostream& operator<<(ostream &os, vector<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]\n";}
template<typename T> T gcd(T a, T b) { return(b?__gcd(a,b):a); }
ll mul(ll a, ll b, ll c = MOD) { return (a*b)%c; }
template<typename T>T power(T e, T n, T m = MOD) { T x=1,p=e; while(n) { if(n&1) { x=mul(x,p,m); } p=mul(p,p,m); n>>=1; } return x; }
template<typename T>T max(vec<T> &v) { return *max_element(v.begin(), v.end()); } template<typename T>T min(vec<T> &v) { return *min_element(v.begin(), v.end()); }
template<typename T, size_t S> ostream& operator<< (ostream& out, const array<T, S>& v) { out << "{"; for(T x: v) cout << v[0] << ","; cout << "}"; return out; }
template<typename T> void sort(vec<T> &v, int dec=0) { if(dec) sort(v.begin(), v.end(), greater<T>()); else sort(v.begin(), v.end()); }
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
/* Segment Tree */
 
struct node
{
    ll left;
    ll right;
    ll full;
    ll ans;
 
    node(): left(0), right(0), full(0), ans(0) {}
    node(int l, int r, int f, int a): left(l), right(r), full(f), ans(a) {}
 
    struct node operator+(struct node &n)
    {
        struct node res;
 
        res.left = max(left, full+n.left);
        res.right = max(n.right, n.full+right);
        res.full = full + n.full;
        res.ans = max({ans, n.ans, right+n.left});
 
        return res;
    }
};
 
ostream& operator<<(ostream &os, struct node &n)
{
    os << "{ " << n.left << "," << n.right << "," << n.full << "," << n.ans << " }\n";
    return os;
}
 
class SegmentTree
{
    int n;
    vec<struct node> tree;
    struct node merge(struct node n1, struct node n2)
    {
        return n1 + n2;
    }
 
public:
    SegmentTree(vec<int> v)
    {
        n = (1<<int(ceil(log2(v.size()))));
        tree = vec<struct node>(2*n);
 
        REP(i,v.size())
            tree[i+n] = node(v[i],v[i],v[i],v[i]);
 
        REPD(i,n)
            tree[i] = merge(tree[2*i], tree[2*i+1]);
 
        // deb1(tree);
    }
 
    ll updateIndex(int k, int val)
    {
        k += n;
        tree[k] = node(val,val,val,val);
        k/=2;
        while(k)
        {
            tree[k] = merge(tree[2*k], tree[2*k+1]);
            k/=2;
        }
 
        // deb1(tree);
 
        return max({tree[1].ans,0ll});
    }
 
    ll queryRange(int i, int j)
    {
        i += n;
        j += n;
        struct node ans;
        while(i<=j)
        {
            if(i%2==1) ans = merge(ans, tree[i++]);
            if(j%2==0) ans = merge(ans, tree[j--]);
            i/=2;
            j/=2;
        }
        return ans.ans;
    }
};
 
int main()
{
    FAST_IO;
 
    int n, m, k, a;
    cin>>n>>m;
 
    vec<int> v(n);
    REP(i,n)
        cin>>v[i];
    
    SegmentTree tree(v);
    
    REP(i,m)
    {
        cin>>k>>a;
        k--;
 
        cout<<tree.updateIndex(k, a)<<"\n";
    }
 
    return 0;
}
