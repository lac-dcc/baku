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
#define FORD(i,a,b) for (int i = b-1; i >= a; i--)
#define trace(...) cout<<"[DEBUG]\n"; __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1){cout << name << ": " << arg1 << endl;}
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << ": " << arg1<<" | "; __f(comma+1, args...);}
typedef long long ll; const double PI=acos(-1); const int MOD = 1000000007; const int MOD2 = 998244353; const double eps = 1e-9; using pii = array<int, 2>; using pll = array<ll, 2>;
template<typename T> using vec = vector<T>; template<typename T> using vvec = vector< vector<T> >; template<typename T> using vvvec = vector< vector< vector<T> > >;
template<typename T> struct comparator { bool operator()(T const& p1, T const& p2) { for(auto a: p1) for(auto b: p2) return a < b; } };
template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){os << "(" << V.first << "," << V.second << ")"; return os;}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){os << "[ "; for(auto itr = V.begin(); itr != V.end(); itr++) os << itr->first << ": " << itr->second << " "; return os << "]\n";}
template<class T> ostream& operator<<(ostream &os, set<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]\n";} template<class T> ostream& operator<<(ostream &os, multiset<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]\n";}
template<class T> ostream& operator<<(ostream &os, vector<T> V){os << "[ "; for(auto v  : V) os << v << " "; return os << "]\n";}
template<typename T, size_t S> ostream& operator<< (ostream& out, const array<T, S>& v) { out << "{"; for(T x: v) cout << v[0] << ","; cout << "}"; return out; }
template<typename T> T gcd(T a, T b) { return(b?__gcd(a,b):a); } ll mul(ll a, ll b, ll c = MOD) { return (a*b)%c; } template<typename T>T power(T e, T n, T m = MOD) { T x=1,p=e; while(n) { if(n&1) { x=mul(x,p,m); } p=mul(p,p,m); n>>=1; } return x; }
template<typename T> void sort(vec<T> &v, int dec=0) { if(dec) sort(v.begin(), v.end(), greater<T>()); else sort(v.begin(), v.end()); }
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
/* Greedy */
 
struct Node {
    long long left, total;
    bool init;
    Node(): left(-1), total(-1), init(false) { }
    Node(long long l, long long t): left(l), total(t), init(true) { }
};
 
ostream& operator<< (ostream& os, Node& node) {
    return os<<"["<<node.init<<"] l: "<<node.left<<" | t: "<<node.total<<"\n";
}
 
class SegmentTree {
    int n;
    vector<Node> tree;
    Node merge(Node n1, Node n2) {
        if(!n1.init)
            return n2;
        if(!n2.init)
            return n1;
        Node res;
        res.left = max(n1.left, n1.total+n2.left); // check if n2.left is negative then don't include it
        res.total = n1.total + n2.total;
        res.init = true;
        return res;
    }
public:
    SegmentTree(vector<long long>& v) {
        int n = v.size();
        int N = (1<<int(ceil(log2(n))));
        this->n = N;
        tree = vector<Node>(2*N);
        REP(i,n) {
            tree[i+N] = Node(max(v[i],0LL), v[i]);
        }
 
        REPD(i,N) {
            tree[i] = merge(tree[2*i], tree[2*i+1]);
        }
    }
 
    void update(int i, long long x) {
        i+=n;
        tree[i] = Node(max(x,0LL), x);
        i/=2;
        while(i) {
            tree[i] = merge(tree[2*i], tree[2*i+1]);
            i/=2;
        }
    }
 
    long long query(int i, int j) {
        Node left, right;
        i += n, j += n;
        while(i<=j) {
            // trace(i, j, left, right);
            if(i&1) left = merge(left, tree[i++]);
            if(!(j&1)) right = merge(tree[j--], right);
            i /= 2;
            j /= 2;
        }
        return merge(left, right).left;
    }
};
 
int main() {
    FAST_IO;
 
    long long n, m, a, b, c;
    cin>>n>>m;
 
    vector<long long> v(n);
    REP(i,n)
        cin>>v[i];
    
    SegmentTree tree(v);
    
    REP(i,m) {
        cin>>c;
        if(c==1) {
            cin>>a>>b;
            a--;
            tree.update(a, b);
        }
        else {
            cin>>a>>b;
            a--, b--;
            cout<<tree.query(a, b)<<"\n";
        }
    }
 
    return 0;
}
